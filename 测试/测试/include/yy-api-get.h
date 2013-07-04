//! IYY接口创建
/*! 接口说明
 * @file dw-client-api.h
 * @create date 2011-10-03
 * @modify data 2012-03-29
 * @author simon.lv
 * @version 1.0
 * @modify list
 * ............................................................................
 * ............................................................................
 * 显式创建yy::IYY接口，对外发布
 * 广州华多网络科技有限公司 版权所有 (c) 2005-2011 DuoWan.com [多玩游戏]

 ******************************************************************************
 * 详细接口文档参考open.yy.com
 *******************************************************************************/

#ifndef YY_PLATFORM_SDK_YY_API_GET_H
#define YY_PLATFORM_SDK_YY_API_GET_H

#include "yy-api-client.h"

typedef yy::IYY* (*IYYCREATEFUNC)(void);
#define YYPLATFORM_SDK_DLL_NAME _T("yyplatformsdk.dll")
#define YYPLATFORM_SDK_FUNC_NAME "GetYYOpenInterface"

inline yy::IYY* GetYYApi(unsigned int& err)
{
	HMODULE hModule = ::LoadLibrary(YYPLATFORM_SDK_DLL_NAME);

	if (hModule==NULL)
	{
		err = ::GetLastError();
		return NULL;
	}

	IYYCREATEFUNC pFunc = (IYYCREATEFUNC)::GetProcAddress(hModule, YYPLATFORM_SDK_FUNC_NAME);

	if (pFunc==NULL)
	{
		err = ::GetLastError();
		return NULL;
	}

	return pFunc();
}

#endif
