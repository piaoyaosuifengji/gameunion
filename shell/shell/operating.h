

#include "StdAfx.h"









/*
���еĲ������ͣ�



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

//�ýṹ���е�ûһ����Ա��ʾһ���ض������Ĳ����б�
union funcParameter
	{
		struct funcParameter1 p1;
		struct funcParameter2 p2;

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




void sendALeftMuoseClick(int X,int Y ,int delyTime);  //����Ϊclick��λ�ã���������ӳٶ�����
void ToInPutChar(char c,int delyTime);
int haveToDo(int countINFact,struct operat *p,struct dodo * todo);
int runShell(int countINFact,struct dodo *todo);