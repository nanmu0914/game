#ifndef _DELINE_H
#define _DELINE_H
 
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
 
//��ʾϵͳʱ��
void showtime();
//��������
void paintheart();
//�����û���
int scanfuser();
//��������
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
	//���κ���
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
	//�����û�������
	char user[100];
 
	//��ӡ����
	printf("�û�����");
 
	//�����û��������浽user������
	scanf("%s",user);
 
	//printf("%s",user);
 
	//���û�����Ϣ������data.txt�ļ���
	FILE *fpWrite=fopen("data.txt","a+");
 
	//�ɹ������ļ�ʱ
	if(fpWrite)
	{	
		//��Ϊ��ʱ����ַ�����
		for(int i=0;user[i]!='\0';i++)
		{
			fprintf(fpWrite,"%c",user[i]);
		}
 
	//�ر��ļ�
	fclose(fpWrite);
 
	//�ͷ�ָ��
	fpWrite=NULL;
	}
	return 0;
}
//scanfpassword.cpp
