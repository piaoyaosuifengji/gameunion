#pragma once
class xiaoaoshell
{
public:
	xiaoaoshell(void);
	~xiaoaoshell(void);
};

//��һ���ű����Զ���ֽű�
/*

��ͬ����ʾ���ֱ�����Ȼ���в�ͬ������


���̨ʽ����1440*900������˵���Ͻǵ������ǣ�0.0�������½ǵ������ǣ�1440.900��






��Ҫʵ�ֵĹ����Ӽ���

1��ѡ��
2�������ͷ�------һ��ʼ����ֻ�Ǽ򵥵�˳���ͷţ�������Խ����Ż������Ǹ��ݼ���cdʱ������޼���ͷ�
3���ж��Ƿ�����˹�
4�����»ص�1
5���Զ���Ѫ������
*/



DWORD WINAPI autoAttack(PVOID pvParam);
int ifNeedToNeiLi(CString Environment,CPoint  * ParameterPoints);
int ifNeedToHuiXue(CString Environment,CPoint  * ParameterPoints);
void readAndRunShell(CString  littleshellfile);
