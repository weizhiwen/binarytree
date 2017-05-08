#pragma once
#include <iostream>
using namespace std;

//定义二叉树结点的结构体
typedef struct BiTNode {
	char data; //结点数据
	struct BiTNode *lChild, *rChild; //该结点的左孩子和右孩子
}BiTNode, *BiTree;

//以先序方式创建二叉树
int CreateBiTree(BiTree &T)
{
	char data;
	//printf("输入该结点的值\n");
	data = getchar(); //单个字符输入
	//getchar();
	if (data == ' ')
		T = NULL;
	else
	{
		if (!(T = (BiTNode*)malloc(sizeof(BiTNode))))
		{
			printf("内存分配失败！\n");
			return 0;
		}
		T->data = data;
		CreateBiTree(T->lChild);
		CreateBiTree(T->rChild);
	}
	return 1;
}

//以递归先序遍历二叉树
void PreOrderTraverse(BiTree &T)
{
	if (T)
	{
		printf("%c", T->data); //输出根结点的值
		PreOrderTraverse(T->lChild); //遍历左子树
		PreOrderTraverse(T->rChild); //遍历右子树
	}
}

//以递归中序遍历二叉树
void InOrderTraverse(BiTree &T)
{
	if (T)
	{
		InOrderTraverse(T->lChild); //遍历左子树
		printf("%c", T->data); //输出根结点的值
		InOrderTraverse(T->rChild); //遍历右子树
	}
}

//以递归后序遍历二叉树
void PostOderTraverse(BiTree &T)
{
	if (T)
	{
		PostOderTraverse(T->lChild); //遍历左子树
		PostOderTraverse(T->rChild); //遍历右子树
		printf("%c", T->data); //输出根结点的值
	}
}

//计算叶子节点数
int CountLeaf(BiTree &T)
{
	int static count = 0;
	if (T)
	{
		//判断该节点是不是叶子节点
		if (T->lChild == NULL && T->rChild == NULL)
			count++;
		CountLeaf(T->lChild);
		CountLeaf(T->rChild);
	}
	return count;
}

//求树的深度
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

//求节点的左孩子
void LeftChild(BiTree T, char elem)
{
	if (T != NULL)
	{
		if (elem == T->data) //如果找到了该节点
		{
			if (T->lChild) //并且该节点有左节点
				printf("该节点的左孩子为%c\n", T->lChild->data);
			else
				printf("该节点没有左孩子\n");
		}
		else
		{//递归查找
			LeftChild(T->lChild, elem);
			LeftChild(T->rChild, elem);
		}
	}
	
}

//求节点的右孩子
void RightChild(BiTree T, char elem)
{
	if (T != NULL)
	{
		if (elem == T->data) //如果找到了该节点
		{
			if (T->rChild) //并且该节点有右节点
				printf("该节点的右孩子为%c\n", T->rChild->data);
			else
				printf("该节点没有右孩子\n");
		}
		else
		{//递归查找
			RightChild(T->lChild, elem);
			RightChild(T->rChild, elem);
		}
	}
}

//求节点的左兄弟
void LeftSibling(BiTree &T, char elem)
{
	if (T != NULL)
	{
		if (T->data == elem)
			printf("该节点为根结点，没有左兄弟\n");
		else if (T->lChild != NULL && T->lChild->data == elem)
			printf("该节点为左节点，没有左兄弟\n");
		else if (T->rChild != NULL && T->rChild->data == elem)
			printf("该节点的左兄弟为%c\n", T->lChild->data);
		else
		{
			LeftSibling(T->lChild, elem);
			LeftSibling(T->rChild, elem);
		}
	}
}

//求节点的右兄弟
void RightSibling(BiTree &T, char elem)
{
	if (T != NULL)
	{
		if (T->data == elem)
			printf("该节点为根结点，没有右兄弟\n");
		else if (T->rChild != NULL && T->rChild->data == elem)
			printf("该节点为右节点，没有右兄弟\n");
		else if (T->lChild != NULL && T->lChild->data == elem)
			printf("该节点的右兄弟为%c\n", T->rChild->data);
		else
		{
			RightSibling(T->lChild, elem);
			RightSibling(T->rChild, elem);
		}
	}
}

//求该节点的父节点
void Parent(BiTree &T, char elem)
{
	if (T != NULL)
	{
		if (T->data == elem)
			printf("该节点为根节点\n");
		if ((T->lChild != NULL && T->lChild->data == elem) || (T->rChild != NULL && T->rChild->data == elem))
			printf("父节点为%c\n", T->data);
		else
		{
			Parent(T->lChild, elem);
			Parent(T->rChild, elem);
		}
	}
}