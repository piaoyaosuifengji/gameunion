




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

*/

#define  LEFTmouseClick   "LeftMouse"
#define  InputChar   "char"