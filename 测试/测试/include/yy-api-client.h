//! IYY SDK 同步接口
/*! 接口说明
 * @file dw-client-api.h
 * @create date 2011-10-03
 * @modify data 2011-11-30
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

#ifndef _DW_OPENPLATFORM_CLIENT_API_H_
#define _DW_OPENPLATFORM_CLIENT_API_H_

#include "yy-api-types.h"
#include "yy-api-events.h"

namespace yy
{

	extern "C"
	{
		struct IAudio;
		struct IUser;
		struct IChannel;
		struct INet;
		struct IIM;
		struct ICloud;
		struct IChannelAppMsg;

		//![interface] 多玩yy客户端接口
		//!客户端所有接口入口
		struct IYY : public IYYUnk
		{
			//!获取用户接口
			/*!
			* \return IUser*, success返回有效指针，error返回NULL
			 */
			virtual IUser * GetUser() = 0;

			//!获取频道接口
			/*!
			* \return IChannel*, success返回有效指针，error返回NULL
			*/
			virtual IChannel * GetChannel() = 0;

			//!获取IM接口
			/*!
			*\return IIM*, success返回有效指针，error返回NULL
			*/
			virtual IIM * GetIM() = 0;

			//!获取语音接口
			/*!
			* \return IAudio*, success返回有效指针，error返回NULL
			*/
			virtual IAudio * GetAudio() = 0;

			//!获取网络接口
			/*!
			* \return INet*, success返回有效指针，error返回NULL
			*/
			virtual INet * GetNet() = 0;

			//!获取云存储接口
			/*!
			* \return ICloudData*, success返回有效指针，error返回NULL
			*/
			virtual ICloud * GetCloud() = 0;
			
			//!获取sdk 版本信息
			/*!
			 * \return int, sdk 版本信息
			*/
			virtual int GetVersion() = 0;
		};

		//! [interface] 用户接口
		//! 用户相关接口 入口接口，包括获取当前的用户的信息，根据uid获取频道内的某个用户的基本信息，以及用户信息改变的基本事件
		struct IUser
		{
			//!获取当前用户信息
			/*! 
			/* \return IUserInfo*, success有效指针,error为NULL
			*/
			virtual IUserInfo * GetCurrnetUserInfo() = 0;

			//!根据uid获取当前用户信息
			/*!
			* \param unsigned int [in] 用户id
			* \return IUserInfo*, success有效指针,error为NULL
			*/
			virtual IUserInfo * GetUserInfo(unsigned int uid) = 0;

			//!注册用户事件
			/*!
			* \param IUserEvent* [in] 有效的用户事件指针
			* \return int, 0 success ,其他值 error,参考错误代码表
			*/
			virtual int RegisterUserEvent(IUserEvent *e) = 0;

			//!反注册 用户事件
			/*!
			* \param IUserEvent* [in] 有效的用户事件指针
			* \return int, 0 success ,其他值 error,参考错误代码表
			*/
			virtual int UnRegisterUserEvent(IUserEvent *e) = 0;
		};

		//![interface] 频道右键菜单接口
		//!频道用户列表右键菜单设置 和取消设置 和对应的菜单事件设置
		struct IChannelUserListPopMenu
		{
			//!设置频道用户右键菜单
			/*!
			* \param [in] char* 显示在右键菜单字符串
			* \param [in] int   右键菜单显示字符串长度 最大长度 20
			* \return int, 0 success ,其他 值error,参考错误代码表
			*/
			virtual int SetPopMenu(const char *str, 
					unsigned int size) = 0;

			//!取消设置频道用户右键菜单
			/*!
			* \return int, 0 success ,其他 值error,参考错误代码表
			*/
			virtual int UnSetPopMemu() = 0;

			//!注册频道右键菜单事件
			/*!
			* \param [in] IChannelUserPopMenuEvent* e,有效的右键菜单事件指针
			* \return int, 0 success ,其他 值error,参考错误代码表
			*/
			virtual int RegisterPopMenuEvent(IChannelUserPopMenuEvent * e) = 0;

			//!反注册频道右键菜单事件
			/*!
			* \param IChannelUserPopMenuEvent* [int] 有效的右键菜单事件指针
			* \return int, 0 success ,其他 值error,参考错误代码表
			*/
			virtual int UnRegisterPopMenuEvent(IChannelUserPopMenuEvent * e) = 0;
		};

		//![interface] 应用消息接口
		//!该消息在频道内的公告栏下方出现一栏可点击的连接的文字信息，支持发送到指定的子频道所有人，和指定用户 的 接口入库
		struct IChannelAppMsg
		{
			//!发送应用消息
			/*!
			* \param unsigned int sub_channel_id, 子频道id
			* \param const char* view_str [in],显示字符串
			* \param unsigned size [in], 显示字符串的大小 最大长度 [100]
			* \param unsigned int  [in], 显示字符串中的链接首位置
			* \param unsigned int link_end_pos [in], 显示字符创的链接结束位置 //!eg. view_str :"my app link" 链接 link字符,link_begin_pos: 7, link_end_pos:10
			* \param unsigned int cookie [in], 自定义数据
			* \return int, 0 success ,其他值 error,参考错误代码表
			*/
			virtual int SendMsgToSubChannel(unsigned int sub_channel_id,
				const char *view_str,
				unsigned int link_begin_pos,
				unsigned int link_end_pos,
				unsigned int cookie) = 0;

			//!发送应用消息
			/*!
			* \const unsigned int *users, 用户数组首地址
			* \const unsigned int size, 用户数组数量
			* \param const char* view_str [in],显示字符串
			* \param unsigned size [in], 显示字符串的大小 最大长度 [100]
			* \param unsigned int  [in], 显示字符串中的链接首位置
			* \param unsigned int link_end_pos [in], 显示字符创的链接结束位置 //!eg. view_str :"my app link" 链接 link字符,link_begin_pos: 7, link_end_pos:10
			* \param unsigned int cookie [in], 自定义数据
			* \return int, 0 success ,其他值 error,参考错误代码表
			*/
			virtual int SendMsgToUsers(const unsigned int *users, 
				unsigned int size,
				const char *view_str,
				unsigned int link_begin_pos,
				unsigned int link_end_pos,
				unsigned int cookie) = 0;

			//!注册频道应用消息事件
			/*!
			* \param [in] IChannelUserPopMenuEvent* e,有效的右键菜单事件指针
			* \return int, 0 success ,其他值 error,参考错误代码表
			*/
			virtual int RegisterChannelAppLinkEvent(IChannelAppLinkEvent *e) = 0;

			//!反注册频道应用消息事件
			/*!
			* \param [in] IChannelUserPopMenuEvent* e,有效的右键菜单事件指针
			* \return int, 0 success ,其他值 error,参考错误代码表
			*/
			virtual int UnRegisterChannelAppLinkEvent(IChannelAppLinkEvent *e) = 0;
		};

		//![interface] 麦序接口
		//!获取麦序列表，注册麦序变化事件相关
		struct IChannelMicList
		{
			//!获取麦序列表
			/*!
			* \return IMicListItem * ,有效指针 success，error返回NULL
			*/
			virtual const IMicListItem * GetMicList() = 0;

			//!注册频道麦序事件
			/*!
			* \param [in] IMicListEvent* e,有效的右键菜单事件指针
			* \return int, 0 success ,其他值 error,参考错误代码表
			*/
			virtual int RegisterMicListEvent(IMicListEvent *e) = 0;

			//!反注册频道麦序事件
			/*!
			* \param [in] IMicListEvent* e,有效的右键菜单事件指针
			* \return int, 0 success ,其他值 error,参考错误代码表
			*/
			virtual int UnRegisterMicListEvent(IMicListEvent *e) = 0;
		};

		//![interface] 频道子窗口 
		//!在频道的中间打开一个子窗口，用于应用自定义UI，在创建窗口成功后，可以接受窗口大小改变，和显示隐藏的事件
		struct IChannelSubWindow
		{
			//!创建频道内嵌窗口
			/*!
			* \param unsigned long &h [inout], Window HANDLE 引用
			* \param unsigned int &x [inout], 子窗口 x 位置
			* \param unsigned int &y [inout], 子窗口 y 位置
			* \param unsigned int &width [inout], 子窗口 宽
			* \param unsigned int &height [inout], 子窗口  高
			* \param bool &visible [inout], 是否显示
			* \return int, 0	success,其他值 error，查看错误代码表
			*/		
			virtual int CreateSubWindow(unsigned long &h, 
				unsigned int &x, 
				unsigned int &y, 
				unsigned int &width, 
				unsigned int &height,
				bool &visible) = 0;

			//!关闭内嵌窗口
			/*!
			* \return int, 0 success,其他值 error，查看错误代码表
			*/
		virtual int CloseSubWindow() = 0;
			
			//!注册频道事件
			/*!
			* \param IChannelSubWindowEvent * e [in] [not NULL]
			* \return int, 0	success,其他值 error，查看错误代码表
			*/
			virtual int RegisterChannelSubWinEvent(IChannelSubWindowEvent *e) = 0;
			
			//!反注册频道事件
			/*!
			* \param IChannelSubWindowEvent * e [in] [not NULL]
			* \return int, 0	success,其他值 error，查看错误代码表
			*/
			virtual int UnRegisterChannelSubWinEvent(IChannelSubWindowEvent *e) = 0;
		};

		//![interface] 频道接口
		//!获取频道相关接口的入口，其中包括频道信息，子频道信息，麦序接口，频道子窗口接口，频道应用消息接口，频道信息 
		struct IChannel
		{
			//!获取当前子频道信息
			/*!
			* \return IChannelInfo *, error NULL
			*/
			virtual IChannelInfo * GetCurrentSubChannelInfo() = 0;

			//!获取大频道信息
			/*!
			* \return IChannelInfo *, error NULL
			*/
			virtual IChannelInfo * GetCurrentChannelInfo() = 0;

			//!通过频道id获取频道信息
			/*!
			* \param unsigned int cid [in],频道或者子频道id
			* \return IChannelInfo *, error NULL
			*/
			virtual IChannelInfo * GetChannelInfo(unsigned int cid) = 0;

			//!获取频道树接口
			/*!
			* \return IChannelNode *, error NULL
			*/
			virtual const IChannelNode * GetChannelTree() = 0;

			//!获取麦序接口
			/*!
			* \return IChannelMicList *,error NULL
			*/
			virtual IChannelMicList * GetMicList() = 0;

			//!获取右键菜单接口
			/*!
			* \return IChannelUserListPopMenu *, error NULL
			*/
			virtual IChannelUserListPopMenu *GetUserListPopMenu() = 0; 
			
			//!获取频道消息接口
			/*!
			* \return IChannelAppMsg *, error NULL
			*/
			virtual IChannelAppMsg * GetAppMsg() = 0;
			
			//!获取频道子窗口接口
			/*!
			* \return IChannelSubWindow *, error NULL
			*/
			virtual IChannelSubWindow * GetSubWin() = 0;
		
			//!注册频道事件
			/*!
			* \param IChannelEvent * e, [in] [not NULL]
			* \return int, 0 success, 其他值 error,参考错误代码表
			*/
			virtual int RegisterChannelEvent(IChannelEvent *e) = 0;

			//!反注册频道事件
			/*!
			* \param IChannelEvent * e [in] [not NULL]
			* \return int, 0	success,其他值 error，查看错误代码表
			*/
			virtual int UnRegisterChannelEvent(IChannelEvent *e) = 0;
		};

		//![interface] IM接口
		//!提供根据uid弹出聊天信息窗口功能，后续是马上提供是否是好友，增加好友的接口
		struct IIM
		{
			//!弹出IM对话框,只支持发送到当前好友
			/*!
			* \param int uid [in],用户唯一id
			* \param const char * [in], 聊天信息
			* \param unsigned int size [in], 信息长度 值范围(0, 40]
			* \return int, 0 success, 其他值 error,参考错误代码表
			*/
			virtual int ChatTo(unsigned int uid, const char *msg, unsigned int size) = 0;
		};

		//![interface] 语音接口 
		//!提供录音功能，和录音事件
		struct IAudio
		{
			//!开始录音
			/*!
			* \param const char *file_name [in],录音保存文件名
			* \return int, 0 success, 其他值 error,参考错误代码表
			*/
			virtual int StartRecord(const char *file_name) = 0;
		    
			//!停止录音
			/*!
			* \return int, 0 success, 其他值 error,参考错误代码表
			*/
			virtual int StopRecord() = 0;

			//!注册音频设备更改回调
			/*!
			* \param IAudioEvent *e, [Not NULL]
			* \return int, 0 success 其他值 error 参考错误代码表
			*/
			virtual int RegisterAudioEvent(IAudioEvent *e) = 0;

			//!反注册IAudioDeviceChangedEvent
			/*!
			* \return int ,0 success，其他值 error 参考错误代码表
			*/
			virtual int UnRegisterAudioEvent(IAudioEvent *e) = 0;
		};

		//![interface]网络接口
		//!提供连接yy，断开yy，广播数据到当前频道所有的人，广播数据到指定的子频道，广播数据到指定的用户，和广播事件
		//!注意：只有当前的应用开启状态才能收到广播数据
		struct INet
		{
			//!连接到平台
			/*!
			* \return int, 0 success，其他值 error，参考错误代码表,在获取到IYY 接口之后必须在5秒之内连接上，否则连接会失效。
			*/
			virtual int Connect() = 0;

			//!主动断开
			/*!
			* \return int, 0 success，其他值 error，参考错误代码表
			*/
			virtual int Close() = 0;

			//!子频道数据广播
			/*!
			* \param unsigned int sub_channel_id [in], 子频道id,
			* \param const char *data [in], 广播数据流 开始地址
			* \param unsigned int size [in], 广播数据流大小， 值范围(0, 4096]
			* \return int, 0 success，其他值 error，参考错误代码表
			*/
			virtual int BroadcastToSubChannel(unsigned int sub_channel_id, const char *data, unsigned int size) = 0;
		    
			//!全频道数据广播
			/*!
			* \param const char *data [in], 广播数据流 开始地址
			* \param unsigned int size [in], 广播数据流大小 值范围(0, 4096] 
			* \return int, 0 success，其他值 error，参考错误代码表
			*/
			virtual int BroadcastToAllChannel(const char *data, unsigned int size) = 0;
			
			//!广播到指定用户
			/*!
			* \param const char *data [in], 广播数据流 开始地址
			* \param unsigned int size [in], 广播数据流大小 值范围(0, 4096] 
			* \param int *u_array [in], 用户数组 开始地址
			* \param unsigned int count [in], 用户数组大小 值范围(0, 100] 
			* \return int, 0 success，其他值 error，参考错误代码表
			*/
			virtual int BroadcastToUsers(const char *data, unsigned int size, unsigned int *u_array, unsigned int count) = 0;
			
			//!注册网络回调
			/*!
			* \param INetEvent *e [in],网络事件
			* \return int, 0 注册success,其他值error,参考错误代码表
			*/
			virtual int RegisterNetEvent(INetEvent *e) = 0;

			//!反注册INetStateEvent 
			/*!
			* \return int, 0 success，其他值error 参考错误代码表
			*/
			virtual int UnRegisterNetEvent(INetEvent *e) = 0;
		};

		//![interface]云存储数据服务
		//!提供简单的数据存储，和操作能力，可以存储两个int，一个字符串，一个2进制流
		//!当前频道的数据只有橙马和紫马具备修改所有数据的能力，其他人一律只能修改自己的数据
		struct ICloud
		{
			//!增加数据
			/*!
			* \param ICloudData *data [in],云存储数据，必须设置值，否则无效
			* \return unsigned int, 0 success, 其他值 error, 参考错误代码表
			*/
			virtual unsigned __int64 AddData(ICloudData *data) = 0;

			//!修改数据
			/*!
			* \param ICloudData *data 云存储数据 ，必须设置值，否则无效
			* \param ICloudFilter *filter ,云存储过滤器，设置条件和条件值
			* \return int, 0 success, 其他值 error，参考错误代码表
			*/
			virtual int UpdateData(ICloudData *data, ICloudFilter *filter) = 0;
			
			//!删除数据
			/*!
			* \param ICloudFilter *filter [in],云存储过滤器，设置条件和条件值
			* \return int, 0 success, 其他值 error，参考错误代码表
			*/
			virtual int DeleteData(ICloudFilter *filter) = 0;

			//!查询数据
			/*!
			* \param ICloudDataList *filter [in],云存储过滤器，设置条件和条件值
			* \return ICloudDataList, 返回查询数据结构
			*/
			virtual ICloudDataList * QueryData(ICloudFilter *filter) = 0;

			//!创建云存储数据
			/*!
			* \return ICloudData *, success返回有效指针，error返回NULL
			*/
			virtual ICloudData * CreateCloudData() = 0;

			//!创建数据过滤器
			/*!
			* \return ICloudFilter *, success返回有效指针，error返回NULL
			*/
			virtual ICloudFilter * CreateCloudFilter() = 0;
		};
	}
}

#endif //!_DW_OPENPLATFORM_CLIENT_API_H_
