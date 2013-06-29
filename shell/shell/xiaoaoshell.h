#pragma once
class xiaoaoshell
{
public:
	xiaoaoshell(void);
	~xiaoaoshell(void);
};

//第一个脚本是自动打怪脚本
/*
需要实现的功能子集：

1：选怪
2：技能释放------一开始可以只是简单的顺序释放，后面可以进行优化，就是根据技能cd时间就行无间断释放
3：判断是否打死了怪
4：重新回到1
5：自动加血蓝内气
*/



DWORD WINAPI autoAttack(PVOID pvParam);