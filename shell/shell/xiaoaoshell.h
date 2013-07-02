#pragma once
class xiaoaoshell
{
public:
	xiaoaoshell(void);
	~xiaoaoshell(void);
};

//第一个脚本是自动打怪脚本
/*

不同的显示器分辨率显然会有不同的坐标


你的台式机是1440*900，就是说左上角的坐标是（0.0），右下角的坐标是（1440.900）






需要实现的功能子集：

1：选怪
2：技能释放------一开始可以只是简单的顺序释放，后面可以进行优化，就是根据技能cd时间就行无间断释放
3：判断是否打死了怪
4：重新回到1
5：自动加血蓝内气
*/



DWORD WINAPI autoAttack(PVOID pvParam);
int ifNeedToNeiLi(CString Environment,CPoint  * ParameterPoints);
int ifNeedToHuiXue(CString Environment,CPoint  * ParameterPoints);
void readAndRunShell(CString  littleshellfile);
