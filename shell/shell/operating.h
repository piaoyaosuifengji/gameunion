

#include "StdAfx.h"



//zheli这里定义几个有关显示器分辨率的宏

#define for1440and900  _T("1440900")
#define for1280and800  _T("1280800")



/*
所有的操作类型：



funcParameter1----------void sendALeftMuoseClick(int X,int Y ,int delyTime); ----------
funcParameter2----------void ToInPutChar(char c,int delyTime);
funcParameter3----------void PutKeyDown(char c,int delyTime);
funcParameter4----------void ToInPutKeyboardKey(int c,int delyTime);
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
//funcID=3
struct funcParameter3//for void ToInPutChar(char c,int delyTime);
{
	char c;int delyTime;
};
//funcID=4
struct funcParameter4//for void ToInPutChar(char c,int delyTime);
{
	int c;int delyTime;
};
//该结构体中的没一个成员表示一个特定函数的参数列表
union funcParameter
	{
		struct funcParameter1 p1;
		struct funcParameter2 p2;
		struct funcParameter3 p3;
		struct funcParameter4 p4;
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


struct AttackType
{

	int type;
};

void sendALeftMuoseClick(int X,int Y ,int delyTime);  //参数为click的位置，及点击后延迟多少秒
void ToInPutChar(char c,int delyTime);
int haveToDo(int countINFact,struct operat *p,struct dodo * todo);
int runShell(int countINFact,struct dodo *todo);
void PutKeyDown(char c,int delyTime);
void GetCurrentRGB(CPoint pt);
void GetPointRGB(CPoint *pt,struct colourRGB * obColour);
void  standardOutput(CString str);
void ToInPutKeyboardKey(int c,int delyTime);
///////////////////////////RGB//////////////////////////////////
//讲a，b值相加后赋给a
int addRGB(struct colourRGB *a,struct colourRGB *b);
//初始化一个rgb
 int initRGB(struct colourRGB *a);
 ///////////////////////////RGB//////////////////////////////////
 struct colourRGB  	CalculateAverageValueRBG(CPoint start,CPoint end,int Thickness);
 int getMsgForFindMatrix(CString file,CPoint *startPoint,struct colourRGB * AverageValueRBG);
int FindMatrix(CPoint startPoint,struct colourRGB obColour,CPoint *LeftPoint,CPoint *RightPoint);