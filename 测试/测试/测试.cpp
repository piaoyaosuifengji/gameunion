// 测试.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <locale>

#include "yy-api-get.h"
#include "yy-api-client.h"
#include "yy-api-error-codes.h"

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "chs");

	unsigned int uErr = yy_e_unknown;
	yy::IYY *pYY = GetYYApi(uErr);

	if( pYY == NULL )
	{
		printf("GetYYApi failed\r\n");
		return -1;
	}

	// needed!
	pYY->AddRef();
	int ver=pYY->GetVersion();
	// 使用其它接口之前必须Initialize成功
	//YYRESULT nRet = pYY->Initialize();

	//if( nRet != yy_success )
	//{
	//	printf("Initialize Failed with Error NO: %d\r\n", nRet);
	//	return -3;
	//}

	printf("现在可以\"Attach to Process\"了！\r\n");
	printf("按任意键继续……\r\n");
	getchar();

	// a demo to show user info	
	//yy::IUser *pUser = pYY->GetUser();

	

	// TODO: add your test code here

	// release resource
	pYY->Release();

	printf("按任意键退出……");
	getchar();

	return 0;
}

