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


		ToInPutKeyboardKey(0x46, 100);//����
		Sleep(7000);

	}
	return res;
}
DWORD WINAPI autoAttack_LingLongZuDui(PVOID pvParam)
{
	int res = 0;
	CString fileName;
	int  firstRun = 1;//ѭ����־����һ�ν���ѭ���������޸�
	//��־��ǰ�������ĸ���ɫ�ڴ�0��δ֪��1�����磬2�����飬2������
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
	//��ȡshell�ı�

	int count = lineCount(fileName);
	struct operat *p = new struct operat[count];
	int countINFact = ReadTxtToGetShellByName2(fileName, count, p);
	//��������
	//���ǵó���ִ�еĲ������Լ���Ӧ�Ĳ���
	struct dodo *todo = new struct dodo[countINFact];
	res = haveToDo(countINFact, p, todo);
	//��������
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
	//�����ж���Ϸ���ڴ�С�������800*600�Ͳ�Ҫ��pc�ķֱ�����
	//ʵ�ʵõ�����816*638
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

	ToInPutKeyboardKey(9, 100);//�й�
	while (continueAutoAttack)
	{
		cycle++;
		if (cycle >= 30)
			cycle = 0;
		if (qieguai >= 10)	
			qieguai = 1;
		if (qieguai == 10)
			ToInPutKeyboardKey(0x46, 100);//����

		qieguai++;
		//ruguo����Ƕ�ü��ô��ѭ��5�ο��Լ�һ��Ѫ
		//if(cycle == 3  && autoAttackType == 1 )
		//	ToInPutChar('q',500);
		//ѡ��
		c = 'e';
		delyTime = 500;
		//ToInPutChar(c, delyTime);
		//2�������ͷ�-
		

		/*
		//3���ж��Ƿ�����˹�
		*/

		need = ifNeedToFindNewMonster(Environment, ParameterPoints, windowMsg);
		if (need == 1)
		{
			ToInPutKeyboardKey(9, 100);//�й�
			OutputDebugString(_T("�й� \n"));
		//fight

		}
		res = runShell(countINFact, todo);
		OutputDebugString(_T("fight over \n"));

		//addBlueFlag
		//��ʱ��������Ϊ�����´��������Ϊ�˱����������������������Ҫ�������η�����Ҫ�����ŵ��ü�������
		need = ifNeedToRecoveryBlue(Environment, ParameterPoints, windowMsg);
		if (need == 1 && addBlueFlag == 1)
		{
			addBlueFlag = 0;
			OutputDebugString(_T("need  add  Blue \n"));
			//AfxGetMainWnd()->SetWindowText(_T("need  add  blood"));
			ToInPutKeyboardKey(57, 100);//Ĭ��9����
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

			if (autoAttackType == 1)//��������谴3��Ѫ
			{
				ToInPutKeyboardKey(52, 100);//Ĭ��0��Ѫ
			}
			else 
				ToInPutKeyboardKey(48, 100);//Ĭ��0��Ѫ
			//ToInPutKeyboardKey(51, 100);//Ĭ��0��Ѫ
		}
		else OutputDebugString(_T("do not need  add  blood \n"));

		/*
		ifNeedToHuiXue��˼·��
		1���ҵ���Ϸ�Ĵ���
		2:ȷ��Ѫ��λ��
			������a:�ֲڵ�ָ�����꣬�򵥶���Ч�����Ǿ�����̫�󣬲������������ǵ�ʹ�����ְ취��
					���������ָ���������ι���ʱ�����������ģʽ�������ޱ߿�
				  b��ͨ��Ѱ�ҿؼ��ķ�ʽ��ֵ��һ��---��ʱʧ��
				  c��ͨ������ͼ��ķ�ʽ���Ѷȴ�
		3��ȷ����Ѫ�ı�׼��ʲô����¼�Ѫ
		4��ȷ����Ѫ�Ķ��󣺸��Լ����Ǹ����ˣ��������У�
		5����Ѫ
		*/

		//�������������Ҫ�ж��Ƿ�Ҫ���������Ѽ�Ѫ��
		if (autoAttackType == 1)
		{ 

			//���Լ���һЩ״̬��
			if (cycle == 1 || cycle == 15)
			{
				ToInPutKeyboardKey(56, 0);

			}

			//�����ж��ж��ٶ���
			//��һ�����е�ʱ���жϣ�
			if (firstRun == 1)
			{
				//���ǵÿ���ѯ��ɫ���жϣ���Ȼ������ȱ�ݵģ��ܻ���Ӱ��
				//�Ҳ�����ʵ�㲢����Ҫ֪�������ж��ٶ��Ѱ���ֻҪĬ����4������
				//һ����ѡ��������Ѫ�ͼӾͺ��˰�.....
			}

			//exit(0);
			//�����ж�
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

					//�����㹻���̣�
					ToInPutKeyboardKey(53, 10);
					ToInPutKeyboardKey(52, 10);
					ToInPutKeyboardKey(55, 10);
				}
				

			}
			//�����й֣�

			ToInPutKeyboardKey(9, 100);//�й�
		}


		if (autoAttackType == 2)
		{
			//���Լ���һЩ״̬��
			if (cycle == 1 || cycle == 15)
			{
				ToInPutKeyboardKey(VK_OEM_PLUS, 10);  //�Ӻ�
				ToInPutKeyboardKey(VK_OEM_MINUS, 10);//����
			}



		}
		firstRun = 0;
	}
	delete[] p;
	delete[] todo;
	return res;
}
//�ж������Ƿ���Ҫ�����Ѽ�Ѫ������0���ã�����1.2.3.4��ֱ����Ӧλ�ö��Ѽ�Ѫ
//ͨ����ݼ�ֱ��ѡ�����,�Ҳ�
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
			//������������ң�����ʵû��Ҫ,���ǿ��ǵ�Ұ�ֿ�Ѫ��Ѫ����
			//�������ҿۣ����ԣ�ʵ���ϣ��㿴��ע�ұ߰��Ѫ��
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
//ֻ��������ͨ�֣���boss��Ч����û��ϵ����bossʱ����Ҫ�й�
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
			//������������ң�����ʵû��Ҫ,���ǿ��ǵ�Ұ�ֿ�Ѫ��Ѫ����
			//�������ҿۣ����ԣ�ʵ���ϣ��㿴��ע�ұ߰��Ѫ��
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
	int niceBuleCount = 0;//��¼�ҵ�����ɫ�����صĸ���
	static  int runCounts = 0;
	static  CPoint  OriginPoint;
	CPoint  ptTMP;
	//exit(0);
	if (Environment.Compare(_T("800600")) == 0 )
	{
		if (runCounts == 0)
		{
			#ifdef  TianYuDeBug
						str.Format(_T("(change  OriginPoint��)"));
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
	//������Ҫ���������ɼ����λ��
	//�ӵ㣨windowMsg.TopLeftPoint.x + 45��windowMsg.TopLeftPoint.y��Ϊ������¸���5���ؽ�������
	if (runCounts == 0)
	{

		for (j = 0; j < 5 && niceBuleCount<45; j++)
		{ 
			niceBuleCount = 0;
			//���� OriginPoint
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
/*����1 ��ʾ��Ҫ��Ѫ*/
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

	int niceBloodCount = 0;//��¼�ҵ��ĺ�ɫѪ�����صĸ���

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






	//���ڲ�ͬ����Ϸ���ڴ�С��һ��ȫ���ʹ���С�������⣬
	//��������ͬ�ķֱ���ȫ���Ĵ�СҲ��һ��
	//������£�1440900          a:ȫ��ģʽ   b��800*600ģʽ
	//			1280720          a:ȫ��ģʽ   b��800*600ģʽ
	//���������������������800*600ģʽ,ͨ����λ�ø����Ͻǵ����λ������
	//ע��������ļ�Ѫָ�����Լ����Լ���Ѫ����������˼�Ѫ��������ﲻ����


		//SetCursorPos(windowMsg.TopLeftPoint.x + 145, windowMsg.TopLeftPoint.y + 66);
		//SetCursorPos(windowMsg.TopLeftPoint.x + 145+50, windowMsg.TopLeftPoint.y + 66);

		//���ǵ���ɫ�Ĳ��ȶ���������ȡ�㹻������زźý����ж�
		//�ж������ǲɼ����㹻�������غ��ж��ж��ٸ��ӽ���ɫ������
		//�ɼ��ĵ�һ�����£�windowMsg.TopLeftPoint.x + 145, windowMsg.TopLeftPoint.y + 66��
		//���һ������(windowMsg.TopLeftPoint.x + 145+50, windowMsg.TopLeftPoint.y + 66)
		//�������£����ռ��㹻����Ѫ����Ѫ״̬�µ�Ѫ����ɫֵ���Ƚ����ֵ��һ����Χ�ڵĲ�̫��ĸ���
		//������%50�Ϳ��Լ�Ѫ�ˣ�����%90Ҫʹ����Ѫ��



		//�������ݲɼ����֣������ɫѪ����rgbȡֵ������ 195��r��250�� g=12��b=8
		//���ں�ɫѪ��������Ƚϸ��ӣ���������˵��ƫ���ɫ�ģ���͸���ģ�������Ҳ��ﵽ120���ҵ�rgbֵ
		//����֪������ɫԽ�ڣ�rgbֵԽС
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
	//��־��ǰ�������ĸ���ɫ�ڴ�0��δ֪��1�����磬2������
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
	//��ȡshell�ı�

	int count = lineCount(fileName);
	struct operat *p = new struct operat[count];
	int countINFact = ReadTxtToGetShellByName2(fileName, count, p);
	//��������
	//���ǵó���ִ�еĲ������Լ���Ӧ�Ĳ���
	struct dodo *todo = new struct dodo[countINFact];
	res = haveToDo(countINFact, p, todo);
	//��������
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
			ToInPutKeyboardKey(9, 100);//�й�
		
		qieguai++;
		//ruguo����Ƕ�ü��ô��ѭ��5�ο��Լ�һ��Ѫ
		//if(cycle == 3  && autoAttackType == 1 )
		//	ToInPutChar('q',500);
		//ѡ��
		c = 'e';
		delyTime = 500;
		//ToInPutChar(c, delyTime);
		//2�������ͷ�-
		res = runShell(countINFact, todo);

		/*
		//3���ж��Ƿ�����˹�
		*/
		//�Զ���Ѫ������
		//res=ifNeedToNeiLi(CString Environment,CPoint  * ParameterPoints);
		//int need = ifNeedToNeiLi(Environment, ParameterPoints);
		if (cycle == 19)
		{
			ToInPutKeyboardKey(57, 100);//Ĭ��9������
			ToInPutKeyboardKey(70, 100);//Ĭ��f����

		}
		if (cycle == 19 || cycle == 9)
		{
			ToInPutKeyboardKey(48, 100);//Ĭ��0��Ѫ

		}
		//need = ifNeedToHuiXue(Environment, ParameterPoints);
		//if (need == 1)
		//{
		//	ToInPutKeyboardKey(VK_F4, 200);//Ĭ��f2���ں�

		//}

		
	}
	delete[] p;
	delete[] todo;
	return res;
}