#pragma once
#include <iostream>
using namespace std;

//������������Ľṹ��
typedef struct BiTNode {
	char data; //�������
	struct BiTNode *lChild, *rChild; //�ý������Ӻ��Һ���
}BiTNode, *BiTree;

//������ʽ����������
int CreateBiTree(BiTree &T)
{
	char data;
	//printf("����ý���ֵ\n");
	data = getchar(); //�����ַ�����
	//getchar();
	if (data == ' ')
		T = NULL;
	else
	{
		if (!(T = (BiTNode*)malloc(sizeof(BiTNode))))
		{
			printf("�ڴ����ʧ�ܣ�\n");
			return 0;
		}
		T->data = data;
		CreateBiTree(T->lChild);
		CreateBiTree(T->rChild);
	}
	return 1;
}

//�Եݹ��������������
void PreOrderTraverse(BiTree &T)
{
	if (T)
	{
		printf("%c", T->data); //���������ֵ
		PreOrderTraverse(T->lChild); //����������
		PreOrderTraverse(T->rChild); //����������
	}
}

//�Եݹ��������������
void InOrderTraverse(BiTree &T)
{
	if (T)
	{
		InOrderTraverse(T->lChild); //����������
		printf("%c", T->data); //���������ֵ
		InOrderTraverse(T->rChild); //����������
	}
}

//�Եݹ�������������
void PostOderTraverse(BiTree &T)
{
	if (T)
	{
		PostOderTraverse(T->lChild); //����������
		PostOderTraverse(T->rChild); //����������
		printf("%c", T->data); //���������ֵ
	}
}

//����Ҷ�ӽڵ���
int CountLeaf(BiTree &T)
{
	int static count = 0;
	if (T)
	{
		//�жϸýڵ��ǲ���Ҷ�ӽڵ�
		if (T->lChild == NULL && T->rChild == NULL)
			count++;
		CountLeaf(T->lChild);
		CountLeaf(T->rChild);
	}
	return count;
}

//���������
int max(int a, int b)
{
	return a > b ? a : b;
}

int Depth(BiTree &T)
{
	if (!T)
		return 0;
	else
		return 1 + max(Depth(T->lChild), Depth(T->rChild));
}

//��ڵ������
void LeftChild(BiTree T, char elem)
{
	if (T != NULL)
	{
		if (elem == T->data) //����ҵ��˸ýڵ�
		{
			if (T->lChild) //���Ҹýڵ�����ڵ�
				printf("�ýڵ������Ϊ%c\n", T->lChild->data);
			else
				printf("�ýڵ�û������\n");
		}
		else
		{//�ݹ����
			LeftChild(T->lChild, elem);
			LeftChild(T->rChild, elem);
		}
	}
	
}

//��ڵ���Һ���
void RightChild(BiTree T, char elem)
{
	if (T != NULL)
	{
		if (elem == T->data) //����ҵ��˸ýڵ�
		{
			if (T->rChild) //���Ҹýڵ����ҽڵ�
				printf("�ýڵ���Һ���Ϊ%c\n", T->rChild->data);
			else
				printf("�ýڵ�û���Һ���\n");
		}
		else
		{//�ݹ����
			RightChild(T->lChild, elem);
			RightChild(T->rChild, elem);
		}
	}
}

//��ڵ�����ֵ�
void LeftSibling(BiTree &T, char elem)
{
	if (T != NULL)
	{
		if (T->data == elem)
			printf("�ýڵ�Ϊ����㣬û�����ֵ�\n");
		else if (T->lChild != NULL && T->lChild->data == elem)
			printf("�ýڵ�Ϊ��ڵ㣬û�����ֵ�\n");
		else if (T->rChild != NULL && T->rChild->data == elem)
			printf("�ýڵ�����ֵ�Ϊ%c\n", T->lChild->data);
		else
		{
			LeftSibling(T->lChild, elem);
			LeftSibling(T->rChild, elem);
		}
	}
}

//��ڵ�����ֵ�
void RightSibling(BiTree &T, char elem)
{
	if (T != NULL)
	{
		if (T->data == elem)
			printf("�ýڵ�Ϊ����㣬û�����ֵ�\n");
		else if (T->rChild != NULL && T->rChild->data == elem)
			printf("�ýڵ�Ϊ�ҽڵ㣬û�����ֵ�\n");
		else if (T->lChild != NULL && T->lChild->data == elem)
			printf("�ýڵ�����ֵ�Ϊ%c\n", T->rChild->data);
		else
		{
			RightSibling(T->lChild, elem);
			RightSibling(T->rChild, elem);
		}
	}
}

//��ýڵ�ĸ��ڵ�
void Parent(BiTree &T, char elem)
{
	if (T != NULL)
	{
		if (T->data == elem)
			printf("�ýڵ�Ϊ���ڵ�\n");
		if ((T->lChild != NULL && T->lChild->data == elem) || (T->rChild != NULL && T->rChild->data == elem))
			printf("���ڵ�Ϊ%c\n", T->data);
		else
		{
			Parent(T->lChild, elem);
			Parent(T->rChild, elem);
		}
	}
}