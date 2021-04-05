#include <stdio.h>
#include <stdlib.h>
#include "SqStack.h"

Status initStack(SqStack *s,int sizes)
{
	s->elem=(ElemType *)malloc(sizes*sizeof(ElemType));    //��s->elem�����ʼ�ڴ�ռ�
	if(! s->elem)   //����ʧ��ʱ
	{
		printf("\n\n\n\n\n\n\n\n\n\n\n\n");
		printf("%70s","****************************\n");
		printf("%70s","*********��ʼ��ʧ��*********\n");
		printf("%70s","****************************\n");
		system("pause");
		system("cls");
		return ERROR;
	}
	s->top=-1;      //��ʾ��ջ
	s->size=sizes;     //��ʼ��ջ����󳤶�
	printf("\n\n\n\n\n\n\n\n\n\n\n\n");
	printf("%70s","****************************\n");
	printf("%70s","*********��ʼ���ɹ�*********\n");
	printf("%70s","****************************\n");
	system("pause");
	system("cls");
	//*(s->elem)=NULL��
	return SUCCESS;
}

Status isEmptyStack(SqStack *s)
{
	if(s->top == -1)   //��ʾ��ջʱ
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

Status getTopStack(SqStack *s,ElemType *e)
{
	if(s->top==-1)
	{
		printf("\n\n\n\n\n\n\n\n\n\n\n\n");
		printf("%70s","****************************\n");
		printf("%70s","******��ջ����ջ��Ԫ��******\n");
		printf("%70s","****************************\n");
		system("pause");
		system("cls");
	}
	else
	{
		(*e)=*((s->elem)+(s->top));     //��ջ��Ԫ�صĸ�ֵ
		printf("\n\n\n\n\n\n\n\n\n\n\n\n");
		printf("%70s","****************************\n");
		printf("%42s","*");
		printf("******ջ��Ԫ��Ϊ:%-d  *******\n",*e);
		printf("%70s","****************************\n");
		system("pause");
		system("cls");
	}
	return SUCCESS;
}

Status clearStack(SqStack *s)
{
	//ͨ��ѭ�������ջ
	while(s->top!=-1)
	{
		free((s->elem)+(s->top));
		s->top--;      //���һ��ջ������ָһ��
	}
	printf("\n\n\n\n\n\n\n\n\n\n\n\n");
	printf("%70s","****************************\n");
	printf("%70s","**********ջ�����**********\n");
	printf("%70s","****************************\n");
	system("pause");
	system("cls");
	return SUCCESS;
}

Status destroyStack(SqStack *s)
{
	while(s->top!=-1)
	{
		free((s->elem)+(s->top));
		s->top--;
	}
	s->top=-2;          //��ʾջ�����٣���Ҫ��������
	printf("\n\n\n\n\n\n\n\n\n\n\n\n");
	printf("%70s","****************************\n");
	printf("%70s","**********ջ������**********\n");
	printf("%70s","****************************\n");
	system("pause");
	system("cls");
	return SUCCESS;
}

Status stackLength(SqStack *s,int *length)
{
	(*length)=(s->top) + 1;    //s->top��ʾ�±꣬���ȵ����±��1
	printf("\n\n\n\n\n\n\n\n\n\n\n\n");
	printf("%70s","****************************\n");
	printf("%42s","*");
	printf("******ջ�ĳ���Ϊ:%d ********\n",*length);
	printf("%70s","****************************\n");
	system("pause");
	system("cls");
	return SUCCESS;
}

Status pushStack(SqStack *s,ElemType data)
{
	(s->top)++;
	if(s->top==0)
	{
		s->elem=(ElemType *)malloc(initsize*sizeof(ElemType));    //������ջ��ջ����С�����٣����ٴη����ڴ�ռ�
	}

	//��ջ������ջ�������ռ�
	if(s->top>= s->size)
	{
		s->elem=(ElemType *)realloc(s->elem,(s->size + addsize)*sizeof(ElemType));
		s->size+=addsize;
	}
	(*((s->elem)+(s->top)))=data;
	printf("\n\n\n\n\n\n\n\n\n\n\n\n");
	printf("%70s", "***************************\n");
	printf("%70s", "**********�ѽ�ջ***********\n");
	printf("%70s", "***************************\n");
	system("pause");
	system("cls");
	return SUCCESS;
}

Status popStack(SqStack *s,ElemType *data)
{
	if(s->top==-1)    //��Ϊ��ջ���µ�ջ����յ����
	{
		printf("\n\n\n\n\n\n\n\n\n\n\n\n");
		printf("%70s","****************************\n");
		printf("%70s","*****ջ����գ��޷���ջ*****\n");
		printf("%70s","****************************\n");
		system("pause");
		system("cls");
	}
	else
	{
		(*data)=*((s->elem)+(s->top));
		(s->top)--;
		free((s->elem)+((s->top)+1));
		printf("\n\n\n\n\n\n\n\n\n\n\n\n");
		printf("%70s","****************************\n");
		printf("%42s","*");
		printf("*******��ջԪ��Ϊ:%d *******\n",*data);
		printf("%70s","****************************\n");
		system("pause");
		system("cls");
	}
	return SUCCESS;
}
