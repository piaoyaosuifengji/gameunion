#pragma once
class taskHandle
{
public:
	taskHandle();
	~taskHandle();
};




//zai����������Ͳ���һЩ����ʱ��Ϊ���ж�
//���ȥ������ô����������һ������ṹ���������
//�ṹ���ж�ȥ���������غ���

#define Shell_Hangle			1
#define Func_Hangle				2

struct  taskMsg
{
	int taskID;//gei��ÿһ������Ԥ����һ��ID
	//int subTaskID;//ÿһ�����������������Ҳ��ID
	int flag1;//��¼һЩ״̬
	int fucPos;//����ʵ���������ĺ���λ�ã��е�����������shell���е���������Ӧ�ĺ���
				//fucPos ΪShell_Hangle��ʾ�ж�Ӧ��taskShell		��ȡ�Ǹ�shell��ʵ��
				//fucPos ΪFunc_Hangle��ʾ�ж�Ӧ��task  function��������Ӧ����
	int fucID;//��������/shell �ı��
};



//����һ��Hangle�Ĺ��̣�
//	1����shellResolve�ж�������ID��
//	2��  tasksp[]�и���taskMsg�ṹ
//	3�����Shell_Hangle    Func_Hangle








int TaskId_Mainline_Hangdle_fuc(int  process);//����Ϊ�Ѿ���ɽ��ȣ���������������id
void SignInTaskFuc();