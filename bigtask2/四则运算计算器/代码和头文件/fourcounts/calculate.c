#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "calculate.h"
#include "zintoh.h"
#include "stack.h"
int calculate(char str[])
{
	sqstack store;
	initstack(&store);
	elemtype last,former,sum;
	char strl[Size], strll[] = "0";

	int i=0,m=0;
again:
	//ͨ��ѭ���������ȡstr�н��յ����ַ���
	while(str[m]!='#' || str[m]== ' ')
	{
		if(str[m] == ' ')  //���յ��ո��������ո������һ���ַ�
		{
			m++;
			goto again;
		}

		//�������־�����ջ��
		if (str[m] >= '0' && str[m] <= '9')
		{
			while (str[m] >= '0' && str[m] <= '9')
			{
				strl[i++] = str[m];
				strl[i] = '\0';
				m++;
				if (str[m] == ' ')
				{
					sum = atof(strl);
					push(&store, sum);
				}
			}
			i = 0;
			strcpy(strl, strll);
			goto again;
		}

		//����������Ͱ�ջ�е�����ȥ���������ִ�ջ��ȡ������������
		switch(str[m])
		{
		case '+':
			if (store.top - store.bottom < 2)   //���û�������ȷ����ÿ������֮ǰ�ض�����������ջ�У������û��������
				goto end_1;     //����������˳����㴰�ڣ���ʾ�û�����ѡ������
			pop(&store,&last);
			pop(&store,&former);
			sum=former + last;
			push(&store,sum);
			m++;
			goto again;
		case '-':
			if (store.top - store.bottom < 2)
				goto end_1;
			pop(&store,&last);
			pop(&store,&former);
			sum=former - last;
			push(&store,sum);
			m++;
			goto again;
		case '*':
			if (store.top - store.bottom < 2)
				goto end_1;
			pop(&store,&last);
			pop(&store,&former);
			sum=former * last;
			push(&store,sum);
			m++;
			goto again;
		case '/':
			if (store.top - store.bottom < 2)
				goto end_1;
			pop(&store,&last);
			pop(&store,&former);
			sum=former / last;
			push(&store,sum);
			m++;
			goto again;
		}
	}
	system("cls");
	printf("\n\n\n\n\n\n\n\n\n\n\n\n");
	printf("%70s","***************************\n");
	printf("%40s","*");
	printf("*********������Ϊ:%3.2f*******\n",sum);
	printf("%70s","***************************\n");
	system("pause");
	return 1;
end_1:
	return -1;
}
