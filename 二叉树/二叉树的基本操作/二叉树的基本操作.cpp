// 二叉树的基本操作.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "bTree.h"
#include <iostream>
using namespace std;

int main()
{
	
	BiTree T;
	printf("先序创建一棵二叉树\n");
	//创建二叉树
	CreateBiTree(T);
	//测试遍历函数
	printf("先序遍历：\n");
	PreOrderTraverse(T);
	printf("\n");
	printf("中序遍历：\n");
	InOrderTraverse(T);
	printf("\n");
	printf("后序遍历：\n");
	PostOderTraverse(T);
	printf("\n");
	//测试计算叶子节点的函数
	int count = CountLeaf(T);
	printf("叶子节点数为%d\n", count);
	//测试求树深度的函数
	int depth = Depth(T);
	printf("该树的深度为%d\n", depth);
	
	getchar();
	char elem;
	printf("请输入一个节点的值：");
	scanf_s("%c", &elem);
	//求一节点的父节点
	//Parent(T, elem);
	//求一节点的左孩子和右孩子
	//LeftChild(T, elem);
	//RightChild(T, elem);
	////求一节点的左兄弟右兄弟
	LeftSibling(T, elem);
	RightSibling(T, elem);

	system("pause");
    return 0;
}

