

#include "StdAfx.h"



//zheli���ﶨ�弸���й���ʾ���ֱ��ʵĺ�

#define for1440and900  _T("1440900")
#define for1280and800  _T("1280800")



/*
���еĲ������ͣ�



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
//�ýṹ���е�ûһ����Ա��ʾһ���ض������Ĳ����б�
union funcParameter
	{
		struct funcParameter1 p1;
		struct funcParameter2 p2;
		struct funcParameter3 p3;
		struct funcParameter4 p4;
	};


//���еĲ������ն���ӳ���ĳһ���ض��ĺ�����ȥ����ô�����Ҫ��һ�������б�ʾ��������Щ����
//�����ô����,������һ���ṹ������
//�����еĺ������б��funcID��һ���ض��Ĳ�������Ҫ�ĺ�����Ψһ��id
//��һ��union funcParameter paramet;�������Ӧ�Ĳ���

struct dodo
{

	int funcID;
	union funcParameter paramet;

};


struct AttackType
{

	int type;
};

void sendALeftMuoseClick(int X,int Y ,int delyTime);  //����Ϊclick��λ�ã���������ӳٶ�����
void ToInPutChar(char c,int delyTime);
int haveToDo(int countINFact,struct operat *p,struct dodo * todo);
int runShell(int countINFact,struct dodo *todo);
void PutKeyDown(char c,int delyTime);
void GetCurrentRGB(CPoint pt);
void GetPointRGB(CPoint *pt,struct colourRGB * obColour);
void  standardOutput(CString str);
void ToInPutKeyboardKey(int c,int delyTime);
///////////////////////////RGB//////////////////////////////////
//��a��bֵ��Ӻ󸳸�a
int addRGB(struct colourRGB *a,struct colourRGB *b);
//��ʼ��һ��rgb
 int initRGB(struct colourRGB *a);
 ///////////////////////////RGB//////////////////////////////////
 struct colourRGB  	CalculateAverageValueRBG(CPoint start,CPoint end,int Thickness);
 int getMsgForFindMatrix(CString file,CPoint *startPoint,struct colourRGB * AverageValueRBG);
int FindMatrix(CPoint startPoint,struct colourRGB obColour,CPoint *LeftPoint,CPoint *RightPoint);