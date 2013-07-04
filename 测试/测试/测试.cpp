// ����.cpp : �������̨Ӧ�ó������ڵ㡣
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
	// ʹ�������ӿ�֮ǰ����Initialize�ɹ�
	//YYRESULT nRet = pYY->Initialize();

	//if( nRet != yy_success )
	//{
	//	printf("Initialize Failed with Error NO: %d\r\n", nRet);
	//	return -3;
	//}

	printf("���ڿ���\"Attach to Process\"�ˣ�\r\n");
	printf("���������������\r\n");
	getchar();

	// a demo to show user info	
	//yy::IUser *pUser = pYY->GetUser();

	

	// TODO: add your test code here

	// release resource
	pYY->Release();

	printf("��������˳�����");
	getchar();

	return 0;
}

