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

		//{ TaskId_Mainline_0, 0, Shell_Hangle,1 },				//主线任务
		{ TaskId_Mainline_1, 0, Shell_Hangle,1},				//主线任务--进入游戏
		{ TaskId_Mainline_2, 0, Shell_Hangle, 2 },				//主线任务--接取第一个任务



};

//参数为已经完成进度，这里就是子任务的id，如从进入游戏开始就是process=TaskId_Mainline_1
int TaskId_Mainline_Hangdle_fuc(int  process)
{


	if (process < TaskId_Mainline_0)
		return -1;
	int taskNum = sizeof(tasksp) / sizeof(struct  taskMsg);
	int i = 0;
	//找该任务是否有对应实现函数的方法：
	//	首先在任务数组里面找该任务的任务结构

	while ( 1)
	{ 
		for (i = 0; i < taskNum; i++)
		{
			if (process == tasksp[i].taskID)
			{
				//找到有实现函数，实现之
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


		if (i >= taskNum)//结束
		{

			return 0;

		}

		
	}

	return 0;
}















