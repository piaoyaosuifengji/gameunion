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



struct  taskMsg   tasksp[] = {

		//{ TaskId_Mainline_0, 0, Shell_Hangle,1 },				//��������
		{ TaskId_Mainline_1, 0, Shell_Hangle,1},				//��������--������Ϸ
		{ TaskId_Mainline_2, 0, Shell_Hangle, 2 },				//��������--��ȡ��һ������



};

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















