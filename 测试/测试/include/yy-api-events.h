//!! IYY SDK event  ����
/*! �ӿ�˵�� platform api �¼� �ӿ�, ʹ���߼̳ж�Ӧ��Event�ӿ�ʵ��֮��ע�ᵽָ���Ľӿ�
	ע����߻�����event ֻ����APi��ʼ���̷߳��� ��������UI�̳߳�ʼ��API
 * @file dw-api-events.h
 * @create date 2011-12-01
 * @modify data 2011-12-01
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

#ifndef _DW_PLATFORM_API_EVENTS_H_
#define _DW_PLATFORM_API_EVENTS_H_

#include "yy-api-types.h"

namespace yy
{

extern "C"
{
	//![event] �û��¼�
	struct IUserEvent
	{
		//!�û���Ϣ�ı�
		/*!
		 * \param info [in] ,�ı����û���Ϣ
		*/
		virtual void OnUserInfoChanged(IUserInfo *info) = 0;
	};
	
	//![event] Ƶ����Ϣ��ȡ�ص��ӿ�
	struct IChannelEvent
	{
		//!��Ƶ����תʱ����
		/*!
		 * \param unsigned int departed_id [in] ,ԭ����Ƶ��id
		 * \param unsigned int now_id	[in]	,������Ƶ��id
		*/
		virtual void OnFocusChannelChannged(unsigned int departed_id, unsigned int now_id) = 0;

		//!��Ƶ����Ϣ�ı�ʱ�����¼�
		/*! 
		* \param IChannelInfo *info[in] ,�ı���Ƶ����Ϣ
		*/
		virtual void OnChannelInfoChannged(IChannelInfo *info) = 0;

		//!ɾ����Ƶ��ʱ�����¼�
		/*!
		* \param unsigned int cid [in], ��Ƶ��id
		*/
		virtual void OnSubChannelDel(unsigned int cid) = 0;

		//!�����Ƶ��ʱ�����¼�
		/*!
		 * \param unsigned int cid [in], ��������Ƶ��id��
		 * \param unsigned int pcid [in], ��Ƶ��id
		*/
		virtual void OnSubChannelAdd(unsigned int cid, unsigned int pcid) = 0;

		//!�����Ƶ��ʱ�����¼�
		/*!
		 * \param unsigned int cid [in], ��������Ƶ��id��
		 * \param unsigned int pcid [in], ��Ƶ��id
		*/
		virtual void OnUserEnterChannel(unsigned int uid, unsigned int cid) = 0;

		//!�����Ƶ��ʱ�����¼�
		/*!
		* \param unsigned int cid [in], ��������Ƶ��id��
		* \param unsigned int pcid [in], ��Ƶ��id
		*/
		virtual void OnUserLeaveChannel(unsigned int uid, unsigned int cid) = 0;
	};
	
	//![event] �����豸�����¼�
	struct IAudioEvent
	{
		//!¼������ص�֪ͨ
		/*!
		* \param int err_code [in], ¼��������룬�ο���������
		*/
		virtual void OnRecordErr(int err_code) = 0;
	    
		//!¼����ɻص�֪ͨ
		/*!
		* \param int result [in], ¼�����
		* \param const char *file_name[in],¼���ļ���
		*/
		virtual void OnRecordFinished(int result, const char *file_name) = 0;
	};

	//![event] Ƶ���û��б��Ҽ��˵��¼�֪ͨ 
	struct IChannelUserPopMenuEvent
	{
		//!�Ҽ��û��˵��¼�
		/*!
		* \param unsigned int uid [in], �û�id
		* \param unsigned int cid [in], �û�����Ƶ��id
		*/
		virtual void OnClicked(unsigned int uid, unsigned int cid) = 0;
	};

	//![event] ����״̬�ص� 
	struct INetEvent
	{
		//!���ӻص�
		/*!
		* \param int result [in],���ӽ������, 0:success ,����ֵ error, �ο�DWApi��������
		*/
		virtual void OnConnected(int result) = 0;
		
		//!�Ͽ���ص�
		/*!
		* \param int result, 0:�����Ͽ�, ����ֵerror, ��ο� DWApi��������
		*/
		virtual void OnClosed(int result) = 0;

    //!�յ��㲥���ݰ�
		/*!
		* \param const char *data	[in], �յ����ݰ���ַ
		* \param unsigned int size	[in], �յ����ݰ��Ĵ�С
		*/
		virtual void OnRecv(const char *data, unsigned int size) = 0;
	};

	//![event]Ӧ����Ϣ�¼�
	struct IChannelAppLinkEvent
	{
		//!���ӵ���¼�
		/*!
		* \param unsigned int token 	[in],������Ϣ�û��Զ���ֵ
		*/
        virtual void OnAppLinkClicked(unsigned int token) = 0;
	};
	
	//![event]��������б��¼�
	//!��ǰ������Ƶ�� �û������������������Լ�ĳ���ƶ�������¼�
	struct IMicListEvent 
	{
		//!���˼�������
		/*!
		* \param unsigned int uid [in], ���������û���id
		*/
	    virtual void OnUserJoin(unsigned int uid) = 0;
		
		//!�����뿪����
		/*!
		* \param unsigned int uid [in], �����û���id
		*/
		virtual void OnUserLeave(unsigned int uid) = 0;
		
		//!�����ϵ����ƶ�
		/*!
		* \param unsigned int uid,�����ƶ����û���id
		* \param unsigned int after_uid,�ƶ���ĳ���û������id
		*/
		virtual void OnUserMove(unsigned int uid, unsigned int after_uid) = 0;
		
		//!��������¼�
		/*! 
		*/
		virtual void OnClear() = 0;
	};
	
	//![event] Ƶ���Ӵ����¼�
	struct IChannelSubWindowEvent
	{
		//!��Ƶ��������ʾ�¼�
		/*!
		 * \param unsigned int x [in], ��Ƶ������x����
		 * \param unsigned int y [in], ��Ƶ������y����
		 * \param unsigned int width [in], ��Ƶ�����ڿ��
		 * \param unsigned int height [in], ��Ƶ�����ڸ߶�
		*/
		virtual void OnShow(unsigned int x, 
			unsigned int y,
			unsigned int width,
			unsigned int height) = 0;
		
		//!��Ƶ�����������¼�
		virtual void OnHide() = 0;
		
		//!��Ƶ�����ڴ�С�ı��¼�
		/*!
		 * \param unsigned int x [in], ��Ƶ������x����
		 * \param unsigned int y [in], ��Ƶ������y����
		 * \param unsigned int width [in], ��Ƶ�����ڿ��
		 * \param unsigned int height [in], ��Ƶ�����ڸ߶�
		*/
		virtual void OnSizeChannel(unsigned int x, 
			unsigned int y,
			unsigned int width,
			unsigned int height) = 0;
	};
}

}
#endif //!_DW_PLATFORM_API_EVENTS_H_