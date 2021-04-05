#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_SILENCE_NONCONFORMING_TGMATH_H
#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "get_input.h"
#include "SqStack.h"
void choice()
{
	SqStack stack;

	stack.top=-2;
	int input, Length;
	ElemType Data, E;
again:
	menu();       //��ӡ�˵�����
	printf("\n\n");
	printf("%60s","��ѡ��ѡ��:");
	input=get_input();   //get_input��������ɸѡ�����˵����Ϸ������룬��󽫺Ϸ����뷵�ظ�input
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
	if(stack.top == -2)   //�ڴ˹涨topΪ-2��ʱ��û������ջ
	{

		if(input!= 1 && input!=9)    //ʹ��û����ջ��ʱ���ܽ�������ѡ��
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
		initStack(&stack,initsize);  //����ջ
		goto again;
	case 2:
		isEmptyStack(&stack); //����ջ�Ƿ�Ϊ��
		goto again;
	case 3:
		getTopStack(&stack,&E);   //�õ�ջ��Ԫ��
		goto again;
	case 4:
		clearStack(&stack);    //���ջ
		goto again;
	case 5:
		destroyStack(&stack);    //����ջ
		goto again;
	case 6:
		stackLength(&stack,&Length);   //����ջ�ĳ���
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
		Data=get_input();     //ʹ��Data���պϷ�����ֵ
		if(Data==-1073741510)   //�����ش�ֵ�������벻��ȷ��ʹ�û���������
		{
			goto again;
		}
		pushStack(&stack,Data);    //��ջ
		goto again;
	case 8:
		popStack(&stack,&Data);   //��ջ
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
