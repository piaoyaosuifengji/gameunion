




//���������ļ�
//�����ʽ
//�������ͣ�����ִ��ʱ�䣺��������������
//���в��������ж�����ö��ŷֿ�
//'#'��ͷ��ʾע����

//�������ͣ�
/*
1:�ַ����롣����24����ĸ�������֡�
	������    char:1500:1:m
	���壺��ʾ����һ���ַ�m���ȴ�1.5��

2��������
	������    LeftMouse:1500:1:198,842,
	���壺ģ�������������ȴ�1.5��,�����������ݾ��ǵ���λ�õ�����
	������    LeftMouseDown:1500:1:198,842,
	���壺ģ�������������ȴ�1.5��,�����������ݾ��ǵ���λ�õ�����
3:�ַ����¡�����24����ĸ�������֡�
	������    KeyDown:1500:1:m
	���壺��ʾ����һ���ַ�m���£�����������1.5�벻�ſ�
const int MOUSEEVENTF_MOVE = 0x0001;      �ƶ���� 
const int MOUSEEVENTF_LEFTDOWN = 0x0002; ģ������������ 
const int MOUSEEVENTF_LEFTUP = 0x0004; ģ��������̧�� 
const int MOUSEEVENTF_RIGHTDOWN = 0x0008; ģ������Ҽ����� 
const int MOUSEEVENTF_RIGHTUP = 0x0010; ģ������Ҽ�̧�� 
const int MOUSEEVENTF_MIDDLEDOWN = 0x0020; ģ������м����� 
const int MOUSEEVENTF_MIDDLEUP = 0x0040; ģ������м�̧�� 
const int MOUSEEVENTF_ABSOLUTE = 0x8000; ��ʾ�Ƿ���þ�������

LEFTmouse ; ģ������������
RIGHT ; ģ������Ҽ�����


4���Զ�Ѱ·���Զ���λ��ָ����ͼ��ָ�����꣨ע�⣺����֮���ö��Ÿ�����
	������    location:1500:3:���ݳǣ�x��y
*/

/*
MapName   ID  ���壬����location���ַ���������ID��ת����
*/

#define MapNameID_LUOYANG			0		//������
#define MapNameID_FUZHOU			1		//���ݳ�



#define  LEFTmouseUP   "LeftMouseUP"
#define  LEFTmouseDOWN   "LeftMouseDown"
#define  RightmouseDOWN   "RightMouseDown"
#define  LEFTmouseClick   "LeftMouse"
#define  RightmouseClick   "RightMouse"
#define  InputChar   "char"
#define  KeyDown   "KeyDown"   //ĳ�������£������ſ�
#define  Location   "location"
#define  KeyBoardKey   "keyboard"			//ֱ�����������











//����ID��,��������ID��������ID֮�֣���ͬ���������в�ͬ��ID����4λ��ͬ
//ͬһ����������������в�ͬ�������񣬲�ͬ��������Ҳ����Ӧ��ID
//���ǵĸ�4λ��ͬ������λ��ͬ
//��������ID������λΪ0
#define  TaskId_Mainline_0	  10010000		
#define  TaskId_Mainline_1	  10010001		//��������������--������Ϸ
#define  TaskId_Mainline_2	  10010002		//��������������--��ȡ��һ������
#define  TaskId_Mainline_3	  10010003		//��������������--��ȡ��2������
#define  TaskId_Mainline_4	  10010004		//��������������--���ݳ� �˿���װ
#define  TaskId_Mainline_5	  10010005		//��������������--���ݳ� �������˵�ɱ��
#define  TaskId_Mainline_6	  10010006		//��������������--��jiong
#define  TaskId_Mainline_7	  10010007		//��������������--�����𣬸������
#define  TaskId_Mainline_8	  10010008		//��������������--�������ὣ��ǿ��
#define  TaskId_Mainline_9	  10010009		//��������������--�������ս����̯
#define  TaskId_Mainline_10	  10010010		//��������������--���ż�Ѫ���
#define  TaskId_Mainline_11   10010011		//��������������--�䵱�ܾ�����
#define  TaskId_Mainline_12   10010012		//��������������--�䵱�ܾ�����
#define  TaskId_Mainline_13   10010013		//��������������--�䵱�ܾ�����
#define  TaskId_Mainline_14   10010014		//��������������--�䵱�ܾ�����
#define  TaskId_Mainline_15   10010015		//��������������--�䵱�ܾ�����
#define  TaskId_Mainline_16   10010016		//��������������--�䵱�ܾ�����
#define  TaskId_Mainline_17   10010017		//��������������--�䵱�ܾ�����
#define  TaskId_Mainline_18   10010018		//��������������--�׺�Ц��׷��
#define  TaskId_Mainline_19   10010019		//��������������--�׺�Ц����ִ