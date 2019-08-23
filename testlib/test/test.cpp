#include <stdio.h>
//��̬������
#include "../testlib/testlib.h"
#pragma comment(lib,"testlib.lib")
//��̬������
#include "../testdll/testdll.h"
//#pragma comment(lib,"testdll.lib") //�˴���.lib�����Ǿ�̬����Ƕ�̬�����ɵ��ļ�������ʽ���ö�̬��
#include<Windows.h>

//��̬������
#include "../testdll2/testdll2.h"

//���庯��ָ��
typedef int(*DLLADD) (int, int);
typedef int(*DLLADD2) (int, int);

int main()
{
	printf("����������������\n");
	int a, b;
	scanf("%d %d", &a, &b);

	//���þ�̬��
	printf("���þ�̬�⣺testlib_add(a, b)=%d\n", testlib_add(a, b));


	//��ʽ���ö�̬��
	//printf("��ʽ���ö�̬�⣺testdll_add(a, b)=%d\n", testdll_add(a, b));

	//��ʾ���ö�̬�⣬��Ҫ��ʱ��ʹ�ò���Ҫ��ʱ�����ж��
	//����һ��dll�ļ�
	HMODULE hDLL = LoadLibrary(L"../Debug/testdll.dll");
	if (hDLL == NULL)
	{
		printf("����DLL�ļ�ʧ�ܡ�\n");
		return 0;
	}
		
	//��ȡ����ָ��
	DLLADD dlladd = (DLLADD)GetProcAddress(hDLL, "testdll_add");

	//��̬���ö�̬��
	printf("��ʾ���ö�̬�⣺dlladd(a, b)=%d\n", dlladd(a, b));

	//ж�ض�̬��
	FreeLibrary(hDLL);

	//����һ��dll�ļ�
	HMODULE hDLL2 = LoadLibrary(L"../Debug/testdll2.dll");
	if (hDLL2 == NULL)
	{
		printf("����DLL�ļ�ʧ�ܡ�\n");
		return 0;
	}

	//��ȡ����ָ��
	DLLADD2 dlladd2 = (DLLADD2)GetProcAddress(hDLL2, "testdll2_add");

	//��̬���ö�̬��
	printf("��ʾ���ö�̬�⣺dlladd2(a, b)=%d\n", dlladd2(a, b));

	//ж�ض�̬��
	FreeLibrary(hDLL2);

	return 0;
}