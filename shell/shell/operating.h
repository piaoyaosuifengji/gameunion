

#include "StdAfx.h"
#include <afxmt.h>


//zheli���ﶨ�弸���й���ʾ���ֱ��ʵĺ�

#define for1440and900  _T("1440900")
#define for1280and800  _T("1280800")



/*

�ű�ʹ��˵������shellResolve.h��
char:1000:1:0
�ṹ���������ͣ�ʱ�䣺��������������


�ű��������̣�
	1����ȡ�ű��������ű������ɶ��溯����������ṹstruct operat    	ReadTxtToGetShellByName2����
	2����struct operat  ת����������Ҫ�Ĳ�����ʽ struct dodo            haveToDo( countINFact, p,  todo);
	2�����ú�����������													runShell����

��������Ҫ����һ���²���������Ϊ��
	1��������������꣺shellResolve.h���������������funcParameter��  �ṹ  �Լ���Ӧ��funcID   ��
	2����funcParameter��  ����������union funcParameter
	3������ ��Ӧʵ�ֵĲ�������
	4�����µ��жϼ��뺯����haveToDo  �� runShell  ������������


���еĲ������ͣ�
																							�ű��ж������������
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
struct funcParameter4  //for void locationToMapPos()    mapNameID��ָ����ͼ��ID��
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

//�ýṹ���е�ûһ����Ա��ʾһ���ض������Ĳ����б�
union funcParameter
	{
		struct funcParameter1 p1;
		struct funcParameter2 p2;
		struct funcParameter3 p3;
		
		struct funcParameter4 p4;
		struct funcParameter5 p5;
		struct funcParameter6 p6;
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
void sendRightMuoseClick(int X, int Y, int delyTime);
void locationToMapPos(int mapNameID, int x, int y, int delyTime);//��ָ����ͼ��ָ��λ��
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

void luanmaChuLi(CString &str);



//////////////////xiaoС���񼯺�////////////////

//��ȡ����
void AccessTask(CPoint * poss);//ca����Ϊȫ��λ�����飬һЩ����λ������






//wu����������������
void tianxiawuyouTaskHandle(void);