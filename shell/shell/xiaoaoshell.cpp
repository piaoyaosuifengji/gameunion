#include "StdAfx.h"
#include "xiaoaoshell.h"
#include "fileoperating.h"
#include "operating.h"
xiaoaoshell::xiaoaoshell(void)
{
}


xiaoaoshell::~xiaoaoshell(void)
{
}

DWORD WINAPI autoAttack(PVOID pvParam)
{
	//��ȡshell�ı�
	CString fileName("autoAttack.txt");
	int count=lineCount( fileName);
	struct operat *p=new struct operat[count];
	int countINFact=ReadTxtToGetShellByName2(fileName,count,p);
	//��������
	//���ǵó���ִ�еĲ������Լ���Ӧ�Ĳ���
	struct dodo *todo=new struct dodo[countINFact];
	int res=haveToDo( countINFact, p,  todo);
	//��������
	if(res <=0)
	{
		CString  zuobiao1(_T("some wrong"));
		AfxMessageBox(zuobiao1);
		//int res=runShell( countINFact, todo);

	}


	Sleep(4000);
	char c;
	int delyTime;
	int continueAutoAttack=1;
	while(continueAutoAttack)
	{

		//ѡ��
		c='e';
		delyTime=500;
		ToInPutChar( c, delyTime);
		//2�������ͷ�-
		res=runShell( countINFact, todo);







	}
	delete[] p;
	delete[] todo;
	return 0;
}
