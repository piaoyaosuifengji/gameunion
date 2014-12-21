

#include "StdAfx.h"
#include <afxmt.h>


//zheli这里定义几个有关显示器分辨率的宏

#define for1440and900  _T("1440900")
#define for1280and800  _T("1280800")



/*

脚本使用说明：（shellResolve.h）
char:1000:1:0
结构：命令类型：时间：参数个数：参数


脚本解析流程：
	1：读取脚本，并将脚本解析成对面函数命令所需结构struct operat    	ReadTxtToGetShellByName2（）
	2：将struct operat  转化成最终需要的参数格式 struct dodo            haveToDo( countINFact, p,  todo);
	2：调用函数运行命令													runShell（）

倒过来，要定义一个新操作的流程为：
	1：定义操作声明宏：shellResolve.h，，定义操作类型funcParameter？  结构  以及对应的funcID   ，
	2：将funcParameter？  加入联合体union funcParameter
	3：定义 对应实现的操作函数
	4：将新的判断加入函数（haveToDo  ， runShell  这俩个函数）


所有的操作类型：
																							脚本中对面的命令声明
	funcParameter1----------void sendALeftMuoseClick(int X,int Y ,int delyTime); ---------- LeftMouse
	funcParameter2----------void ToInPutChar(char c,int delyTime);							char
	funcParameter3----------void PutKeyDown(char c,int delyTime);							KeyDown
	funcParameter4----------void locationToMapPos(int mapNameID,int x,int y,int delyTime);	location
	funcParameter5----------void ToInPutKeyboardKey(int X,int Y ,int delyTime);	location	keyboardkey
	funcParameter6----------void sendRightMuoseClick(int X,int Y ,int delyTime);			RightMouse
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
struct funcParameter3//for void PutKeyDown(char c,int delyTime);
{
	char c;int delyTime;
};
//funcID=4
struct funcParameter4  //for void locationToMapPos()    mapNameID是指定地图的ID号
{
	int mapNameID; int X; int Y; int delyTime;
};
//funcID=5
struct funcParameter5  //for void ToInPutKeyboardKey()    
{
	char c; int delyTime;
};
//funcID=6
struct funcParameter6  //for void sendRightMuoseClick(int X,int Y ,int delyTime);
{
	int X; int Y; int delyTime;
};

//该结构体中的没一个成员表示一个特定函数的参数列表
union funcParameter
	{
		struct funcParameter1 p1;
		struct funcParameter2 p2;
		struct funcParameter3 p3;
		
		struct funcParameter4 p4;
		struct funcParameter5 p5;
		struct funcParameter6 p6;
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
void sendRightMuoseClick(int X, int Y, int delyTime);
void locationToMapPos(int mapNameID, int x, int y, int delyTime);//到指定地图的指定位置
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

void luanmaChuLi(CString &str);



//////////////////xiao小任务集合////////////////

//接取任务
void AccessTask(CPoint * poss);//ca参数为全局位置数组，一些常用位置坐标






//wu天下无忧任务处理函数
void tianxiawuyouTaskHandle(void);