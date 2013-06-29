

#include "StdAfx.h"









/*
所有的操作类型：



funcParameter1----------void sendALeftMuoseClick(int X,int Y ,int delyTime); ----------
funcParameter2----------void ToInPutChar(char c,int delyTime);


*/
//funcID=1
struct funcParameter1//for void sendALeftMuoseClick(int X,int Y ,int delyTime);
{
	int X;int Y ;int delyTime;
};
//funcID=2
struct funcParameter2//for void ToInPutChar(char c,int delyTime);
{
	char c;int delyTime;
};

//该结构体中的没一个成员表示一个特定函数的参数列表
union funcParameter
	{
		struct funcParameter1 p1;
		struct funcParameter2 p2;

	};


//所有的操作最终都将映射的某一个特定的函数中去，那么如果你要在一个集合中表示出所有这些函数
//你该怎么做呢,用这样一个结构体来表达：
//讲所有的函数进行编号funcID，一个特定的操作所需要的函数又唯一的id
//而一个union funcParameter paramet;来保存对应的参数

struct dodo
{

	int funcID;
	union funcParameter paramet;

};




void sendALeftMuoseClick(int X,int Y ,int delyTime);  //参数为click的位置，及点击后延迟多少秒
void ToInPutChar(char c,int delyTime);
int haveToDo(int countINFact,struct operat *p,struct dodo * todo);
int runShell(int countINFact,struct dodo *todo);