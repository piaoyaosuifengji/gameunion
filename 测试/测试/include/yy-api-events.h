//!! IYY SDK event  定义
/*! 接口说明 platform api 事件 接口, 使用者继承对应的Event接口实现之，注册到指定的接口
	注意多线环境，event 只会在APi初始化线程返回 ，建议在UI线程初始化API
 * @file dw-api-events.h
 * @create date 2011-12-01
 * @modify data 2011-12-01
 * @author simon.lv
 * @version 1.0
 * @modify list
 * ............................................................................
 * ............................................................................
 * yy open platform client api, 基于异步的yyplatform 网络通信协议
 * 广州华多网络科技有限公司 版权所有 (c) 2005-2011 DuoWan.com [多玩游戏]

 ******************************************************************************
 * 详细接口文档参考open.yy.com
 *******************************************************************************/

#ifndef _DW_PLATFORM_API_EVENTS_H_
#define _DW_PLATFORM_API_EVENTS_H_

#include "yy-api-types.h"

namespace yy
{

extern "C"
{
	//![event] 用户事件
	struct IUserEvent
	{
		//!用户信息改变
		/*!
		 * \param info [in] ,改变后的用户信息
		*/
		virtual void OnUserInfoChanged(IUserInfo *info) = 0;
	};
	
	//![event] 频道信息获取回调接口
	struct IChannelEvent
	{
		//!子频道跳转时产生
		/*!
		 * \param unsigned int departed_id [in] ,原来子频道id
		 * \param unsigned int now_id	[in]	,现在子频道id
		*/
		virtual void OnFocusChannelChannged(unsigned int departed_id, unsigned int now_id) = 0;

		//!当频道信息改变时产生事件
		/*! 
		* \param IChannelInfo *info[in] ,改变后的频道信息
		*/
		virtual void OnChannelInfoChannged(IChannelInfo *info) = 0;

		//!删除子频道时产生事件
		/*!
		* \param unsigned int cid [in], 子频道id
		*/
		virtual void OnSubChannelDel(unsigned int cid) = 0;

		//!添加子频道时产生事件
		/*!
		 * \param unsigned int cid [in], 新增的子频道id，
		 * \param unsigned int pcid [in], 父频道id
		*/
		virtual void OnSubChannelAdd(unsigned int cid, unsigned int pcid) = 0;

		//!添加子频道时产生事件
		/*!
		 * \param unsigned int cid [in], 新增的子频道id，
		 * \param unsigned int pcid [in], 父频道id
		*/
		virtual void OnUserEnterChannel(unsigned int uid, unsigned int cid) = 0;

		//!添加子频道时产生事件
		/*!
		* \param unsigned int cid [in], 新增的子频道id，
		* \param unsigned int pcid [in], 父频道id
		*/
		virtual void OnUserLeaveChannel(unsigned int uid, unsigned int cid) = 0;
	};
	
	//![event] 语音设备更换事件
	struct IAudioEvent
	{
		//!录音错误回调通知
		/*!
		* \param int err_code [in], 录音错误代码，参考错误代码表
		*/
		virtual void OnRecordErr(int err_code) = 0;
	    
		//!录音完成回调通知
		/*!
		* \param int result [in], 录音结果
		* \param const char *file_name[in],录音文件名
		*/
		virtual void OnRecordFinished(int result, const char *file_name) = 0;
	};

	//![event] 频道用户列表右键菜单事件通知 
	struct IChannelUserPopMenuEvent
	{
		//!右键用户菜单事件
		/*!
		* \param unsigned int uid [in], 用户id
		* \param unsigned int cid [in], 用户所在频道id
		*/
		virtual void OnClicked(unsigned int uid, unsigned int cid) = 0;
	};

	//![event] 网络状态回调 
	struct INetEvent
	{
		//!连接回调
		/*!
		* \param int result [in],连接结果代码, 0:success ,其他值 error, 参考DWApi错误代码表
		*/
		virtual void OnConnected(int result) = 0;
		
		//!断开后回调
		/*!
		* \param int result, 0:主动断开, 其他值error, 误参考 DWApi错误代码表
		*/
		virtual void OnClosed(int result) = 0;

    //!收到广播数据包
		/*!
		* \param const char *data	[in], 收到数据包地址
		* \param unsigned int size	[in], 收到数据包的大小
		*/
		virtual void OnRecv(const char *data, unsigned int size) = 0;
	};

	//![event]应用消息事件
	struct IChannelAppLinkEvent
	{
		//!链接点击事件
		/*!
		* \param unsigned int token 	[in],链接消息用户自定义值
		*/
        virtual void OnAppLinkClicked(unsigned int token) = 0;
	};
	
	//![event]麦序相关列表事件
	//!当前所在子频道 用户上下麦序和清空麦序，以及某人移动麦序的事件
	struct IMicListEvent 
	{
		//!有人加入麦序
		/*!
		* \param unsigned int uid [in], 加入麦序用户的id
		*/
	    virtual void OnUserJoin(unsigned int uid) = 0;
		
		//!有人离开麦序
		/*!
		* \param unsigned int uid [in], 下麦用户的id
		*/
		virtual void OnUserLeave(unsigned int uid) = 0;
		
		//!麦序上的人移动
		/*!
		* \param unsigned int uid,麦序移动的用户的id
		* \param unsigned int after_uid,移动到某个用户后面的id
		*/
		virtual void OnUserMove(unsigned int uid, unsigned int after_uid) = 0;
		
		//!清空麦序事件
		/*! 
		*/
		virtual void OnClear() = 0;
	};
	
	//![event] 频道子窗口事件
	struct IChannelSubWindowEvent
	{
		//!子频道窗口显示事件
		/*!
		 * \param unsigned int x [in], 子频道窗口x坐标
		 * \param unsigned int y [in], 子频道窗口y坐标
		 * \param unsigned int width [in], 子频道窗口宽度
		 * \param unsigned int height [in], 子频道窗口高度
		*/
		virtual void OnShow(unsigned int x, 
			unsigned int y,
			unsigned int width,
			unsigned int height) = 0;
		
		//!子频道窗口隐藏事件
		virtual void OnHide() = 0;
		
		//!子频道窗口大小改变事件
		/*!
		 * \param unsigned int x [in], 子频道窗口x坐标
		 * \param unsigned int y [in], 子频道窗口y坐标
		 * \param unsigned int width [in], 子频道窗口宽度
		 * \param unsigned int height [in], 子频道窗口高度
		*/
		virtual void OnSizeChannel(unsigned int x, 
			unsigned int y,
			unsigned int width,
			unsigned int height) = 0;
	};
}

}
#endif //!_DW_PLATFORM_API_EVENTS_H_