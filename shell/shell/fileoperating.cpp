#include "StdAfx.h"
#include "fileoperating.h"

    bool ifworkIngProStar=false;
	CPoint  movePoints[movePointsLength];//记录从文件中获取的坐标值
	CPoint  movePointsReal[movePointsLength];//此次运行的真实值
	bool  ZanTing=false;//此值用以控制暂停采集，只要程序不停止运行，那么下次采集将从当前线的下线开始
	int   OldCaiJiline=15;//配合ZanTing，当ZanTing为true时那么下次就从OldCaiJiline+1开始采集
    bool ifCaiJiMnegJingHuaCycle=false;//判断是否循环采集梦境花，默认为false--即循环采集
	                                //在采集陵寝藤是会将其设置为true




fileoperating::fileoperating(void)
{
}


fileoperating::~fileoperating(void)
{
}


//废弃
void ReadTxtToGetShell()
{
	int count=0;
	CString fileName("Shell.txt");
	CStdioFile openfile(fileName,CFile::modeRead);				//构造CStdioFile对象
	CString str;
	CString zuobiao("");
	while(openfile.ReadString(str))							//读一行数据
	{
		if(count >20)   //读入20个数据就停止
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

		//movePoints[count].x=X;  //从movePoints[1]开始记录
		//movePoints[count].y=Y;

/*	  zuobiao.Format(_T("read zuobiao id %d   %d"),X,Y);
		AfxMessageBox(zuobiao);
*/
	}
	openfile.Close();										//关闭文件
      

}
//废弃
struct list_head * ReadTxtToGetShellByName(CString fileName)
{
	struct operat lin;
	struct list_head *head=(struct list_head *)malloc(sizeof(struct list_head ));
	struct operat newshell;
	int count=0;

	INIT_LIST_HEAD(head);

	CStdioFile openfile(fileName,CFile::modeRead);				//构造CStdioFile对象
	CString str;
	//命令类型：命令执行时间：参数个数：参数
	//wchar_t  shelltype[100];
	//int time=1000;
	//int ParameterNum=1;
	//wchar_t  Parameter[500];
	//wchar_t
	while(openfile.ReadString(str))							//读一行数据
	{
		if(count >20)   //读入20个数据就停止
			break;
		//buf=(LPCTSTR)str;
		//swscanf_s(str.GetBuffer(),_T("%s:%d:%d:%s"),shelltype,time,ParameterNum,Parameter);



		//提取文本
		int loct=str.Find(_T(":"));
		CString shelltype=str.Left(loct);

		CString zhong=str.Right(str.GetLength()-loct-1);

		loct=zhong.Find(_T(":"));
		CString time=zhong.Left(loct);
		zhong=zhong.Right(zhong.GetLength()-loct-1);

		loct=zhong.Find(_T(":"));
		CString ParameterNum=zhong.Left(loct);
		CString Parameter=zhong.Right(zhong.GetLength()-loct-1);
	    //新建一个命令节点
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
	openfile.Close();										//关闭文件
      
	return head;
}

int lineCount(CString fileName)
{
	CStdioFile openfile(fileName,CFile::modeRead);				//构造CStdioFile对象
	CString str;
	int count=0;
	while(openfile.ReadString(str))							//读一行数据
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
	CStdioFile openfile(fileName,CFile::modeRead);				//构造CStdioFile对象
	CString str;
	//命令类型：命令执行时间：参数个数：参数
	while(openfile.ReadString(str))							//读一行数据
	{
		if(count >20)   //读入20个数据就停止
			break;
		 WCHAR  fc=str.GetAt(0);
		 CString firc(fc);
		 CString cc(_T("#"));

		if(firc.Compare(cc) ==0)
			 continue;
		//提取文本
		int loct=str.Find(_T(":"));
		CString shelltype=str.Left(loct);

		CString zhong=str.Right(str.GetLength()-loct-1);

		loct=zhong.Find(_T(":"));
		CString time=zhong.Left(loct);
		zhong=zhong.Right(zhong.GetLength()-loct-1);

		loct=zhong.Find(_T(":"));
		CString ParameterNum=zhong.Left(loct);
		CString Parameter=zhong.Right(zhong.GetLength()-loct-1);
	    //新建一个命令节点
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
	openfile.Close();										//关闭文件
      return count;
}

	CPoint  * ReadTxtToGetPoints(CString fileName)
	{
		CPoint  *movePointsP;
		movePointsP=movePoints;
		int count=0;
		//CString fileName("D:\\data\\zuobiao.txt");
		CStdioFile openfile(fileName,CFile::modeRead);				//构造CStdioFile对象
		CString str;
		CString zuobiao("");
		while(openfile.ReadString(str))							//读一行数据
		{
			if(count >20)   //读入20个数据就停止
				break;

		  int loct=str.Find(_T("."));
		  CString x=str.Left(loct);
		  CString y=str.Right(str.GetLength()-loct-1);

		  //for()

		  int Y=_wtoi(y);

		  int X=_wtoi(x);
	    	count++;

			movePoints[count].x=X;  //从movePoints[1]开始记录
			movePoints[count].y=Y;

	/*	  zuobiao.Format(_T("read zuobiao id %d   %d"),X,Y);
		  AfxMessageBox(zuobiao);
*/
		}
		openfile.Close();										//关闭文件
      
		return movePointsP;

	}