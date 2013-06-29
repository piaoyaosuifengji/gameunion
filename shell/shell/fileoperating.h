#pragma once
class fileoperating
{
public:
	fileoperating(void);
	~fileoperating(void);
};


struct operat
{
	struct list_head;
	CString  shelltype;
	int time;
	int ParameterNum;
	CString  Parameter;

};


void ReadTxtToGetShell();
struct list_head * ReadTxtToGetShellByName(CString fileName);
int lineCount(CString fileName);
int ReadTxtToGetShellByName2(CString fileName,int linecount,struct operat *p);


//void CharToTchar (const char * _char, TCHAR * tchar)  
//{  
//    int iLength ;  
//  
//    iLength = MultiByteToWideChar (CP_ACP, 0, _char, strlen (_char) + 1, NULL, 0) ;  
//    MultiByteToWideChar (CP_ACP, 0, _char, strlen (_char) + 1, tchar, iLength) ;  
//}  
//
//void TcharToChar (const TCHAR * tchar, char * _char)  
//{  
//    int iLength ;  
////获取字节长度   
//iLength = WideCharToMultiByte(CP_ACP, 0, tchar, -1, NULL, 0, NULL, NULL);  
////将tchar值赋给_char    
//WideCharToMultiByte(CP_ACP, 0, tchar, -1, _char, iLength, NULL, NULL);   
//}  

//将char转换成wchar_t
//
//可以用TEXT()方法将char转换成wchar_t
//例如： wchar_t appName[5]=TEXT("test");
//方法2：
//wchar_t* c2w(const char *str)
//{
//int length = strlen(str)+1;
//wchar_t *t = (wchar_t*)malloc(sizeof(wchar_t)*length);
//memset(t,0,length*sizeof(wchar_t));
//MultiByteToWideChar(CP_ACP,0,str,strlen(str),t,length);
//return t;
//}