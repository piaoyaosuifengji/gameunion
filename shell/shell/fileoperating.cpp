#include "StdAfx.h"
#include "fileoperating.h"

    bool ifworkIngProStar=false;
	CPoint  movePoints[movePointsLength];//��¼���ļ��л�ȡ������ֵ
	CPoint  movePointsReal[movePointsLength];//�˴����е���ʵֵ
	bool  ZanTing=false;//��ֵ���Կ�����ͣ�ɼ���ֻҪ����ֹͣ���У���ô�´βɼ����ӵ�ǰ�ߵ����߿�ʼ
	int   OldCaiJiline=15;//���ZanTing����ZanTingΪtrueʱ��ô�´ξʹ�OldCaiJiline+1��ʼ�ɼ�
    bool ifCaiJiMnegJingHuaCycle=false;//�ж��Ƿ�ѭ���ɼ��ξ�����Ĭ��Ϊfalse--��ѭ���ɼ�
	                                //�ڲɼ��������ǻὫ������Ϊtrue




fileoperating::fileoperating(void)
{
}


fileoperating::~fileoperating(void)
{
}


//����
void ReadTxtToGetShell()
{
	int count=0;
	CString fileName("Shell.txt");
	CStdioFile openfile(fileName,CFile::modeRead);				//����CStdioFile����
	CString str;
	CString zuobiao("");
	while(openfile.ReadString(str))							//��һ������
	{
		if(count >20)   //����20�����ݾ�ֹͣ
			break;
		 WCHAR  fc=str.GetAt(0);
		 CString firc(fc);
		 CString cc(_T("#"));

		if(firc.Compare(cc) ==0)
			 continue;
		int loct=str.Find(_T(":"));
		CString x=str.Left(loct);
		CString y=str.Right(str.GetLength()-loct-1);

		//for()

		int Y=_wtoi(y);

		int X=_wtoi(x);
	    count++;

		//movePoints[count].x=X;  //��movePoints[1]��ʼ��¼
		//movePoints[count].y=Y;

/*	  zuobiao.Format(_T("read zuobiao id %d   %d"),X,Y);
		AfxMessageBox(zuobiao);
*/
	}
	openfile.Close();										//�ر��ļ�
      

}
//����
struct list_head * ReadTxtToGetShellByName(CString fileName)
{
	struct operat lin;
	struct list_head *head=(struct list_head *)malloc(sizeof(struct list_head ));
	struct operat newshell;
	int count=0;

	INIT_LIST_HEAD(head);

	CStdioFile openfile(fileName,CFile::modeRead);				//����CStdioFile����
	CString str;
	//�������ͣ�����ִ��ʱ�䣺��������������
	//wchar_t  shelltype[100];
	//int time=1000;
	//int ParameterNum=1;
	//wchar_t  Parameter[500];
	//wchar_t
	while(openfile.ReadString(str))							//��һ������
	{
		if(count >20)   //����20�����ݾ�ֹͣ
			break;
		//buf=(LPCTSTR)str;
		//swscanf_s(str.GetBuffer(),_T("%s:%d:%d:%s"),shelltype,time,ParameterNum,Parameter);



		//��ȡ�ı�
		int loct=str.Find(_T(":"));
		CString shelltype=str.Left(loct);

		CString zhong=str.Right(str.GetLength()-loct-1);

		loct=zhong.Find(_T(":"));
		CString time=zhong.Left(loct);
		zhong=zhong.Right(zhong.GetLength()-loct-1);

		loct=zhong.Find(_T(":"));
		CString ParameterNum=zhong.Left(loct);
		CString Parameter=zhong.Right(zhong.GetLength()-loct-1);
	    //�½�һ������ڵ�
		//newshell=new struct operat;
		newshell.Parameter=Parameter;
		newshell.ParameterNum=_wtoi(ParameterNum);
		newshell.shelltype=shelltype;
		newshell.time=_wtoi(time);

		struct operat *newshell2=new struct operat;
		//*newshell2=newshell;
		newshell2->Parameter=newshell.Parameter;
		newshell2->ParameterNum=newshell.ParameterNum;
		newshell2->shelltype=newshell.shelltype;
		newshell2->time=newshell.time;
		list_add_tail((struct list_head *)newshell2,head);
	    count++;


	  CString  zuobiao1,shi,zuobiao2;
	  zuobiao1.Format(_T(" time=%d"),(newshell2->time));
	  zuobiao2.Format(_T(" ParameterNum=%d"),(newshell2->ParameterNum));
	  shi=(newshell2->shelltype)+zuobiao1+zuobiao2+newshell2->Parameter;
		AfxMessageBox(shi);

	}
	openfile.Close();										//�ر��ļ�
      
	return head;
}

int lineCount(CString fileName)
{
	CStdioFile openfile(fileName,CFile::modeRead);				//����CStdioFile����
	CString str;
	int count=0;
	while(openfile.ReadString(str))							//��һ������
	{

			count++;
	}
	return count;
}
int ReadTxtToGetShellByName2(CString fileName,int linecount,struct operat *p)
{
		struct operat newshell;
	struct operat lin;
	int count=0;
	CStdioFile openfile(fileName,CFile::modeRead);				//����CStdioFile����
	CString str;
	//�������ͣ�����ִ��ʱ�䣺��������������
	while(openfile.ReadString(str))							//��һ������
	{
		if(count >20)   //����20�����ݾ�ֹͣ
			break;
		 WCHAR  fc=str.GetAt(0);
		 CString firc(fc);
		 CString cc(_T("#"));

		if(firc.Compare(cc) ==0)
			 continue;
		//��ȡ�ı�
		int loct=str.Find(_T(":"));
		CString shelltype=str.Left(loct);

		CString zhong=str.Right(str.GetLength()-loct-1);

		loct=zhong.Find(_T(":"));
		CString time=zhong.Left(loct);
		zhong=zhong.Right(zhong.GetLength()-loct-1);

		loct=zhong.Find(_T(":"));
		CString ParameterNum=zhong.Left(loct);
		CString Parameter=zhong.Right(zhong.GetLength()-loct-1);
	    //�½�һ������ڵ�
		//newshell=new struct operat;
		newshell.Parameter=Parameter;
		newshell.ParameterNum=_wtoi(ParameterNum);
		newshell.shelltype=shelltype;
		newshell.time=_wtoi(time);

		(p[count]).Parameter=newshell.Parameter;
		p[count].ParameterNum=newshell.ParameterNum;
		p[count].shelltype=newshell.shelltype;
		p[count].time=newshell.time;
	    count++;


	 // CString  zuobiao1,shi,zuobiao2;
	 // zuobiao1.Format(_T(" time=%d"),(newshell2->time));
	 // zuobiao2.Format(_T(" ParameterNum=%d"),(newshell2->ParameterNum));
	 // shi=(newshell2->shelltype)+zuobiao1+zuobiao2+newshell2->Parameter;
		//AfxMessageBox(shi);

	}
	openfile.Close();										//�ر��ļ�
      return count;
}

	CPoint  * ReadTxtToGetPoints(CString fileName)
	{
		CPoint  *movePointsP;
		movePointsP=movePoints;
		int count=0;
		//CString fileName("D:\\data\\zuobiao.txt");
		CStdioFile openfile(fileName,CFile::modeRead);				//����CStdioFile����
		CString str;
		CString zuobiao("");
		while(openfile.ReadString(str))							//��һ������
		{
			if(count >20)   //����20�����ݾ�ֹͣ
				break;

		  int loct=str.Find(_T("."));
		  CString x=str.Left(loct);
		  CString y=str.Right(str.GetLength()-loct-1);

		  //for()

		  int Y=_wtoi(y);

		  int X=_wtoi(x);
	    	count++;

			movePoints[count].x=X;  //��movePoints[1]��ʼ��¼
			movePoints[count].y=Y;

	/*	  zuobiao.Format(_T("read zuobiao id %d   %d"),X,Y);
		  AfxMessageBox(zuobiao);
*/
		}
		openfile.Close();										//�ر��ļ�
      
		return movePointsP;

	}