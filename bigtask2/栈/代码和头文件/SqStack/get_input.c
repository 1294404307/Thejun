#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_SILENCE_NONCONFORMING_TGMATH_H
#include <stdio.h>
#include <stdlib.h>
#include "get_input.h"
#include <string.h>
int get_input()
{
	char inputt, str[Putsize],str3[]="-1073741510";
	int i = 0, Input = 0;
	fflush(stdin);     // ������뻺��������ֹ�´����������Ӱ��
	scanf("%c", &inputt);
	if(inputt=='\n')   //��ֱ�ӵ���س�
	{
		system("cls");
		printf("\n\n\n\n\n\n\n\n\n\n\n\n");
		printf("%70s","****************************\n");
		printf("%70s","******��û�������κζ���****\n");
		printf("%70s","****************************\n");
		system("pause");
		system("cls");
//		printf("\n\n\n\n\n\n\n\n\n\n\n\n\n");
//		printf("%60s","������:");
		strcpy(str, str3);
		goto end;
	}

	//ͨ��ѭ�������ȡ�ַ���ֱ����ȡ���س�
	while (inputt != '\n')
	{
		if (i > Putsize)   //��������ַ���λ�����࣬����ElemType����ֵ�����Χʱ
		{
			system("cls");
			printf("\n\n\n\n\n\n\n\n\n\n\n\n");
			printf("%70s","***************************\n");
			printf("%70s","***�������������ֵ����**\n");
			printf("%70s","***************************\n");
			system("pause");
			system("cls");
//			printf("\n\n\n\n\n\n\n\n\n\n\n\n\n");
//			printf("%60s","������:");
			strcpy(str, str3);  //��str3��Ĵ��󷵻�ֵ��str������һ������ֵ���Ա�ʾ�������
			i = 0;
			goto end;  //�������ʱ��ֱ���˳�����
		}

		//���û���Ҫ���븺���������űض�ֻ�ܳ������ַ������±�Ϊ0��λ�ã����������ж�
		if (i==0)
		{
			if(inputt == '-')
			{
				str[i++]='-';
				str[i]='\0';
				scanf("%c", &inputt);
			}
		}

		//ͨ��ASCII��ֵɸѡ���������ִ������ַ����У��������֣���Ϊ�Ƿ�����
		if (inputt >= 48 && inputt <= 57)
		{
			str[i++] = inputt;
			str[i] = '\0';
		}
		else
		{
			system("cls");
			printf("\n\n\n\n\n\n\n\n\n\n\n\n");
			printf("%70s","***************************\n");
			printf("%70s","***�����������Ƿ��ַ�**\n");
			printf("%70s","***************************\n");
			system("pause");
			system("cls");
			strcpy(str, str3);
			i = 0;
//			printf("\n\n\n\n\n\n\n\n\n\n\n\n\n");
//			printf("%60s","������:");
			goto end;
		}
		scanf("%c", &inputt);
	}
	if(i==1 && str[1]=='-')  //�ж��Ƿ�ֻ�����˸��ţ����ֻ�����˸��ţ���Ҳ�ǲ��Ϸ�����
	{
			system("cls");
			printf("\n\n\n\n\n\n\n\n\n\n\n\n");
			printf("%70s","***************************\n");
			printf("%70s","***�����������Ƿ��ַ�**\n");
			printf("%70s","***************************\n");
			system("pause");
			system("cls");
	}
end:
	system("cls");
	fflush(stdin);
	Input = atoi(str);   //���ַ���strת��Ϊ��������
	return Input;
}
