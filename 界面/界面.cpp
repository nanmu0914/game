#ifndef _DELINE_H
#define _DELINE_H
 
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
 
//显示系统时间
void showtime();
//绘制心形
void paintheart();
//输入用户名
int scanfuser();
//输入密码
int scanfpassword();
 
#endif
//showtime.cpp
 

 
void showtime()
{
	time_t timep;
	char s[30];
	time(&timep);
	strcpy(s,ctime(&timep));
	printf("%s", s);
}
//paintheart.cpp
 

 
void paintheart()
{
	//心形函数
	for (float y = 1.5f; y > -1.5f; y -= 0.1f) 
	{
        for (float x = -1.5f; x < 1.5f; x += 0.05f)
		{
            float a = x * x + y * y - 1;
            putchar(a * a * a - x * x * y * y * y <= 0.0f ? '*' : ' ');
        }
        putchar('\n');
    }
}
//scanfuser.cpp
 

 
int scanfuser()
{
	//定义用户名数组
	char user[100];
 
	//打印文字
	printf("用户名：");
 
	//输入用户名并保存到user数组中
	scanf("%s",user);
 
	//printf("%s",user);
 
	//将用户名信息保存在data.txt文件中
	FILE *fpWrite=fopen("data.txt","a+");
 
	//成功创建文件时
	if(fpWrite)
	{	
		//不为空时逐个字符保存
		for(int i=0;user[i]!='\0';i++)
		{
			fprintf(fpWrite,"%c",user[i]);
		}
 
	//关闭文件
	fclose(fpWrite);
 
	//释放指针
	fpWrite=NULL;
	}
	return 0;
}
//scanfpassword.cpp
