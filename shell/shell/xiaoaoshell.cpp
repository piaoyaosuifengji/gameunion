#include "StdAfx.h"
#include "xiaoaoshell.h"
#include "fileoperating.h"
#include "operating.h"
xiaoaoshell::xiaoaoshell(void)
{
}


xiaoaoshell::~xiaoaoshell(void)
{
}

DWORD WINAPI autoAttack(PVOID pvParam)
{
	int res=0;
	CString fileName;
	//标志当前究竟是哪个角色在打。0是未知。1是峨眉，2是唐门
	struct AttackType *t=(struct AttackType *)pvParam;
	int autoAttackType=(int)pvParam;
	//int cccc=(int)autoAttackType;
	if(autoAttackType == 1)
	{
		fileName.Format(_T("D:\\data\\autoAttack.txt"));
	}
	else if(autoAttackType == 2)
	{
		fileName.Format(_T("D:\\data\\shell\\autoAttackfortangmeng.txt"));
	}
	else{		CString  zuobiao1(_T(" wrong autoAttackType"));
		AfxMessageBox(zuobiao1);
		return res;
	}
	//读取shell文本

	int count=lineCount( fileName);
	struct operat *p=new struct operat[count];
	int countINFact=ReadTxtToGetShellByName2(fileName,count,p);
	//分析命令
	//就是得出该执行的操作，以及相应的参数
	struct dodo *todo=new struct dodo[countINFact];
	 res=haveToDo( countINFact, p,  todo);
	//最后检查操作
	if(res <=0)
	{
		CString  zuobiao1(_T("some wrong"));
		AfxMessageBox(zuobiao1);
		//int res=runShell( countINFact, todo);

	}
	int width = GetSystemMetrics ( SM_CXSCREEN ); 
	int height= GetSystemMetrics ( SM_CYSCREEN ); 

	CString fileName2("D:\\data\\1440900\\zuobiao.txt");
	CPoint  *ParameterPoints;
	CString Environment=for1440and900;

	if(width == 1440 && height==900)
	{
		fileName2.Format(_T("D:\\data\\1440900\\zuobiao.txt"));
		ParameterPoints=ReadTxtToGetPoints(fileName2);
		Environment=for1440and900;
	}
	else if(width == 1280 && height==800)
	{
		fileName2.Format(_T("D:\\data\\1280800\\zuobiao.txt"));
		ParameterPoints=ReadTxtToGetPoints(fileName2);
		Environment=for1280and800;
	}
	else
		return res;

	Sleep(4000);
	char c;
	int delyTime;
	int continueAutoAttack=1;
	int cycle=0;
	while(continueAutoAttack)
	{
		cycle++;
		if(cycle == 10)
			cycle=0;
		//ruguo如果是峨眉那么美循环5次可以加一下血
		//if(cycle == 3  && autoAttackType == 1 )
		//	ToInPutChar('q',500);
		//选怪
		c='e';
		delyTime=500;
		ToInPutChar( c, delyTime);
		//2：技能释放-
		res=runShell( countINFact, todo);

		//3：判断是否打死了怪

		//自动加血蓝内气
		//res=ifNeedToNeiLi(CString Environment,CPoint  * ParameterPoints);
		int need=ifNeedToNeiLi( Environment,  ParameterPoints);
		if(need ==1)
		{
			ToInPutKeyboardKey(VK_F2,200);//默认f2回内力

		}
		 need=ifNeedToHuiXue( Environment,  ParameterPoints);
		if(need ==1)
		{
			ToInPutKeyboardKey(VK_F4,200);//默认f2回内红

		}


	}
	delete[] p;
	delete[] todo;
	return res;
}
//返回1表示需要，0表示不需要，负数说明出错了

//ParameterPoints就是该环境下的相关参数数组，长度是默认值movePointsLength,但是不一定所有参数都有用
int ifNeedToNeiLi(CString Environment,CPoint  * ParameterPoints)
{
	int res=-1;
	CString str;
	int badcolour=0;
	if(Environment.Compare(_T("1440900")) == 0)
	{
		res=0;
		//红条的起始位置657.852---476.852
		//内力条的起始位置783.852---963.852

		//下面截取起始位置的8个点的颜色值
		//如果前面8个值又4个和预想的（满蓝条状态下的值）不一样，就认为需要回蓝了
		int i=0;
		int j=0;
		CPoint linPoint;
	    struct colourRGB  obColour;
		

		struct colourRGB  goodcolour[9];
		int r=1;
		int g=1;
		int b=1;
		//1
		goodcolour[j].R=r;
		goodcolour[j].G=85;
		goodcolour[j].B=131;
		j++;//2
		goodcolour[j].R=1;
		goodcolour[j].G=93;
		goodcolour[j].B=141;
		j++;//3
		goodcolour[j].R=r;
		goodcolour[j].G=93;
		goodcolour[j].B=141;
		j++;//4
		goodcolour[j].R=r;
		goodcolour[j].G=121;
		goodcolour[j].B=173;
		j++;//5
		goodcolour[j].R=r;
		goodcolour[j].G=96;
		goodcolour[j].B=145;
		j++;//6
		goodcolour[j].R=r;
		goodcolour[j].G=97;
		goodcolour[j].B=146;
		j++;//7
		goodcolour[j].R=3;
		goodcolour[j].G=118;
		goodcolour[j].B=170;
		j++;//8
		goodcolour[j].R=19;
		goodcolour[j].G=76;
		goodcolour[j].B=114;

		for(;i<8;i++)
		{
			/* SetCursorPos(100,92);
             GetCurrentRGB(oldPoint);*/
			linPoint.x=ParameterPoints[2].x+20*i;
			linPoint.y=ParameterPoints[2].y;
			 GetPointRGB(&linPoint,&obColour);

			 //SetCursorPos(linPoint.x,linPoint.y);

			 //h获取改点tgb
			// str.Format(_T("x=%d,y=%d,g,b=%d,%d,%d  \n"),linPoint.x,linPoint.y,obColour.R,obColour.G,obColour.B);
			//standardOutput( str);

			if(goodcolour[i].R !=obColour.R || goodcolour[i].G !=obColour.G || goodcolour[i].B !=obColour.B  )
				badcolour++;

		}

	}
	if(Environment.Compare(_T("1280800")) == 0)
	{
		res=0;
		//红条的起始位置591.751---407.751
		//内力条的起始位置689.751---869.751

		//下面截取起始位置的8个点的颜色值
		//如果前面8个值又4个和预想的（满蓝条状态下的值）不一样，就认为需要回蓝了
		int i=0;
		int j=0;
		CPoint linPoint;
	    struct colourRGB  obColour;
		

		struct colourRGB  goodcolour[9];
		int r=0;
		int g=1;
		int b=1;
		//1
		goodcolour[j].R=r;
		goodcolour[j].G=127;
		goodcolour[j].B=183;
		j++;//2
		goodcolour[j].R=0;
		goodcolour[j].G=106;
		goodcolour[j].B=160;
		j++;//3
		goodcolour[j].R=r;
		goodcolour[j].G=111;
		goodcolour[j].B=164;
		j++;//4
		goodcolour[j].R=r;
		goodcolour[j].G=131;
		goodcolour[j].B=187;
		j++;//5
		goodcolour[j].R=r;
		goodcolour[j].G=111;
		goodcolour[j].B=165;
		j++;//6
		goodcolour[j].R=r;
		goodcolour[j].G=117;
		goodcolour[j].B=172;
		j++;//7
		goodcolour[j].R=4;
		goodcolour[j].G=99;
		goodcolour[j].B=149;
		j++;//8
		goodcolour[j].R=22;
		goodcolour[j].G=97;
		goodcolour[j].B=142;

		for(;i<8;i++)
		{
			/* SetCursorPos(100,92);
             GetCurrentRGB(oldPoint);*/
			linPoint.x=ParameterPoints[2].x+20*i;
			linPoint.y=ParameterPoints[2].y;
			 GetPointRGB(&linPoint,&obColour);
			 //SetCursorPos(linPoint.x,linPoint.y);

		/*	 str.Format(_T("x=%d,y=%d,g,b=%d,%d,%d  \n"),linPoint.x,linPoint.y,obColour.R,obColour.G,obColour.B);
			standardOutput( str);*/

			if(goodcolour[i].R !=obColour.R || goodcolour[i].G !=obColour.G || goodcolour[i].B !=obColour.B  )
				badcolour++;

		}

	}
	str.Format(_T("badcolour=%d  \n"),badcolour);
	standardOutput( str);
	if(badcolour >2)
		res=1;
	return res;
}

//判断是否需要回血
int ifNeedToHuiXue(CString Environment,CPoint  * ParameterPoints)
{
	int res=-1;
	CString str;
	int badcolour=0;
	if(Environment.Compare(_T("1440900")) == 0)
	{
		//红条的起始位置657.852---476.852
		//内力条的起始位置783.852---963.852

		//下面截取起始位置的8个点的颜色值
		//如果前面8个值又4个和预想的（满蓝条状态下的值）不一样，就认为需要回蓝了
		int i=0;
		int j=0;
		CPoint linPoint;
	    struct colourRGB  obColour;
		

		struct colourRGB  goodcolour[9];

		//1
		goodcolour[j].R=142;
		goodcolour[j].G=0;
		goodcolour[j].B=10;
		j++;//2
		goodcolour[j].R=133;
		goodcolour[j].G=0;
		goodcolour[j].B=8;
		j++;//3
		goodcolour[j].R=125;
		goodcolour[j].G=0;
		goodcolour[j].B=5;
		j++;//4
		goodcolour[j].R=155;
		goodcolour[j].G=1;
		goodcolour[j].B=7;
		j++;//5
		goodcolour[j].R=150;
		goodcolour[j].G=1;
		goodcolour[j].B=9;
		j++;//6
		goodcolour[j].R=122;
		goodcolour[j].G=3;
		goodcolour[j].B=3;
		j++;//7
		goodcolour[j].R=169;
		goodcolour[j].G=53;
		goodcolour[j].B=3;
		j++;//8
		goodcolour[j].R=134;
		goodcolour[j].G=7;
		goodcolour[j].B=1;
		//linPoint.x=ParameterPoints[2].x;
		//linPoint.y=ParameterPoints[2].y;
		for(;i<8;i++)
		{
			/* SetCursorPos(100,92);
             GetCurrentRGB(oldPoint);*/
			linPoint.x=ParameterPoints[1].x-20*i;
			linPoint.y=ParameterPoints[1].y;
			 GetPointRGB(&linPoint,&obColour);

			//SetCursorPos(linPoint.x,linPoint.y);
			// Sleep(500);
			// str.Format(_T("x=%d,y=%d,g,b=%d,%d,%d  \n"),linPoint.x,linPoint.y,obColour.R,obColour.G,obColour.B);
			//standardOutput( str);

			if(goodcolour[i].R !=obColour.R || goodcolour[i].G !=obColour.G || goodcolour[i].B !=obColour.B  )
				badcolour++;

		}

	}
	if(Environment.Compare(_T("1280800")) == 0)
	{
		//红条的起始位置591.751---407.751
		//内力条的起始位置689.751---869.751

		//下面截取起始位置的8个点的颜色值
		//如果前面8个值又4个和预想的（满蓝条状态下的值）不一样，就认为需要回蓝了
		int i=0;
		int j=0;
		CPoint linPoint;
	    struct colourRGB  obColour;
		

		struct colourRGB  goodcolour[9];

		//1
		goodcolour[j].R=154;
		goodcolour[j].G=0;
		goodcolour[j].B=11;
		j++;//2
		goodcolour[j].R=146;
		goodcolour[j].G=0;
		goodcolour[j].B=16;
		j++;//3
		goodcolour[j].R=136;
		goodcolour[j].G=0;
		goodcolour[j].B=12;
		j++;//4
		goodcolour[j].R=149;
		goodcolour[j].G=0;
		goodcolour[j].B=10;
		j++;//5
		goodcolour[j].R=149;
		goodcolour[j].G=0;
		goodcolour[j].B=15;
		j++;//6
		goodcolour[j].R=143;
		goodcolour[j].G=2;
		goodcolour[j].B=6;
		j++;//7
		goodcolour[j].R=146;
		goodcolour[j].G=3;
		goodcolour[j].B=3;
		j++;//8
		goodcolour[j].R=144;
		goodcolour[j].G=0;
		goodcolour[j].B=3;
		//linPoint.x=ParameterPoints[2].x;
		//linPoint.y=ParameterPoints[2].y;
		for(;i<8;i++)
		{
			/* SetCursorPos(100,92);
             GetCurrentRGB(oldPoint);*/
			linPoint.x=ParameterPoints[1].x-20*i;
			linPoint.y=ParameterPoints[1].y;
			 GetPointRGB(&linPoint,&obColour);

			//SetCursorPos(linPoint.x,linPoint.y);
			// Sleep(500);
			 str.Format(_T("x=%d,y=%d,g,b=%d,%d,%d  \n"),linPoint.x,linPoint.y,obColour.R,obColour.G,obColour.B);
			standardOutput( str);

			if(goodcolour[i].R !=obColour.R || goodcolour[i].G !=obColour.G || goodcolour[i].B !=obColour.B  )
				badcolour++;

		}

	}
	if(badcolour >2)
		res=1;
	return res;
}

//传入指定的文件名，运行该文件
void readAndRunShell(CString  littleshellfile)
{
	//Sleep(3000);
	//读取shell文本
	CString fileName(littleshellfile);
	int count=lineCount( fileName);
	if (count <= 0)
		return;
	struct operat *p=new struct operat[count];
	int countINFact=ReadTxtToGetShellByName2(fileName,count,p);
	//分析命令
	//就是得出该执行的操作，以及相应的参数
	struct dodo *todo=new struct dodo[countINFact];
	int res=haveToDo( countINFact, p,  todo);
	//最后检查操作
	if(res >0)
	{

		 res=runShell( countINFact, todo);


	}
	else
	{
		CString  zuobiao1(_T("some wrong"));
		AfxMessageBox(zuobiao1);
	}

}