#ifndef TESTDLL_H
#define TESTDLL_H
//��ֹͷ�ļ��ظ�����


//__declspec(dllexport)Ϊ�����ӿ���ͷ�ļ���ʹ��
//__declspec(dllimport)Ϊ����ӿڹ��û�ʹ��
#ifdef _DLLAPI
	#define DLLAPI __declspec(dllexport)
#else 
	#define DLLAPI __declspec(dllimport)
#endif

//�Ӽ��˳�
//������ʽʹ��C���Է�ʽ��C++��ʽ��ʹ�ú����������ı䣨extern "C"��
extern "C" DLLAPI int testdll_add(int, int);

/*
LIBRARY testdll
EXPORTS 
testdll_add
*/

#endif