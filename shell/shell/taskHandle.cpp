#include "stdafx.h"
#include "taskHandle.h"
#include <afxmt.h>
#include "fileoperating.h"
#include "operating.h"
#include "xiaoaoshell.h"

taskHandle::taskHandle()
{
}


taskHandle::~taskHandle()
{
}


//#define TaskShellStCreate(id)    ()



struct  taskMsg   tasksp[] = {

		//{ TaskId_Mainline_0, 0, Shell_Hangle,1 },				//��������
		{( TaskId_Mainline_1, 0, Shell_Hangle,1)},				//��������--������Ϸ
		{ TaskId_Mainline_2, 0, Shell_Hangle, 2 },				//��������--��ȡ��һ������
		{ TaskId_Mainline_3, 0, Shell_Hangle, 3 },				//��������--��ȡ��һ������
		{ TaskId_Mainline_4, 0, Shell_Hangle, 4 },				
		{ TaskId_Mainline_5, 0, Shell_Hangle, 5 },
		{ TaskId_Mainline_6, 0, Shell_Hangle, 6 },
		{ TaskId_Mainline_7, 0, Shell_Hangle, 7},
		{ TaskId_Mainline_8, 0, Shell_Hangle, 8 },
		{ TaskId_Mainline_9, 0, Shell_Hangle, 9 },
		{ TaskId_Mainline_10, 0, Shell_Hangle, 10 },
		{ TaskId_Mainline_11, 0, Shell_Hangle, 11 },
		{ TaskId_Mainline_12, 0, Shell_Hangle, 12 },
		{ TaskId_Mainline_13, 0, Shell_Hangle, 13 },
		{ TaskId_Mainline_14, 0, Shell_Hangle, 14 },
		{ TaskId_Mainline_15, 0, Shell_Hangle, 15 },
		{ TaskId_Mainline_16, 0, Shell_Hangle, 16 },
		{ TaskId_Mainline_17, 0, Shell_Hangle, 17 },
		{ TaskId_Mainline_18, 0, Shell_Hangle, 18 },
		{ TaskId_Mainline_19, 0, Shell_Hangle, 19 },
		/*		{ TaskId_Mainline_11, 0, Shell_Hangle, 11 },
		{ TaskId_Mainline_11, 0, Shell_Hangle, 11 },
		{ TaskId_Mainline_11, 0, Shell_Hangle, 11 },
		{ TaskId_Mainline_11, 0, Shell_Hangle, 11 },
		{ TaskId_Mainline_11, 0, Shell_Hangle, 11 },
		{ TaskId_Mainline_11, 0, Shell_Hangle, 11 },
		{ TaskId_Mainline_11, 0, Shell_Hangle, 11 },
		{ TaskId_Mainline_11, 0, Shell_Hangle, 11 }, */
};
void SignInTaskFuc()
{

	CString str;
	//CString tmp(1);
	str.Format(_T("D:\\data\\shell\\signINShell.pl")); 
	readAndRunShell(str);




}
//����Ϊ�Ѿ���ɽ��ȣ���������������id����ӽ�����Ϸ��ʼ����process=TaskId_Mainline_1
int TaskId_Mainline_Hangdle_fuc(int  process)
{


	if (process < TaskId_Mainline_0)
		return -1;
	int taskNum = sizeof(tasksp) / sizeof(struct  taskMsg);
	int i = 0;
	//�Ҹ������Ƿ��ж�Ӧʵ�ֺ����ķ�����
	//	�������������������Ҹ����������ṹ

	while ( 1)
	{ 
		for (i = 0; i < taskNum; i++)
		{
			if (process == tasksp[i].taskID)
			{
				//�ҵ���ʵ�ֺ�����ʵ��֮
				if (tasksp[i].fucPos == Shell_Hangle)
				{
					CString str;
					//CString tmp(1);
					str.Format(_T("D:\\data\\1440900\\shell\\%d.pl"), tasksp[i].fucID);;
					readAndRunShell(str);
					i = 0;
					process++;
				}
				else if (tasksp[i].fucPos == Func_Hangle)
				{

					i = 0;
					process++;
				}
				else
					return -3;

			}

		}


		if (i >= taskNum)//����
		{

			return 0;

		}

		
	}

	return 0;
}















