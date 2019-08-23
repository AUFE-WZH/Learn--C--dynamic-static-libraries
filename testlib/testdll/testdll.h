#ifndef TESTDLL_H
#define TESTDLL_H
//防止头文件重复包含


//__declspec(dllexport)为导出接口在头文件中使用
//__declspec(dllimport)为导入接口供用户使用
#ifdef _DLLAPI
	#define DLLAPI __declspec(dllexport)
#else 
	#define DLLAPI __declspec(dllimport)
#endif

//加减乘除
//导出方式使用C语言方式，C++方式会使得函数名发生改变（extern "C"）
extern "C" DLLAPI int testdll_add(int, int);

/*
LIBRARY testdll
EXPORTS 
testdll_add
*/

#endif