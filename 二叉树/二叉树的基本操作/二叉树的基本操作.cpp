// �������Ļ�������.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "bTree.h"
#include <iostream>
using namespace std;

int main()
{
	
	BiTree T;
	printf("���򴴽�һ�ö�����\n");
	//����������
	CreateBiTree(T);
	//���Ա�������
	printf("���������\n");
	PreOrderTraverse(T);
	printf("\n");
	printf("���������\n");
	InOrderTraverse(T);
	printf("\n");
	printf("���������\n");
	PostOderTraverse(T);
	printf("\n");
	//���Լ���Ҷ�ӽڵ�ĺ���
	int count = CountLeaf(T);
	printf("Ҷ�ӽڵ���Ϊ%d\n", count);
	//����������ȵĺ���
	int depth = Depth(T);
	printf("���������Ϊ%d\n", depth);
	
	getchar();
	char elem;
	printf("������һ���ڵ��ֵ��");
	scanf_s("%c", &elem);
	//��һ�ڵ�ĸ��ڵ�
	//Parent(T, elem);
	//��һ�ڵ�����Ӻ��Һ���
	//LeftChild(T, elem);
	//RightChild(T, elem);
	////��һ�ڵ�����ֵ����ֵ�
	LeftSibling(T, elem);
	RightSibling(T, elem);

	system("pause");
    return 0;
}

