#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "zintoh.h"
#include "calculate.h"
#include "get_input.h"
int main()
{
	char Str[Size];          //����һ��Str�������û�����׺���ʽ������ı��ʽ��
	int choice, out_1, out_2;
again:
	system("cls");
	printf("\n\n\n\n\n\n\n\n\n\n\n");
	printf("%70s","***************************\n");
	printf("%70s","**1�����������  2���˳�***\n");
	printf("%70s","***************************\n");
	printf("\n\n");
	printf("%60s","��ѡ��ѡ��:");
	choice=get_input();        //get_input��������ɸѡ���Ϸ�������
	switch(choice)
	{
	case 1:
		zintoh(Str,&out_1);    //��׺���ʽ��Ϊ��׺���ʽ
		if(out_1 == 0)       //����������������t�����out_1��ֵΪ0������˳�����
		{
			goto end;      //ֱ���˳�
		}
		out_2=calculate(Str);  //���ú�׺���ʽ���м���
		if (out_2 == -1)       //����׺���ʽ���벻��Ҫ��ת��Ϊ��׺���ʽʱ����ִ��󣬳��ִ���ʱ����-1��ʾ������ʾ�û��ٴ�����ѡ��
			goto nonend;
		goto again;
	case 2:
	end:
		system("cls");
		printf("\n\n\n\n\n\n\n\n\n\n\n");
		printf("%70s","***************************\n");
		printf("%70s","********* �˳����� ********\n");
		printf("%70s","***************************\n");
		break;
	default:
	nonend:
		system("cls");
		printf("\n\n\n\n\n\n\n\n\n\n\n");
		printf("%70s","***************************\n");
		printf("%70s","****�����������������***\n");
		printf("%70s","***************************\n");
		system("pause");
		system("cls");
		goto again;
	}


	return 0;
}
