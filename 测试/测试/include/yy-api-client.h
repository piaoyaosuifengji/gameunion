//! IYY SDK ͬ���ӿ�
/*! �ӿ�˵��
 * @file dw-client-api.h
 * @create date 2011-10-03
 * @modify data 2011-11-30
 * @author simon.lv
 * @version 1.0
 * @modify list
 * ............................................................................
 * ............................................................................
 * yy open platform client api, �����첽��yyplatform ����ͨ��Э��
 * ���ݻ�������Ƽ����޹�˾ ��Ȩ���� (c) 2005-2011 DuoWan.com [������Ϸ]

 ******************************************************************************
 * ��ϸ�ӿ��ĵ��ο�open.yy.com
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

		//![interface] ����yy�ͻ��˽ӿ�
		//!�ͻ������нӿ����
		struct IYY : public IYYUnk
		{
			//!��ȡ�û��ӿ�
			/*!
			* \return IUser*, success������Чָ�룬error����NULL
			 */
			virtual IUser * GetUser() = 0;

			//!��ȡƵ���ӿ�
			/*!
			* \return IChannel*, success������Чָ�룬error����NULL
			*/
			virtual IChannel * GetChannel() = 0;

			//!��ȡIM�ӿ�
			/*!
			*\return IIM*, success������Чָ�룬error����NULL
			*/
			virtual IIM * GetIM() = 0;

			//!��ȡ�����ӿ�
			/*!
			* \return IAudio*, success������Чָ�룬error����NULL
			*/
			virtual IAudio * GetAudio() = 0;

			//!��ȡ����ӿ�
			/*!
			* \return INet*, success������Чָ�룬error����NULL
			*/
			virtual INet * GetNet() = 0;

			//!��ȡ�ƴ洢�ӿ�
			/*!
			* \return ICloudData*, success������Чָ�룬error����NULL
			*/
			virtual ICloud * GetCloud() = 0;
			
			//!��ȡsdk �汾��Ϣ
			/*!
			 * \return int, sdk �汾��Ϣ
			*/
			virtual int GetVersion() = 0;
		};

		//! [interface] �û��ӿ�
		//! �û���ؽӿ� ��ڽӿڣ�������ȡ��ǰ���û�����Ϣ������uid��ȡƵ���ڵ�ĳ���û��Ļ�����Ϣ���Լ��û���Ϣ�ı�Ļ����¼�
		struct IUser
		{
			//!��ȡ��ǰ�û���Ϣ
			/*! 
			/* \return IUserInfo*, success��Чָ��,errorΪNULL
			*/
			virtual IUserInfo * GetCurrnetUserInfo() = 0;

			//!����uid��ȡ��ǰ�û���Ϣ
			/*!
			* \param unsigned int [in] �û�id
			* \return IUserInfo*, success��Чָ��,errorΪNULL
			*/
			virtual IUserInfo * GetUserInfo(unsigned int uid) = 0;

			//!ע���û��¼�
			/*!
			* \param IUserEvent* [in] ��Ч���û��¼�ָ��
			* \return int, 0 success ,����ֵ error,�ο���������
			*/
			virtual int RegisterUserEvent(IUserEvent *e) = 0;

			//!��ע�� �û��¼�
			/*!
			* \param IUserEvent* [in] ��Ч���û��¼�ָ��
			* \return int, 0 success ,����ֵ error,�ο���������
			*/
			virtual int UnRegisterUserEvent(IUserEvent *e) = 0;
		};

		//![interface] Ƶ���Ҽ��˵��ӿ�
		//!Ƶ���û��б��Ҽ��˵����� ��ȡ������ �Ͷ�Ӧ�Ĳ˵��¼�����
		struct IChannelUserListPopMenu
		{
			//!����Ƶ���û��Ҽ��˵�
			/*!
			* \param [in] char* ��ʾ���Ҽ��˵��ַ���
			* \param [in] int   �Ҽ��˵���ʾ�ַ������� ��󳤶� 20
			* \return int, 0 success ,���� ֵerror,�ο���������
			*/
			virtual int SetPopMenu(const char *str, 
					unsigned int size) = 0;

			//!ȡ������Ƶ���û��Ҽ��˵�
			/*!
			* \return int, 0 success ,���� ֵerror,�ο���������
			*/
			virtual int UnSetPopMemu() = 0;

			//!ע��Ƶ���Ҽ��˵��¼�
			/*!
			* \param [in] IChannelUserPopMenuEvent* e,��Ч���Ҽ��˵��¼�ָ��
			* \return int, 0 success ,���� ֵerror,�ο���������
			*/
			virtual int RegisterPopMenuEvent(IChannelUserPopMenuEvent * e) = 0;

			//!��ע��Ƶ���Ҽ��˵��¼�
			/*!
			* \param IChannelUserPopMenuEvent* [int] ��Ч���Ҽ��˵��¼�ָ��
			* \return int, 0 success ,���� ֵerror,�ο���������
			*/
			virtual int UnRegisterPopMenuEvent(IChannelUserPopMenuEvent * e) = 0;
		};

		//![interface] Ӧ����Ϣ�ӿ�
		//!����Ϣ��Ƶ���ڵĹ������·�����һ���ɵ�������ӵ�������Ϣ��֧�ַ��͵�ָ������Ƶ�������ˣ���ָ���û� �� �ӿ����
		struct IChannelAppMsg
		{
			//!����Ӧ����Ϣ
			/*!
			* \param unsigned int sub_channel_id, ��Ƶ��id
			* \param const char* view_str [in],��ʾ�ַ���
			* \param unsigned size [in], ��ʾ�ַ����Ĵ�С ��󳤶� [100]
			* \param unsigned int  [in], ��ʾ�ַ����е�������λ��
			* \param unsigned int link_end_pos [in], ��ʾ�ַ��������ӽ���λ�� //!eg. view_str :"my app link" ���� link�ַ�,link_begin_pos: 7, link_end_pos:10
			* \param unsigned int cookie [in], �Զ�������
			* \return int, 0 success ,����ֵ error,�ο���������
			*/
			virtual int SendMsgToSubChannel(unsigned int sub_channel_id,
				const char *view_str,
				unsigned int link_begin_pos,
				unsigned int link_end_pos,
				unsigned int cookie) = 0;

			//!����Ӧ����Ϣ
			/*!
			* \const unsigned int *users, �û������׵�ַ
			* \const unsigned int size, �û���������
			* \param const char* view_str [in],��ʾ�ַ���
			* \param unsigned size [in], ��ʾ�ַ����Ĵ�С ��󳤶� [100]
			* \param unsigned int  [in], ��ʾ�ַ����е�������λ��
			* \param unsigned int link_end_pos [in], ��ʾ�ַ��������ӽ���λ�� //!eg. view_str :"my app link" ���� link�ַ�,link_begin_pos: 7, link_end_pos:10
			* \param unsigned int cookie [in], �Զ�������
			* \return int, 0 success ,����ֵ error,�ο���������
			*/
			virtual int SendMsgToUsers(const unsigned int *users, 
				unsigned int size,
				const char *view_str,
				unsigned int link_begin_pos,
				unsigned int link_end_pos,
				unsigned int cookie) = 0;

			//!ע��Ƶ��Ӧ����Ϣ�¼�
			/*!
			* \param [in] IChannelUserPopMenuEvent* e,��Ч���Ҽ��˵��¼�ָ��
			* \return int, 0 success ,����ֵ error,�ο���������
			*/
			virtual int RegisterChannelAppLinkEvent(IChannelAppLinkEvent *e) = 0;

			//!��ע��Ƶ��Ӧ����Ϣ�¼�
			/*!
			* \param [in] IChannelUserPopMenuEvent* e,��Ч���Ҽ��˵��¼�ָ��
			* \return int, 0 success ,����ֵ error,�ο���������
			*/
			virtual int UnRegisterChannelAppLinkEvent(IChannelAppLinkEvent *e) = 0;
		};

		//![interface] ����ӿ�
		//!��ȡ�����б�ע������仯�¼����
		struct IChannelMicList
		{
			//!��ȡ�����б�
			/*!
			* \return IMicListItem * ,��Чָ�� success��error����NULL
			*/
			virtual const IMicListItem * GetMicList() = 0;

			//!ע��Ƶ�������¼�
			/*!
			* \param [in] IMicListEvent* e,��Ч���Ҽ��˵��¼�ָ��
			* \return int, 0 success ,����ֵ error,�ο���������
			*/
			virtual int RegisterMicListEvent(IMicListEvent *e) = 0;

			//!��ע��Ƶ�������¼�
			/*!
			* \param [in] IMicListEvent* e,��Ч���Ҽ��˵��¼�ָ��
			* \return int, 0 success ,����ֵ error,�ο���������
			*/
			virtual int UnRegisterMicListEvent(IMicListEvent *e) = 0;
		};

		//![interface] Ƶ���Ӵ��� 
		//!��Ƶ�����м��һ���Ӵ��ڣ�����Ӧ���Զ���UI���ڴ������ڳɹ��󣬿��Խ��ܴ��ڴ�С�ı䣬����ʾ���ص��¼�
		struct IChannelSubWindow
		{
			//!����Ƶ����Ƕ����
			/*!
			* \param unsigned long &h [inout], Window HANDLE ����
			* \param unsigned int &x [inout], �Ӵ��� x λ��
			* \param unsigned int &y [inout], �Ӵ��� y λ��
			* \param unsigned int &width [inout], �Ӵ��� ��
			* \param unsigned int &height [inout], �Ӵ���  ��
			* \param bool &visible [inout], �Ƿ���ʾ
			* \return int, 0	success,����ֵ error���鿴��������
			*/		
			virtual int CreateSubWindow(unsigned long &h, 
				unsigned int &x, 
				unsigned int &y, 
				unsigned int &width, 
				unsigned int &height,
				bool &visible) = 0;

			//!�ر���Ƕ����
			/*!
			* \return int, 0 success,����ֵ error���鿴��������
			*/
		virtual int CloseSubWindow() = 0;
			
			//!ע��Ƶ���¼�
			/*!
			* \param IChannelSubWindowEvent * e [in] [not NULL]
			* \return int, 0	success,����ֵ error���鿴��������
			*/
			virtual int RegisterChannelSubWinEvent(IChannelSubWindowEvent *e) = 0;
			
			//!��ע��Ƶ���¼�
			/*!
			* \param IChannelSubWindowEvent * e [in] [not NULL]
			* \return int, 0	success,����ֵ error���鿴��������
			*/
			virtual int UnRegisterChannelSubWinEvent(IChannelSubWindowEvent *e) = 0;
		};

		//![interface] Ƶ���ӿ�
		//!��ȡƵ����ؽӿڵ���ڣ����а���Ƶ����Ϣ����Ƶ����Ϣ������ӿڣ�Ƶ���Ӵ��ڽӿڣ�Ƶ��Ӧ����Ϣ�ӿڣ�Ƶ����Ϣ 
		struct IChannel
		{
			//!��ȡ��ǰ��Ƶ����Ϣ
			/*!
			* \return IChannelInfo *, error NULL
			*/
			virtual IChannelInfo * GetCurrentSubChannelInfo() = 0;

			//!��ȡ��Ƶ����Ϣ
			/*!
			* \return IChannelInfo *, error NULL
			*/
			virtual IChannelInfo * GetCurrentChannelInfo() = 0;

			//!ͨ��Ƶ��id��ȡƵ����Ϣ
			/*!
			* \param unsigned int cid [in],Ƶ��������Ƶ��id
			* \return IChannelInfo *, error NULL
			*/
			virtual IChannelInfo * GetChannelInfo(unsigned int cid) = 0;

			//!��ȡƵ�����ӿ�
			/*!
			* \return IChannelNode *, error NULL
			*/
			virtual const IChannelNode * GetChannelTree() = 0;

			//!��ȡ����ӿ�
			/*!
			* \return IChannelMicList *,error NULL
			*/
			virtual IChannelMicList * GetMicList() = 0;

			//!��ȡ�Ҽ��˵��ӿ�
			/*!
			* \return IChannelUserListPopMenu *, error NULL
			*/
			virtual IChannelUserListPopMenu *GetUserListPopMenu() = 0; 
			
			//!��ȡƵ����Ϣ�ӿ�
			/*!
			* \return IChannelAppMsg *, error NULL
			*/
			virtual IChannelAppMsg * GetAppMsg() = 0;
			
			//!��ȡƵ���Ӵ��ڽӿ�
			/*!
			* \return IChannelSubWindow *, error NULL
			*/
			virtual IChannelSubWindow * GetSubWin() = 0;
		
			//!ע��Ƶ���¼�
			/*!
			* \param IChannelEvent * e, [in] [not NULL]
			* \return int, 0 success, ����ֵ error,�ο���������
			*/
			virtual int RegisterChannelEvent(IChannelEvent *e) = 0;

			//!��ע��Ƶ���¼�
			/*!
			* \param IChannelEvent * e [in] [not NULL]
			* \return int, 0	success,����ֵ error���鿴��������
			*/
			virtual int UnRegisterChannelEvent(IChannelEvent *e) = 0;
		};

		//![interface] IM�ӿ�
		//!�ṩ����uid����������Ϣ���ڹ��ܣ������������ṩ�Ƿ��Ǻ��ѣ����Ӻ��ѵĽӿ�
		struct IIM
		{
			//!����IM�Ի���,ֻ֧�ַ��͵���ǰ����
			/*!
			* \param int uid [in],�û�Ψһid
			* \param const char * [in], ������Ϣ
			* \param unsigned int size [in], ��Ϣ���� ֵ��Χ(0, 40]
			* \return int, 0 success, ����ֵ error,�ο���������
			*/
			virtual int ChatTo(unsigned int uid, const char *msg, unsigned int size) = 0;
		};

		//![interface] �����ӿ� 
		//!�ṩ¼�����ܣ���¼���¼�
		struct IAudio
		{
			//!��ʼ¼��
			/*!
			* \param const char *file_name [in],¼�������ļ���
			* \return int, 0 success, ����ֵ error,�ο���������
			*/
			virtual int StartRecord(const char *file_name) = 0;
		    
			//!ֹͣ¼��
			/*!
			* \return int, 0 success, ����ֵ error,�ο���������
			*/
			virtual int StopRecord() = 0;

			//!ע����Ƶ�豸���Ļص�
			/*!
			* \param IAudioEvent *e, [Not NULL]
			* \return int, 0 success ����ֵ error �ο���������
			*/
			virtual int RegisterAudioEvent(IAudioEvent *e) = 0;

			//!��ע��IAudioDeviceChangedEvent
			/*!
			* \return int ,0 success������ֵ error �ο���������
			*/
			virtual int UnRegisterAudioEvent(IAudioEvent *e) = 0;
		};

		//![interface]����ӿ�
		//!�ṩ����yy���Ͽ�yy���㲥���ݵ���ǰƵ�����е��ˣ��㲥���ݵ�ָ������Ƶ�����㲥���ݵ�ָ�����û����͹㲥�¼�
		//!ע�⣺ֻ�е�ǰ��Ӧ�ÿ���״̬�����յ��㲥����
		struct INet
		{
			//!���ӵ�ƽ̨
			/*!
			* \return int, 0 success������ֵ error���ο���������,�ڻ�ȡ��IYY �ӿ�֮�������5��֮�������ϣ��������ӻ�ʧЧ��
			*/
			virtual int Connect() = 0;

			//!�����Ͽ�
			/*!
			* \return int, 0 success������ֵ error���ο���������
			*/
			virtual int Close() = 0;

			//!��Ƶ�����ݹ㲥
			/*!
			* \param unsigned int sub_channel_id [in], ��Ƶ��id,
			* \param const char *data [in], �㲥������ ��ʼ��ַ
			* \param unsigned int size [in], �㲥��������С�� ֵ��Χ(0, 4096]
			* \return int, 0 success������ֵ error���ο���������
			*/
			virtual int BroadcastToSubChannel(unsigned int sub_channel_id, const char *data, unsigned int size) = 0;
		    
			//!ȫƵ�����ݹ㲥
			/*!
			* \param const char *data [in], �㲥������ ��ʼ��ַ
			* \param unsigned int size [in], �㲥��������С ֵ��Χ(0, 4096] 
			* \return int, 0 success������ֵ error���ο���������
			*/
			virtual int BroadcastToAllChannel(const char *data, unsigned int size) = 0;
			
			//!�㲥��ָ���û�
			/*!
			* \param const char *data [in], �㲥������ ��ʼ��ַ
			* \param unsigned int size [in], �㲥��������С ֵ��Χ(0, 4096] 
			* \param int *u_array [in], �û����� ��ʼ��ַ
			* \param unsigned int count [in], �û������С ֵ��Χ(0, 100] 
			* \return int, 0 success������ֵ error���ο���������
			*/
			virtual int BroadcastToUsers(const char *data, unsigned int size, unsigned int *u_array, unsigned int count) = 0;
			
			//!ע������ص�
			/*!
			* \param INetEvent *e [in],�����¼�
			* \return int, 0 ע��success,����ֵerror,�ο���������
			*/
			virtual int RegisterNetEvent(INetEvent *e) = 0;

			//!��ע��INetStateEvent 
			/*!
			* \return int, 0 success������ֵerror �ο���������
			*/
			virtual int UnRegisterNetEvent(INetEvent *e) = 0;
		};

		//![interface]�ƴ洢���ݷ���
		//!�ṩ�򵥵����ݴ洢���Ͳ������������Դ洢����int��һ���ַ�����һ��2������
		//!��ǰƵ��������ֻ�г��������߱��޸��������ݵ�������������һ��ֻ���޸��Լ�������
		struct ICloud
		{
			//!��������
			/*!
			* \param ICloudData *data [in],�ƴ洢���ݣ���������ֵ��������Ч
			* \return unsigned int, 0 success, ����ֵ error, �ο���������
			*/
			virtual unsigned __int64 AddData(ICloudData *data) = 0;

			//!�޸�����
			/*!
			* \param ICloudData *data �ƴ洢���� ����������ֵ��������Ч
			* \param ICloudFilter *filter ,�ƴ洢����������������������ֵ
			* \return int, 0 success, ����ֵ error���ο���������
			*/
			virtual int UpdateData(ICloudData *data, ICloudFilter *filter) = 0;
			
			//!ɾ������
			/*!
			* \param ICloudFilter *filter [in],�ƴ洢����������������������ֵ
			* \return int, 0 success, ����ֵ error���ο���������
			*/
			virtual int DeleteData(ICloudFilter *filter) = 0;

			//!��ѯ����
			/*!
			* \param ICloudDataList *filter [in],�ƴ洢����������������������ֵ
			* \return ICloudDataList, ���ز�ѯ���ݽṹ
			*/
			virtual ICloudDataList * QueryData(ICloudFilter *filter) = 0;

			//!�����ƴ洢����
			/*!
			* \return ICloudData *, success������Чָ�룬error����NULL
			*/
			virtual ICloudData * CreateCloudData() = 0;

			//!�������ݹ�����
			/*!
			* \return ICloudFilter *, success������Чָ�룬error����NULL
			*/
			virtual ICloudFilter * CreateCloudFilter() = 0;
		};
	}
}

#endif //!_DW_OPENPLATFORM_CLIENT_API_H_
