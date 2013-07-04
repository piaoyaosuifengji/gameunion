//! IYY SDK typde  ����
/*! �ӿ�˵��
 * @file dwop-api-com.h
 * @create date 2011-11-30
 * @modify data 2011-11-30
 * @author simon.lv
 * @version 1.0
 * @modify list
 * ............................................................................
 * ............................................................................
 * yy open platform client api, �����첽�� yyplatform ����ͨ��Э��
 * ���ݻ�������Ƽ����޹�˾ ��Ȩ���� (c) 2005-2011 DuoWan.com [������Ϸ]

 ******************************************************************************
 * ��ϸ�ӿ��ĵ��ο�open.yy.com
 *******************************************************************************/

#ifndef _DW_OPENPLATFORM_API_TYPES_H_
#define _DW_OPENPLATFORM_API_TYPES_H_

//!�汾��Ϣ
//!sdk version 1.0
#define DW_API_VERSION (1 << 16 | 0)

namespace yy
{

extern "C"
{
	//![interface]YY COM�ӿڣ�����COM���ƣ�����ָ��ʱ����AddRef(),�ͷ�ָ�� Release()
	//!��֧��QueryInterface �� IDisPathcer������COM����
	struct IYYUnk
	{
		//!�������
		/*!
		*/
		virtual void AddRef() = 0;
		
		//!�ͷ�����
		/*!
		*/
		virtual void Release() = 0;
	};

	//![interface] YY�û���Ϣ
	struct IUserInfo : public IYYUnk
	{
		typedef enum EUserRole
		{
			//!��Ч��ɫ
			NUlL_ROLE			= 0,
			//!������ VS ����
			VISITOR				= 20,	
			//!��ͨ��Ա N ����
			NORMAL				= 25,	
			//!��ʱ�α�	TMVIP 
			TMPVIP				= 66,
			//!�α�	VIP ����	
			VIP					= 88,
			//!��Ա	R ����
			MEMBER				= 100,
			//!������Ƶ������Ա CA ����
			CMANAGER			= 150,
			//!һ����Ƶ������Ա 
			PMANAGER			= 175,
			//!����Ա			 MA ����
			MANANGER			= 200,
			//!���᳤			
			VICE_OWNER			= 230,
			//!Ƶ��������   OW    ����
			OWNER				= 255,
			//!�ͷ�
			CUSTOMER_SERVICE	= 300,
			//!����	police 
			POLICE				= 400,
			//!DW�ٷ���Ա		����  
			OFFICIAL			= 1000
		} UserRole;
				
		//!��ȡuid
		/*!
		* /return unsigned int, �û�id
		*/
		virtual unsigned int GetUid() const = 0;

		/*!��ȡ�û�im id
		* \return IM����
		*/
		virtual unsigned int GetIMId() const = 0;

		/*!	��ȡ�û��Ա�
		* \return unsigned int �Ա�(0:��  1:Ů)
		*/
		virtual unsigned int GetSex() const = 0;	

		/*!��ȡ�û���ɫ
		* \return unsigned int �ڵ�ǰ��Ƶ���еĽ�ɫ
		*/
		virtual unsigned int GetRole() const = 0;

		/*!��ȡ�û�����
		* \return unsigned int, ���˻���
		*/
		virtual unsigned int GetPoints() const = 0;

		/*!	��ȡ�û��ȼ�
		* \return unsigned int, ���˵ȼ�
		*/
		virtual unsigned int GetLevel() const = 0;		
		
		//!��ȡ�û��ǳ� 
		/*!
		* \param name [inout] �����û��� �ַ������ַ  ,ΪϵͳĬ�ϻ������� CP_ACP
		* \param size[in]   �����С max size = 20 * 2,
		* \return int, 0 success, ����ֵerror
		*/
		virtual int	GetName(char *name, int size) const = 0;

		//!�û�����ǩ��
		/*!
		* \param sign [inout] ���湫����Ϣ �ַ�����ַ ΪϵͳĬ�ϻ������� CP_ACP
		* \param size [in] �����С <= 100 * 2
		* \return int, 0 success, ����ֵerror, �ο��������
		*/
		virtual int	GetSign(char *sign, int size) const = 0;	//! �û�����ǩ��  
	};

	//![interface] Ƶ����Ϣ 
	struct IChannelInfo : public IYYUnk
	{
		//! ��ȡƵ����λid
		/*!
		* \return int,
		*/
		virtual unsigned int GetLongId() const = 0;

		//! ��ȡƵ����λid
		/*!
		* \return int,Ƶ����λid
		*/
		virtual unsigned int GetShortId() const = 0;
		
    //!Ƶ���ǳ�
		/*!
		* \param name [out] ����Ƶ���� �ַ������ַ  ,ΪϵͳĬ�ϻ������� CP_ACP
		* \param size[in]   �����С , ֵ��Χ [0,40]
		* \return int, 0 success, ����ֵerror, �ο��������
		*/
		virtual int	GetName(char *name, int size) const = 0;
	};	
  
	//![interface]�����û���Ϣ
	struct IMicListItem
	{
		//!��ȡ��ǰ�ڵ��û�Id
		/*!
		* \return int,�û�id
		*/		
		virtual unsigned int GetUserId() const = 0;

		//!��һ���ڵ�
		/*!
		* \return IMicListItem *,��һ�������û��Ľڵ�
		*/	
		virtual const IMicListItem * GetNext() const = 0;
	};
  
	//![interface] Ƶ�����ڵ� 
	struct IChannelNode
	{
		//!��ȡƵ���� root �ڵ�
		/*!
		* \return IChannelNode *,Ƶ���� root �ڵ�
		*/			
		virtual const IChannelNode * GetRoot() const = 0;
	  
	  //!��ȡƵ�������ڵ�
	  /*!
		* \return IChannelNode *,Ƶ���ڵ� �ɹ� ��Чָ�룬NULL error
	  */
		virtual const IChannelNode * GetParent() const = 0;
	  
	  //!��ȡƵ�ӽڵ�
	  /*!
	   * \param unsigned int index,�ӽڵ� ����ֵ, ���㿪ʼ��ֵ����С�� �ӽڵ�����,��0��ʼ����
		* \return IChannelNode *,Ƶ���ڵ� �ɹ� ��Чָ�룬NULL error
	  */	  
		virtual const IChannelNode * GetChildAt(unsigned int index) const = 0;

		//!ͨ����ȡ�ӽڵ㣬�ӽڵ���ӽڵ�Ҳ���Ի�ȡ
		/*!
	    * \param unsigned int cid,ͨ�� Ƶ��ID��ȡ�ڵ�
		* \return IChannelNode *,Ƶ���ڵ� �ɹ� ��Чָ�룬NULL error			
		*/
		virtual const IChannelNode * GetChild(unsigned int cid) const = 0;
	  
	  //!��ȡƵ�ӽڵ�����
	  /*!
		* \return int, ֵ��Χ [0,4000)
	  */	  
		virtual const unsigned int GetCount() const = 0;
	  
	  //!��ȡ��ǰ�ڵ�Ƶ��id
	  /*!
		* \return int, ��ǰ�ڵ�Ƶ��id
	  */		  
		virtual const unsigned int GetCid() const = 0;
	};

	//![interface] �ƴ洢���ݽṹ��
	struct ICloudData : public IYYUnk
	{
		//!��ȡ��ǰ���� Ψһid
	  /*!
		* \return unsigned __int64, Ψһid
	  */		
		virtual unsigned __int64 GetUniqueKey() const = 0;

		//!��ȡ���ݴ����ߵ�Uid
	  /*
		* \return unsigned int, Ψһid
	  */
		virtual unsigned int GetCreatorUid() const = 0;

		//!��ȡ��ǰ���� ���һ�θ���ʱ��
	  /*!
		* \return unsigned __int64 ����ʱ��
	  */
		virtual unsigned __int64 GetUpdateTime() const = 0;

		//!��ȡ��ǰ���� ����ʱ��
	  /*!
		* \return unsigned __int64 ����ʱ��
	  */
		virtual unsigned __int64 GetCreateTime() const = 0;
		
		//!��ȡ��ǰ���� ��һ��intֵ
	  /*!
		* \return unsigned int, ��һ��intֵ
	  */				
		virtual unsigned int GetIntValue1() const = 0;
		
		//!��ȡ��ǰ���� �ڶ���intֵ
	  /*!
		* \return unsigned int, �ڶ���intֵ
	  */			
		virtual unsigned int GetIntValue2() const = 0;
		
	  //!��ȡ�ַ���ֵ
	  /*!
		* \param char *data, �ַ���
		* \return int, 0 success, ����ֵerror, �ο��������
	  */			
		virtual const char * GetStringValue() const = 0;
		
	  //!��ȡ2�������׵�ַ
	  /*!
		* \return char *, 2���������׵�ַ
	  */			
		virtual const char * GetBinaryValue() const = 0;
		
	  //!��ȡ2������ ��С
	  /*!
		* \return char *, 2�������ݴ�С�� ֵ��Χ [0,4096]
	  */	
		virtual int GetBinraySize() const = 0;
		
	  //!���õ�һ��intֵ
	  /*!
	  * \param unsigned int value, int ֵ
		* \return int, 0 success, ����ֵerror, �ο��������
	  */	
		virtual int SetIntValue1(unsigned int value) = 0;
		
		//!���õڶ���intֵ
		/*!
		* \param unsigned int value��int��ֵ
		* \return int, 0 success, ����ֵerror, �ο��������
		*/
		virtual int SetIntValue2(unsigned int value) = 0;
		
		//!�����ַ���ֵ
		/*!
		* \param const char *data, �ַ���ֵ
		* \return int, 0 success, ����ֵerror, �ο��������
		*/
		virtual int SetStringValue(const char *data) = 0;
		
		//!����2����ֵ
		/*!
		* \param const char *data, �ַ���ֵ
		* \param const unsigned int size, ���������ݴ�С ,ֵ��Χ (0,4096]
		*/		
		virtual int SetBinrayValue(const char *data, unsigned int size) = 0;		
	};

	//![interface] �ƴ洢���� �б�
	//!���ڲ�ѯ���� ���ؽ����ICloudData ���б�
	struct ICloudDataList
	{
		//!ʹ������ֵ��ȡ�ƴ洢����
		/*!
		* \param unsigned int index, ����ֵ,��0��ʼ����
		* \return ICloudData *, ��Чָ�� success, ����ֵ error
		*/
		virtual const ICloudData * GetDataAt(unsigned int index) = 0;
		
		//!��ȡ�ƴ洢list����
		/*!
		* \return unsigned int, �б�����
		*/
		virtual unsigned int GetCount() = 0;
	};

	//![interface] �ƴ洢������
	//!�ṩ���ƴ洢ICloudData ��һ��Int�͵ڶ���Int �� ����ʱ����޸� �Ĳ�ѯ ����
	struct ICloudFilter : public IYYUnk
	{
		enum EField
		{
			//!��Ч�ֶ�
			FIELD_NONE = 0,
			//!key Ψһ�� �ֶ�
			UNIQUE_KEY_FIELD = 1,	
			//!uid �ֶ�
			USER_ID_FIELD = 2,
			//!��չint1 �ֶ�
			External_VALUE1 = 3,
			//!��չint2 �ֶ�
			External_VALUE2 = 4,
			//!����ʱ��
			FIELD_CREATE_TIME = 5,
			//!����ʱ��
			FILED_UPDATE_TIME = 6
		};

		enum EFilterOperator
		{
			//! ��Ч����
			FILTER_OP_NONE = 0,
			//! = ����
			FILTER_OP_EQ = 1,
			//! >= ���ڵ���
			FILTER_OP_GE = 2,
			//! <= С�ڵ���	
			FILTER_OP_LE = 3,
			//! = ����
			FILTER_OP_GREATER = 4,
			//! < С��
			FILTER_OP_LESS = 5
		};

		enum EFilterCondition
		{
			//!��Ч����
			FILTER_CD_NONE = 0,
			//! ���� �� and 
			FILTER_CD_AND = 1,
			//! ���� �� or
			FILTER_CD_OR
		};

		//!���� ��������
		/*!
		* \param const EField field, ���������ֶ�
		* \param const EFilterOperator op, ���������ֶ� ����
		* \param const unsigned int filter_value, ������������ ֵ
		* \param const EFilterCondition condition,���� ����
		* \return int ,0 success, ����ֵ error
		*/
		virtual int AddFiter(const EField field,
			const EFilterOperator op,
			const unsigned __int64 filter_value,
			const EFilterCondition condition) = 0;
	};
}

}
#endif //!_DW_OPENPLATFORM_API_TYPES_H_