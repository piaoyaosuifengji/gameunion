#include "stdafx.h"
#include "tianyuShell.h"
#include "fileoperating.h"
#include "operating.h"
#include "xiaoaoshell.h"
#include "DialogMsg.h"
tianyuShell::tianyuShell()
{
}


tianyuShell::~tianyuShell()
{
}
DWORD WINAPI dandiancaijiForTianYu(PVOID pvParam)
{
	int res = 0;
	int continueAutoAttack = 1;
	Sleep(5000);
	while (continueAutoAttack)
	{


		ToInPutKeyboardKey(0x46, 100);//捡东西
		Sleep(7000);

	}
	return res;
}
DWORD WINAPI autoAttack_LingLongZuDui(PVOID pvParam)
{
	int res = 0;
	CString fileName;
	int  firstRun = 1;//循环标志，第一次进入循环结束后修改
	//标志当前究竟是哪个角色在打。0是未知。1是玲珑，2是玉虚，2是炎天
	struct AttackType *t = (struct AttackType *)pvParam;
	int autoAttackType = (int)pvParam;
	//int cccc=(int)autoAttackType;
	if (autoAttackType == 1)
	{
		fileName.Format(_T("C:\\data\\tianyu\\autoAttackLingLongZuDui.txt"));
	}
	else if (autoAttackType == 2)
	{
		fileName.Format(_T("C:\\data\\tianyu\\autoAttackforDPS.txt"));
	}
	else if (autoAttackType == 3)
	{
		fileName.Format(_T("C:\\data\\tianyu\\yantian.txt"));
	}
	else{
		CString  zuobiao1(_T(" wrong autoAttackType"));
		AfxMessageBox(zuobiao1);
		return res;
	}
	//读取shell文本

	int count = lineCount(fileName);
	struct operat *p = new struct operat[count];
	int countINFact = ReadTxtToGetShellByName2(fileName, count, p);
	//分析命令
	//就是得出该执行的操作，以及相应的参数
	struct dodo *todo = new struct dodo[countINFact];
	res = haveToDo(countINFact, p, todo);
	//最后检查操作
	if (res <= 0)
	{
		CString  zuobiao1(_T("some wrong"));
		AfxMessageBox(zuobiao1);
		//int res=runShell( countINFact, todo);

	}
	int width = GetSystemMetrics(SM_CXSCREEN);
	int height = GetSystemMetrics(SM_CYSCREEN);

	CString fileName2("C:\\data\\1440900\\zuobiao.txt");
	CPoint  *ParameterPoints;
	CString Environment = for1440and900;
	//首先判断游戏窗口大小，如果是800*600就不要管pc的分辨率了
	//实际得到的是816*638
	struct WindowPosMsg  windowMsg = getGameWindowSize(_T("NETEASE-TY-APP"), NULL);

	//SetCursorPos(windowMsg.TopLeftPoint.x + 8, windowMsg.TopLeftPoint.y+30);
	if ((windowMsg.Width - 800)<50 && (windowMsg.Height - 600)<70)
	{

		fileName2.Format(_T("C:\\data\\800600\\zuobiao.txt"));
		ParameterPoints = ReadTxtToGetPoints(fileName2);
		Environment = for800and600;

	}
	else if (width == 1440 && height == 900)
	{
		fileName2.Format(_T("C:\\data\\1440900\\zuobiao.txt"));
		ParameterPoints = ReadTxtToGetPoints(fileName2);
		Environment = for1440and900;
	}
	else if (width == 1280 && height == 800)
	{
		fileName2.Format(_T("C:\\data\\1280800\\zuobiao.txt"));
		ParameterPoints = ReadTxtToGetPoints(fileName2);
		Environment = for1280and800;
	}
	else if (width == 1280 && height == 720)
	{
		fileName2.Format(_T("C:\\data\\1280720\\zuobiao.txt"));
		ParameterPoints = ReadTxtToGetPoints(fileName2);
		Environment = for1280and720;
	}
	//else
	//	return res;

	Sleep(2500);
	char c;
	int delyTime,i;
	int continueAutoAttack = 1;
	int cycle = 0;
	int need=0;
	int  qieguai = 1;
	int addBlueFlag = 0;


	//AfxGetApp()->LoadIcon(IDI_ICON1);
	//SetIcon(m_hIcon, true);
	//SetIcon(m_hIcon, false);
	if (ParameterPoints == NULL || windowMsg.Height == 0 || windowMsg.Width == 0)
	{

		OutputDebugString(_T("some wrong \n"));
		return res;
	}

	ToInPutKeyboardKey(9, 100);//切怪
	while (continueAutoAttack)
	{
		cycle++;
		if (cycle >= 30)
			cycle = 0;
		if (qieguai >= 10)	
			qieguai = 1;
		if (qieguai == 10)
			ToInPutKeyboardKey(0x46, 100);//捡东西

		qieguai++;
		//ruguo如果是峨眉那么美循环5次可以加一下血
		//if(cycle == 3  && autoAttackType == 1 )
		//	ToInPutChar('q',500);
		//选怪
		c = 'e';
		delyTime = 500;
		//ToInPutChar(c, delyTime);
		//2：技能释放-
		

		/*
		//3：判断是否打死了怪
		*/

		need = ifNeedToFindNewMonster(Environment, ParameterPoints, windowMsg);
		if (need == 1)
		{
			ToInPutKeyboardKey(9, 100);//切怪
			OutputDebugString(_T("切怪 \n"));
		//fight

		}
		res = runShell(countINFact, todo);
		OutputDebugString(_T("fight over \n"));

		//addBlueFlag
		//有时候会出现以为，导致错误加蓝，为了避免这种情况，所以这里需要连续俩次发现需要加蓝才调用加蓝函数
		need = ifNeedToRecoveryBlue(Environment, ParameterPoints, windowMsg);
		if (need == 1 && addBlueFlag == 1)
		{
			addBlueFlag = 0;
			OutputDebugString(_T("need  add  Blue \n"));
			//AfxGetMainWnd()->SetWindowText(_T("need  add  blood"));
			ToInPutKeyboardKey(57, 100);//默认9回蓝
		}
		else if (need == 1 && addBlueFlag == 0)
			addBlueFlag = 1;
		else
		{
			OutputDebugString(_T("do not need  add  Blue \n"));
			addBlueFlag = 0;
		}



		need = ifNeedToRecoveryBlood(Environment, ParameterPoints,   windowMsg);
		if (need == 1)
		{
			OutputDebugString(_T("need  add  blood \n"));
			//AfxGetMainWnd()->SetWindowText(_T("need  add  blood"));

			if (autoAttackType == 1)//如果是奶妈按3回血
			{
				ToInPutKeyboardKey(52, 100);//默认0回血
			}
			else 
				ToInPutKeyboardKey(48, 100);//默认0回血
			//ToInPutKeyboardKey(51, 100);//默认0回血
		}
		else OutputDebugString(_T("do not need  add  blood \n"));

		/*
		ifNeedToHuiXue的思路：
		1：找到游戏的窗口
		2:确定血条位置
			方案：a:粗糙的指定坐标，简单而有效，但是局限性太大，不过看起来还是得使用这种办法了
					但是你必须指定：开启次功能时必须是最大屏模式，左右无边框。
				  b：通过寻找控件的方式，值得一试---暂时失败
				  c：通过查找图像的方式，难度大
		3：确定加血的标准，什么情况下加血
		4：确定加血的对象：给自己还是给别人（奶妈特有）
		5：加血
		*/

		//如果是奶妈则需要判断是否要单独给队友加血：
		if (autoAttackType == 1)
		{ 

			//给自己加一些状态：
			if (cycle == 1 || cycle == 15)
			{
				ToInPutKeyboardKey(56, 0);

			}

			//首先判断有多少队友
			//第一次运行的时候判断：
			if (firstRun == 1)
			{
				//还是得考查询颜色来判断，显然这是有缺陷的，受环境影响
				//我擦，其实你并不需要知道到底有多少队友啊，只要默认有4个队友
				//一个个选过来，残血就加就好了啊.....
			}

			//exit(0);
			//挨个判断
			for (i=1;i<=4;i++)
			{
				switch (i)
				{
					Sleep(1000);
					case 1:
						KeyboardCombination(VK_F1, VK_SHIFT);
						break;
					case 2:
						KeyboardCombination(VK_F2, VK_SHIFT);
						break;
					case 3:
						KeyboardCombination(VK_F3, VK_SHIFT);
						break;
					case 4:
						KeyboardCombination(VK_F4, VK_SHIFT);
						break;
					default:break;


				}
				need = ifNeedToGainBlood(Environment, ParameterPoints, windowMsg);
				{

					//给他足够的奶：
					ToInPutKeyboardKey(53, 10);
					ToInPutKeyboardKey(52, 10);
					ToInPutKeyboardKey(55, 10);
				}
				

			}
			//重新切怪：

			ToInPutKeyboardKey(9, 100);//切怪
		}


		if (autoAttackType == 2)
		{
			//给自己加一些状态：
			if (cycle == 1 || cycle == 15)
			{
				ToInPutKeyboardKey(VK_OEM_PLUS, 10);  //加号
				ToInPutKeyboardKey(VK_OEM_MINUS, 10);//减号
			}



		}
		firstRun = 0;
	}
	delete[] p;
	delete[] todo;
	return res;
}
//判断玲珑是否需要给队友加血，返回0则不用，返回1.2.3.4则分别给相应位置队友加血
//通过快捷键直接选择队友,我擦
int ifNeedToGainBlood(CString Environment, CPoint  * ParameterPoints, struct WindowPosMsg windowMsg)
{
	int res = 0;
	CString str;
	int badcolour = 0;
	int i = 0;
	int j = 0;
	CPoint linPoint;
	struct colourRGB  obColour;
	//struct colourRGB  goodcolour[9];
	CPoint pt;
	int len = 50;
	int niceBloodCount = 0;

	//exit(0);
	if (Environment.Compare(_T("800600")) == 0)
	{
		for (i = 0; i < len; i++)
		{
			//这里从右向左找，但事实没必要,但是考虑到野怪扣血的血条是
			//从左向右扣，所以，实际上，你看关注右边半管血条
			pt.x = windowMsg.TopLeftPoint.x + 400 + i;
			pt.y = windowMsg.TopLeftPoint.y + 64;
			//SetCursorPos(pt.x, pt.y);
			//exit(0);
			GetPointRGB(&pt, &obColour);
			//str.Format(_T("(%d,%d,%d)"), obColour.R,obColour.G,obColour.B);
			//standardOutput( str);

			if ((abs(obColour.R - 200) < 50) && (abs(obColour.G - 12) < 15) && (abs(obColour.B - 8) < 8))
				niceBloodCount++;
		}
		//exit(0);
		if (niceBloodCount < 25)
			res = 1;
	}



	return res;


}
//只适用切普通怪，对boss无效，但没关系，打boss时不需要切怪
int ifNeedToFindNewMonster(CString Environment, CPoint  * ParameterPoints, struct WindowPosMsg windowMsg)
{

	int res = 0;
	CString str;
	int badcolour = 0;
	int i = 0;
	int j = 0;
	CPoint linPoint;
	struct colourRGB  obColour;
	//struct colourRGB  goodcolour[9];
	CPoint pt;
	int len = 50;
	int niceBloodCount = 0; 

	//exit(0);
	if (Environment.Compare(_T("800600")) == 0)
	{
		for (i = 0; i < len; i++)
		{
			//这里从右向左找，但事实没必要,但是考虑到野怪扣血的血条是
			//从左向右扣，所以，实际上，你看关注右边半管血条
			pt.x = windowMsg.TopLeftPoint.x + 446 + i;
			pt.y = windowMsg.TopLeftPoint.y + 64;
			//SetCursorPos(pt.x, pt.y);
			//SetCursorPos(windowMsg.TopLeftPoint.x + 145+50, windowMsg.TopLeftPoint.y + 66);
			//exit(0);
			GetPointRGB(&pt, &obColour);
			//str.Format(_T("(%d,%d,%d)"), obColour.R,obColour.G,obColour.B);
			//standardOutput( str);

			if ((abs(obColour.R - 200) < 50) && (abs(obColour.G - 12) < 15) && (abs(obColour.B - 8) < 8))
				niceBloodCount++;
		}
		//exit(0);
		if (niceBloodCount < 5)
			res = 1;
	}



	return res;

}



int ifNeedToRecoveryBlue(CString Environment, CPoint  * ParameterPoints, struct WindowPosMsg windowMsg)
{
	CString  zuobiao1(_T("over"));
	int res = 0;
	CString str;
	int badcolour = 0;
	int i = 0;
	int j = 0;
	CPoint linPoint;
	struct colourRGB  obColour;
	//struct colourRGB  goodcolour[9];
	CPoint pt;
	int len = 50;
	int niceBuleCount = 0;//记录找到的蓝色条像素的个数
	static  int runCounts = 0;
	static  CPoint  OriginPoint;
	CPoint  ptTMP;
	//exit(0);
	if (Environment.Compare(_T("800600")) == 0 )
	{
		if (runCounts == 0)
		{
			#ifdef  TianYuDeBug
						str.Format(_T("(change  OriginPoint：)"));
						standardOutput(str);
			#endif

			OriginPoint.x = windowMsg.TopLeftPoint.x + 45;
			OriginPoint.y = windowMsg.TopLeftPoint.y + 75;
		}

	}
	else  return res;
	ptTMP.x = OriginPoint.x;
	ptTMP.y = OriginPoint.y;
	#ifdef  TianYuDeBug
		str.Format(_T("(OriginPoint.x =%d,OriginPoint.y =%d)"), OriginPoint.x, OriginPoint.y);
		standardOutput(str);
	#endif
	//首先需要调整蓝条采集点的位置
	//从点（windowMsg.TopLeftPoint.x + 45，windowMsg.TopLeftPoint.y）为起点上下浮动5像素进行搜索
	if (runCounts == 0)
	{

		for (j = 0; j < 5 && niceBuleCount<45; j++)
		{ 
			niceBuleCount = 0;
			//修正 OriginPoint
			OriginPoint.y = ptTMP.y - 2 + j;
			for (i = 0; i < len; i++)
			{
				pt.x = OriginPoint.x + i;
				pt.y = OriginPoint.y ;
				//SetCursorPos(pt.x, pt.y);
				//SetCursorPos(windowMsg.TopLeftPoint.x + 145+50, windowMsg.TopLeftPoint.y + 66);
				GetPointRGB(&pt, &obColour);
				#ifdef  TianYuDeBug
				str.Format(_T("(j=%d,%d,%d,%d)"),j, obColour.R,obColour.G,obColour.B);
				standardOutput( str);
				#endif
				if ((abs(obColour.R - 8) < 15) && (abs(obColour.G - 35) < 20) && (abs(obColour.B - 170) < 50))
					niceBuleCount++;
			}
			#ifdef  TianYuDeBug
			str.Format(_T("niceBuleCount=%d "),  niceBuleCount);
						standardOutput(str);
			#endif
		}

		runCounts = 1;
	}


#ifdef  TianYuDeBug
	str.Format(_T("(new			OriginPoint.x =%d,OriginPoint.y =%d)"), OriginPoint.x, OriginPoint.y);
	standardOutput(str);
#endif
	niceBuleCount = 0;
	//#ifdef  TianYuDeBug
	//SetCursorPos(pt.x, pt.y);
	//str.Format(_T("(%d,%d,%d)"), obColour.R,obColour.G,obColour.B);
	//standardOutput( str);
	//#endif
	for (i = 0; i < len; i++)
	{
		pt.x = OriginPoint.x + i;
		pt.y = OriginPoint.y ;


		GetPointRGB(&pt, &obColour);
#ifdef  TianYuDeBug
		str.Format(_T("(%d,%d,%d---->(%d,%d))"), obColour.R,obColour.G,obColour.B,pt.x,pt.y);
		standardOutput( str);

		SetCursorPos(pt.x, pt.y);
		//SetCursorPos(windowMsg.TopLeftPoint.x + 145+50, windowMsg.TopLeftPoint.y + 66);
#endif			
		if ((abs(obColour.R - 4) < 10) && (abs(obColour.G - 35) < 20) && (abs(obColour.B - 170) < 50))
			niceBuleCount++;
	}
		
	if (niceBuleCount < 20)
		res = 1;
	//zuobiao1.Format(_T("niceBuleCount=%d,j=%d"), niceBuleCount,j);
	//AfxMessageBox(zuobiao1);
	//exit(0);
	#ifdef  TianYuDeBug
	str.Format(_T("niceBuleCount=%d\n\n"), niceBuleCount);
	standardOutput( str);
	#endif	



	return res;
}
/*返回1 表示需要回血*/
int ifNeedToRecoveryBlood(CString Environment, CPoint  * ParameterPoints, struct WindowPosMsg  windowMsg)
{
	int res = 0;
	CString str;
	int badcolour = 0;
	int i = 0;
	int j = 0;
	CPoint linPoint;
	struct colourRGB  obColour;
	//struct colourRGB  goodcolour[9];
	CPoint pt;
	int len = 50;
	CPoint  ptTMP;
	static  int runCounts = 0;
	static  CPoint  OriginPoint;

	int niceBloodCount = 0;//记录找到的红色血条像素的个数

	if (Environment.Compare(_T("800600")) == 0)
	{
		if (runCounts == 0)
		{
			OriginPoint.x = windowMsg.TopLeftPoint.x + 145;
			OriginPoint.y = windowMsg.TopLeftPoint.y + 66;
		}

	}
	else  return res;
	ptTMP.x = OriginPoint.x;
	ptTMP.y = OriginPoint.y;
	if (runCounts == 0)
	{

		for (j = 0; j < 5 && niceBloodCount<45; j++)
		{
			niceBloodCount = 0;
			OriginPoint.y = ptTMP.y - 2 + j;
			for (i = 0; i < len; i++)
			{
				pt.x = OriginPoint.x + i;
				pt.y = OriginPoint.y;
				//SetCursorPos(pt.x, pt.y);
				//SetCursorPos(windowMsg.TopLeftPoint.x + 145+50, windowMsg.TopLeftPoint.y + 66);
				GetPointRGB(&pt, &obColour);
				//str.Format(_T("(%d,%d,%d)"), obColour.R,obColour.G,obColour.B);
				//standardOutput( str);

				if ((abs(obColour.R - 200) < 50) && (abs(obColour.G - 12) < 15) && (abs(obColour.B - 8) < 8))
					niceBloodCount++;
			}

		}

		runCounts = 1;
	}
	niceBloodCount = 0;






	//对于不同的游戏窗口大小有一个全屏和窗口小屏的问题，
	//不过，不同的分辨率全屏的大小也不一样
	//情况如下：1440900          a:全屏模式   b：800*600模式
	//			1280720          a:全屏模式   b：800*600模式
	//所以你可以这样，优先做800*600模式,通过各位置跟左上角的相对位置来做
	//注意你这里的加血指的是自己给自己加血，奶妈给别人加血的情况这里不考虑


		//SetCursorPos(windowMsg.TopLeftPoint.x + 145, windowMsg.TopLeftPoint.y + 66);
		//SetCursorPos(windowMsg.TopLeftPoint.x + 145+50, windowMsg.TopLeftPoint.y + 66);

		//考虑到颜色的不稳定，必须提取足够多的像素才好进行判断
		//判断依据是采集到足够量的像素后判断有多少个接近红色的像素
		//采集的第一个点事（windowMsg.TopLeftPoint.x + 145, windowMsg.TopLeftPoint.y + 66）
		//最后一个点是(windowMsg.TopLeftPoint.x + 145+50, windowMsg.TopLeftPoint.y + 66)
		//做法如下：先收集足够的无血和满血状态下的血条颜色值，比较误差值在一定范围内的差太多的个数
		//当超过%50就可以加血了，超过%90要使劲加血了



		//经过数据采集发现：对面红色血条的rgb取值大致是 195《r《250， g=12，b=8
		//二在黑色血条下情况比较复杂，但总体来说是偏向黑色的（半透明的），所以也会达到120左右的rgb值
		//我们知道，颜色越黑，rgb值越小
		for (i = 0; i < len; i++)
		{
			pt.x = OriginPoint.x + i;
			pt.y = OriginPoint.y;
			GetPointRGB(&pt, &obColour);
			//SetCursorPos(pt.x, pt.y);
			//str.Format(_T("(%d,%d,%d)"), obColour.R,obColour.G,obColour.B);
			//standardOutput( str);

			if ((abs(obColour.R - 200) < 50)  &&  (abs(obColour.G - 12) < 15)      &&    (abs(obColour.B - 8) < 8)  )
				niceBloodCount++;


		}
		//CString  zuobiao1(_T("over"));
		//if (niceBloodCount >35)
		//	zuobiao1.Format(_T("nice blood  niceBloodCount=%d"), niceBloodCount);
		//else if (niceBloodCount >25)
		//	zuobiao1.Format(_T("need add  blood niceBloodCount=%d"), niceBloodCount);
		//else
		//	zuobiao1.Format(_T("bad blood niceBloodCount=%d"), niceBloodCount);
		//AfxMessageBox(zuobiao1);
		//exit(0);
		if (niceBloodCount < 20)
			res = 1;
	



	return res;
}





DWORD WINAPI autoAttack_LingLong(PVOID pvParam)
{
	int res = 0;
	CString fileName;
	//标志当前究竟是哪个角色在打。0是未知。1是玲珑，2是其他
	struct AttackType *t = (struct AttackType *)pvParam;
	int autoAttackType = (int)pvParam;
	//int cccc=(int)autoAttackType;
	if (autoAttackType == 1)
	{
		fileName.Format(_T("C:\\data\\tianyu\\autoAttack.txt"));
	}
	else if (autoAttackType == 2)
	{
		//fileName.Format(_T("D:\\data\\shell\\autoAttackfortangmeng.txt"));
	}
	else{
		CString  zuobiao1(_T(" wrong autoAttackType"));
		AfxMessageBox(zuobiao1);
		return res;
	}
	//读取shell文本

	int count = lineCount(fileName);
	struct operat *p = new struct operat[count];
	int countINFact = ReadTxtToGetShellByName2(fileName, count, p);
	//分析命令
	//就是得出该执行的操作，以及相应的参数
	struct dodo *todo = new struct dodo[countINFact];
	res = haveToDo(countINFact, p, todo);
	//最后检查操作
	if (res <= 0)
	{
		CString  zuobiao1(_T("some wrong"));
		AfxMessageBox(zuobiao1);
		//int res=runShell( countINFact, todo);

	}
	int width = GetSystemMetrics(SM_CXSCREEN);
	int height = GetSystemMetrics(SM_CYSCREEN);

	CString fileName2("C:\\data\\1440900\\zuobiao.txt");
	CPoint  *ParameterPoints;
	CString Environment = for1440and900;

	if (width == 1440 && height == 900)
	{
		fileName2.Format(_T("C:\\data\\1440900\\zuobiao.txt"));
		ParameterPoints = ReadTxtToGetPoints(fileName2);
		Environment = for1440and900;
	}
	else if (width == 1280 && height == 800)
	{
		fileName2.Format(_T("C:\\data\\1280800\\zuobiao.txt"));
		ParameterPoints = ReadTxtToGetPoints(fileName2);
		Environment = for1280and800;
	}
	//else
	//	return res;

	Sleep(4000);
	char c;
	int delyTime;
	int continueAutoAttack = 1;
	int cycle = 0;

	int  qieguai = 1;
	while (continueAutoAttack)
	{
		cycle++;
		if (cycle >= 20)
			cycle = 0;
		if (qieguai >= 10)
			qieguai = 1;
		if (qieguai == 1)
			ToInPutKeyboardKey(9, 100);//切怪
		
		qieguai++;
		//ruguo如果是峨眉那么美循环5次可以加一下血
		//if(cycle == 3  && autoAttackType == 1 )
		//	ToInPutChar('q',500);
		//选怪
		c = 'e';
		delyTime = 500;
		//ToInPutChar(c, delyTime);
		//2：技能释放-
		res = runShell(countINFact, todo);

		/*
		//3：判断是否打死了怪
		*/
		//自动加血蓝内气
		//res=ifNeedToNeiLi(CString Environment,CPoint  * ParameterPoints);
		//int need = ifNeedToNeiLi(Environment, ParameterPoints);
		if (cycle == 19)
		{
			ToInPutKeyboardKey(57, 100);//默认9回内力
			ToInPutKeyboardKey(70, 100);//默认f捡东西

		}
		if (cycle == 19 || cycle == 9)
		{
			ToInPutKeyboardKey(48, 100);//默认0回血

		}
		//need = ifNeedToHuiXue(Environment, ParameterPoints);
		//if (need == 1)
		//{
		//	ToInPutKeyboardKey(VK_F4, 200);//默认f2回内红

		//}

		
	}
	delete[] p;
	delete[] todo;
	return res;
}