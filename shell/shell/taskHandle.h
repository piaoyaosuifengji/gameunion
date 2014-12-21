#pragma once
class taskHandle
{
public:
	taskHandle();
	~taskHandle();
};




//zai在批量处理和操作一些任务时候，为了判断
//如何去处理这么函数，定义一个任务结构，根据这个
//结构来判断去哪里调用相关函数

#define Shell_Hangle			1
#define Func_Hangle				2

struct  taskMsg
{
	int taskID;//gei给每一个任务都预定义一个ID
	//int subTaskID;//每一个任务可能有子任务，也有ID
	int flag1;//记录一些状态
	int fucPos;//给定实现这个任务的函数位置，有的任务有任务shell，有的任务有相应的函数
				//fucPos 为Shell_Hangle表示有对应的taskShell		读取那个shell来实现
				//fucPos 为Func_Hangle表示有对应的task  function，调用相应函数
	int fucID;//任务处理函数/shell 的编号
};



//定义一个Hangle的过程：
//	1：在shellResolve中定义任务ID宏
//	2：  tasksp[]中给定taskMsg结构
//	3：添加Shell_Hangle    Func_Hangle








int TaskId_Mainline_Hangdle_fuc(int  process);//参数为已经完成进度，这里就是子任务的id
void SignInTaskFuc();