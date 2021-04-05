#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_SILENCE_NONCONFORMING_TGMATH_H
#include <stdio.h>
#include <stdlib.h>
#include "LinkStack.h"
#include "menu.h"
#include "get_input.h"
void choice()
{
	LinkStack stack;
	stack.count=-1;    //ͨ���ж�count�Ƿ�Ϊ-1���ж�ջ�Ƿ����
	int input, Length;
	ElemType Data, E;
again:
	menu();    //��ӡ�˵�����
	printf("\n\n");
	printf("%60s","��ѡ��ѡ��:");
	input=get_input();     //get_input��������ɸѡ�����˵����Ϸ������룬��󽫺Ϸ����뷵�ظ�input
	system("cls");
	if(input==-1073741510)
	{
		printf("\n\n\n\n\n\n\n\n\n\n\n\n");
		printf("%70s","****************************\n");
		printf("%70s","*********����������*********\n");
		printf("%70s","****************************\n");
		system("pause");
		system("cls");
		goto again;
	}

	//�ڴ˹涨countΪ-1��ʱ��û������ջ������ʹ��û����ջ��ʱ���ܽ�������ѡ��
	if(stack.count == -1)
	{
		if(input!= 1 && input!=9)
		{
//			system("cls");
			printf("\n\n\n\n\n\n\n\n\n\n\n\n");
			printf("%70s","****************************\n");
			printf("%70s","***ջ��û���ɣ���������ջ***\n");
			printf("%70s","****************************\n");
			system("pause");
			system("cls");
			goto again;
		}
	}

	switch(input)
	{
	case 1:
		initLStack(&stack);  //����ջ
		goto again;
	case 2:
		isEmptyLStack(&stack);  //�ж��Ƿ�Ϊ��ջ
		goto again;
	case 3:
		getTopLStack(&stack,&E);   //�õ�ջ��Ԫ��
		goto again;
	case 4:
		clearLStack(&stack);   //���ջ
		goto again;
	case 5:
		destroyLStack(&stack);  //����ջ
		goto again;
	case 6:
		LStackLength(&stack,&Length);    //����ջ�ĳ���
		goto again;
	case 7:
		printf("\n\n\n\n\n\n\n\n\n\n\n\n");
		printf("%70s","****************************\n");
		printf("%70s","****��������������ջ��ֵ:***\n");
		printf("%70s","****************************\n");
		system("pause");
		system("cls");
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\n");
		printf("%60s","������:");
		Data=get_input();      //ʹ��Data���պϷ�����ֵ
		if(Data==-1073741510)     //�����ش�ֵ�������벻��ȷ��ʹ�û���������
		{
			goto again;
		}
		pushLStack(&stack,Data);
		goto again;
	case 8:
		popLStack(&stack,&Data);     //��ջ
		goto again;
	case 9:
		printf("\n\n\n\n\n\n\n\n\n\n\n\n");
		printf("%70s","****************************\n");
		printf("%70s","***********���˳�:**********\n");
		printf("%70s","****************************\n");
		break;
	default:
		printf("\n\n\n\n\n\n\n\n\n\n\n\n");
		printf("%70s","****************************\n");
		printf("%70s","****�����������������:***\n");
		printf("%70s","****************************\n");
		system("pause");
		system("cls");
		goto again;
	}
}
