#include <stdio.h>
#include <stdlib.h>
#include "BinaryTree.h"

BTreeNode * MakeBTreeNode(void)
{
	BTreeNode * nd = (BTreeNode*)malloc(sizeof(BTreeNode));

	nd->Left = NULL;
	nd->Right = NULL;
	return nd;
}

BTData GetData(BTreeNode * bt)
{
	return bt->data;
}

void SetData(BTreeNode * bt, BTData data)
{
	bt->data = data;
}

BTreeNode * GetLeftSubTree(BTreeNode * bt)
{
	return bt->Left;
}

BTreeNode * GetRightSubTree(BTreeNode * bt)
{
	return bt->Right;
}

void MakeLeftSubTree(BTreeNode * main, BTreeNode * sub)
{
	if(main->Left != NULL)
		free(main->Left);

	main->Left = sub;
}

void MakeRightSubTree(BTreeNode * main, BTreeNode * sub)
{
	if(main->Right != NULL)
		free(main->Right);

	main->Right = sub;
}
