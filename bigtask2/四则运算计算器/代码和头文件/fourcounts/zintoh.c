#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"
#include "zintoh.h"
#include "charstack.h"
char zintoh(char str[],int *z)
{
	charstack store;
	charinitstack(&store);   //��ʼ��һ�������ַ��Ľṹ��
	char c, e,str1[]="0";
	int i,j=0;
again_1:
	i = 0;
	strcpy(str,str1);
	printf("\n\n\n\n\n\n\n\n\n\n\n\n");
	printf("%95s","��������������ʽ(ע����#��Ϊ������־,����֮�������������),�˳���t:\n");
	printf("%55s","������:");
	scanf("%c",&c);
	if(c == 't')        //����tʱ�˳�����
	{
		return *z=0;
	}
	while(c!='#')
	{
		while(c>= '0' && c<='9')    //��������ʱ��ֱ����str����
		{
			str[i++] = c;
			str[i] = '\0';
			scanf("%c",&c);
			if(c < '0' ||c > '9')
			{
				str[i++] = ' ';
				str[i] = '\0';
			}
		}
		if(c == ')')      //��⵽����������ʱ��
		{
			if(store.top == store.bottom)    //���û�����Ϸ���ջ�о������ܳ��ֿ�ջ֮���ٳ�ջ�����������������ִ������������ض����ִ���
				goto default_1;
			charpop(&store,&e);

			//�����ŵ��������ڲ�������֮����������ȼ��ض����ұߵĴ�����ߵ�
			//���Կ�ͨ��ѭ����ջ�ڵ������ȫ����ջ
			while(e != '(')
			{
				str[i++] = e;
				str[i++] = ' ';
				str[i] = '\0';
				if(store.top == store.bottom)
					goto default_1;
				charpop(&store,&e);
			}
		}
		else if(c == '+' || c== '-')
		{

			//���ջ�ڳ���Ϊ0����ֱ����ջ
			if(!charstacklen(store))
			{
				charpush(&store,c);
			}

			//ջ���Ȳ�Ϊ0�����ж�ջ�ڵ�������Ƿ�Ϊ���ţ����Ϊ����
			//���������·���ջ�л������������
			//��Ϊ+-�ŵ����ȼ���ͣ�����ͬ������������+-����ջʱ��ֻҪ
			//�������ţ���ôǰһ����ջ��������ض���ջ
			else
			{
				do
				{
					if(store.top == store.bottom)
						goto default_1;
					charpop(&store,&e);
					if(e == '(')
					{
						charpush(&store,e);
					}
					else
					{
						str[i++] = e;
						str[i++] = ' ';
						str[i] = '\0';
					}
				}while(e !='(' && charstacklen(store));
				charpush(&store,c);
			}
		}
		else if(c == '*' || c == '/' || c == '(')   //��������ȼ���ߣ���ȫ����ջ
		{
			charpush(&store,c);
		}
		else if(c== '#')   //����������־���ַ���������ɣ�����ѭ��
		{
			break;
		}

		else   //����Ƿ��ַ�����û������#�����������������������
		{
		default_1:

			//��������ʱ�����ջ��գ���ȻӰ���������
			while(charstacklen(store))
			{
				charpop(&store,&e);

			}
			system("cls");
			fflush(stdin);
			printf("\n\n\n\n\n\n\n\n\n\n\n");
			printf("%70s","***************************\n");
			printf("%70s","**�����ʽ����,����������**\n");
			printf("%70s","***************************\n");
			system("pause");
			system("cls");
			goto again_1;
		}
		scanf("%c",&c);
	}

	//��û�г�ջ���ַ���ջ��str����
	while(charstacklen(store))
	{
		charpop(&store,&e);
		str[i++] = e;
		str[i++]=' ';
	}
	str[i++] = '#';
	str[i] = '\0';
	system("cls");
	printf("\n\n\n\n\n\n\n\n\n\n\n\n");
	printf("%50s","ת��Ϊ��׺���ʽΪ:");
	while(str[j] != '#')
	{
		printf("%c",str[j++]);
	}
	printf("\n");
	system("pause");
	return *str;
}
