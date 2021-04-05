#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_SILENCE_NONCONFORMING_TGMATH_H
#include "LinkStack.h"
#include <stdio.h>
#include <stdlib.h>
Status initLStack(LinkStack *s)
{
	s->top=(LinkStackPtr)malloc(sizeof(StackNode));   //������ʼ�ڴ�ռ�
	if(!s->top)  //����ʧ��ʱ
	{
		printf("\n\n\n\n\n\n\n\n\n\n\n\n");
		printf("%70s","****************************\n");
		printf("%70s","*********��ʼ��ʧ��*********\n");
		printf("%70s","****************************\n");
		system("pause");
		system("cls");
		return ERROR;
	}
	s->top->next=NULL;
	s->count=0;            //ջ�ĳ���Ϊ0����ʾ��ջ
	printf("\n\n\n\n\n\n\n\n\n\n\n\n");
	printf("%70s","****************************\n");
	printf("%70s","*********��ʼ���ɹ�*********\n");
	printf("%70s","****************************\n");
	system("pause");
	system("cls");
	return SUCCESS;
}

Status isEmptyLStack(LinkStack *s)
{
	if(s->count==0)     //ջ����Ϊ0ʱ
	{
		printf("\n\n\n\n\n\n\n\n\n\n\n\n");
		printf("%70s","****************************\n");
		printf("%70s","**********ջΪ��ջ**********\n");
		printf("%70s","****************************\n");
		system("pause");
		system("cls");
	}
	else
	{
		printf("\n\n\n\n\n\n\n\n\n\n\n\n");
		printf("%70s","****************************\n");
		printf("%70s","*********ջ��Ϊ��ջ*********\n");
		printf("%70s","****************************\n");
		system("pause");
		system("cls");
	}
	return SUCCESS;
}

Status getTopLStack(LinkStack *s,ElemType *e)
{
	if(s->count == 0)
	{
		printf("\n\n\n\n\n\n\n\n\n\n\n\n");
		printf("%70s","****************************\n");
		printf("%70s","******��ջ����ջ��Ԫ��******\n");
		printf("%70s","****************************\n");
		system("pause");
		system("cls");
		return SUCCESS;
	}
	printf("\n\n\n\n\n\n\n\n\n\n\n\n");
	printf("%70s","****************************\n");
	printf("%42s","*");
	printf("******ջ��Ԫ��Ϊ:%d ********\n",s->top->data);
	printf("%70s","****************************\n");
	system("pause");
	system("cls");
	return SUCCESS;
}

Status clearLStack(LinkStack *s)
{
	StackNode *temp;   //������ʱ����ջ������һ��

	//ѭ�������ջ�е�Ԫ�أ�ount=0ʱ��ʾ������
	while(s->count!=0)
	{
	temp=s->top->next;
	free(s->top);
	s->top=temp;
	s->count--;
	}
	printf("\n\n\n\n\n\n\n\n\n\n\n\n");
	printf("%70s","****************************\n");
	printf("%70s","**********ջ�����**********\n");
	printf("%70s","****************************\n");
	system("pause");
	system("cls");
	return SUCCESS;
}

Status destroyLStack(LinkStack *s)
{
	StackNode *temp;

	//ѭ�����ͷ�ջ�е�Ԫ��
	while(s->count!=0)
	{
	temp=s->top->next;
	free(s->top);
	s->top=temp;
	s->count--;
	}
	s->count=-1;  //��count����-1��ʾ�Ѿ�����
	printf("\n\n\n\n\n\n\n\n\n\n\n\n");
	printf("%70s","****************************\n");
	printf("%70s","**********ջ������**********\n");
	printf("%70s","****************************\n");
	system("pause");
	system("cls");
	return SUCCESS;
}
Status LStackLength(LinkStack *s,int *length)
{
	(*length)=s->count;
	printf("\n\n\n\n\n\n\n\n\n\n\n\n");
	printf("%70s","****************************\n");
	printf("%42s","*");
	printf("******ջ�ĳ���Ϊ:%d  *******\n",*length);
	printf("%70s","****************************\n");
	system("pause");
	system("cls");
	return SUCCESS;
}

Status pushLStack(LinkStack *s,ElemType data)
{
	if(s->count==0)   ////������ջ��ջ����С�����٣����ٴη����ڴ�ռ�
	{
		s->top=(LinkStackPtr)malloc(sizeof(StackNode));
		s->top->data=data;
		s->top->next=NULL;
	}
	else
	{
		LinkStack temp;
		temp.top=(LinkStackPtr)malloc(sizeof(StackNode));     //��һ��ջ����Ҫ�����һ���ڴ�ռ�
		temp.top->data = data;
		temp.top->next=s->top;
		s->top=temp.top;
	}
	printf("\n\n\n\n\n\n\n\n\n\n\n\n");
	printf("%70s", "***************************\n");
	printf("%70s", "**********�ѽ�ջ***********\n");
	printf("%70s", "***************************\n");
	system("pause");
	system("cls");
	s->count++;
	return SUCCESS;
}

Status popLStack(LinkStack *s,ElemType *data)
{
	if(s->count == 0)
	{
		printf("\n\n\n\n\n\n\n\n\n\n\n\n");
		printf("%70s","****************************\n");
		printf("%70s","*****ջ����գ��޷���ջ*****\n");
		printf("%70s","****************************\n");
		system("pause");
		system("cls");
		printf("ջ����գ��޷���ջ\n");
	}
	else
	{
		(*data)=s->top->data;
		printf("\n\n\n\n\n\n\n\n\n\n\n\n");
		printf("%70s","****************************\n");
		printf("%42s","*");
		printf("*******��ջԪ��Ϊ:%d *******\n",*data);
		printf("%70s","****************************\n");
		//free(s->top);
		s->top=s->top->next;   //��ջ��ջ��������
		s->count--;
		system("pause");
		system("cls");
	}
	return SUCCESS;
}
