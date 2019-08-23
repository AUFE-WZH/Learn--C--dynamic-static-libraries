#include <stdio.h>
//静态库引入
#include "../testlib/testlib.h"
#pragma comment(lib,"testlib.lib")
//动态库引入
#include "../testdll/testdll.h"
//#pragma comment(lib,"testdll.lib") //此处的.lib并不是静态库而是动态库生成的文件用来隐式调用动态库
#include<Windows.h>

//动态库引入
#include "../testdll2/testdll2.h"

//定义函数指针
typedef int(*DLLADD) (int, int);
typedef int(*DLLADD2) (int, int);

int main()
{
	printf("请输入两个整数：\n");
	int a, b;
	scanf("%d %d", &a, &b);

	//调用静态库
	printf("调用静态库：testlib_add(a, b)=%d\n", testlib_add(a, b));


	//隐式调用动态库
	//printf("隐式调用动态库：testdll_add(a, b)=%d\n", testdll_add(a, b));

	//显示调用动态库，需要的时候使用不需要的时候可以卸载
	//加载一下dll文件
	HMODULE hDLL = LoadLibrary(L"../Debug/testdll.dll");
	if (hDLL == NULL)
	{
		printf("加载DLL文件失败。\n");
		return 0;
	}
		
	//获取函数指针
	DLLADD dlladd = (DLLADD)GetProcAddress(hDLL, "testdll_add");

	//动态调用动态库
	printf("显示调用动态库：dlladd(a, b)=%d\n", dlladd(a, b));

	//卸载动态库
	FreeLibrary(hDLL);

	//加载一下dll文件
	HMODULE hDLL2 = LoadLibrary(L"../Debug/testdll2.dll");
	if (hDLL2 == NULL)
	{
		printf("加载DLL文件失败。\n");
		return 0;
	}

	//获取函数指针
	DLLADD2 dlladd2 = (DLLADD2)GetProcAddress(hDLL2, "testdll2_add");

	//动态调用动态库
	printf("显示调用动态库：dlladd2(a, b)=%d\n", dlladd2(a, b));

	//卸载动态库
	FreeLibrary(hDLL2);

	return 0;
}