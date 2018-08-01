#include "BinarySearchTree2.h"
#include <stdio.h>
#include <stdlib.h>

void BSTMakeAndInit(BTreeNode ** pRoot)
{
	*pRoot = NULL;
}

BSTData BSTGetNodeData(BTreeNode * bst)
{
	return GetData(bst);
}

void BSTInsert(BTreeNode ** pRoot, BSTData data)
{
	BTreeNode * pNode = NULL;
	BTreeNode * cNode = *pRoot;
	BTreeNode * nNode = NULL;

	while (cNode != NULL)
	{
		if (data == GetData(cNode))
			return;

		pNode = cNode;

		if (GetData(cNode) > data)
			cNode = GetLeftSubTree(cNode);
		else
			cNode = GetRightSubTree(cNode);
	}

	nNode = MakeBTreeNode();
	SetData(nNode, data);

	if (pNode != NULL)
	{
		if (data < GetData(pNode))
			MakeLeftSubTree(pNode, nNode);
		else
			MakeRightSubTree(pNode, nNode);
	}
	else
	{
		*pRoot = nNode;
	}
}

BTreeNode * BSTSearch(BTreeNode * bst, BSTData target)
{
	BTreeNode * cNode = bst;
	BSTData cd;
	while (cNode != NULL)
	{
		cd = GetData(cNode);
		if (cd > target)
			cNode = GetLeftSubTree(cNode);
		else if (cd < target)
			cNode = GetRightSubTree(cNode);
		else
			return cNode;
	}
	return NULL;
}

BTreeNode * BSTRemove(BTreeNode ** pRoot, BSTData target)
{
	BTreeNode * pVRoot = MakeBTreeNode();
	BTreeNode * pNode = pVRoot;
	BTreeNode * cNode = *pRoot;
	BTreeNode * dNode = NULL;

	ChangeRightSubTree(pVRoot, *pRoot);

	while (cNode != NULL && GetData(cNode) != target)
	{
		pNode = cNode;

		if (target < GetData(cNode))
			cNode = GetLeftSubTree(cNode);
		else
			cNode = GetRightSubTree(cNode);
	}
	if (cNode == NULL)
		return NULL;

	dNode = cNode;

	if (GetLeftSubTree(dNode) == NULL && GetRightSubTree(cNode) == NULL)
	{
		if (GetLeftSubTree(pNode) == dNode)
			RemoveLeftSubTree(pNode);
		else
			RemoveRightSubTree(pNode);
	}

	else if (GetLeftSubTree(dNode) == NULL || GetRightSubTree(dNode) == NULL)
	{
		BTreeNode * dcNode = NULL;

		if (GetLeftSubTree(dNode) != NULL)
			dcNode = GetLeftSubTree(dNode);
		else
			dcNode = GetRightSubTree(dNode);

		if (GetLeftSubTree(pNode) == dNode)
			ChangeLeftSubTree(pNode, dcNode);
		else
			ChangeRightSubTree(pNode, dcNode);
	}

	else
	{
		BTreeNode * mNode = GetRightSubTree(dNode);
		BTreeNode * mpNode = dNode;
		int delData;
		while (GetLeftSubTree(mNode) != NULL)
		{
			mpNode = mNode;
			mNode = GetLeftSubTree(mNode);
		}

		delData = GetData(dNode);
		SetData(dNode, GetData(mNode));
		
		if (GetLeftSubTree(mpNode) == mNode)
			ChangeLeftSubTree(mpNode, GetRightSubTree(mNode));
		else
			ChangeRightSubTree(mpNode, GetRightSubTree(mNode));

		dNode = mNode;
		SetData(dNode, delData);
	}

	if (GetRightSubTree(pVRoot) != *pRoot)
		*pRoot = GetRightSubTree(pVRoot);

	free(pVRoot);
	return dNode;
}
BTreeNode * BSTRemoveK(BTreeNode ** pRoot, BSTData target)
{
	BTreeNode * delNode = *pRoot;
	BTreeNode * pNode = NULL;
	while (GetData(delNode) != target && delNode != NULL)
	{
		pNode = delNode;
		if (GetData(delNode) < target)
		{
			delNode = GetRightSubTree(delNode);
		}
		else if (GetData(delNode) > target)
		{
			delNode = GetLeftSubTree(delNode);
		}
	} 
	if (delNode == NULL) { return NULL; }
	if (delNode->left && delNode->right)
	{
		BTreeNode * temp = delNode->right;
		while (temp->left != NULL)
		{
			temp = temp->left;
		}
		SetData(delNode, GetData(temp));

		delNode = temp;
	}

	BTreeNode * delChild = GetRightSubTree(delNode) ? GetRightSubTree(delNode) : GetLeftSubTree(delNode);

	if (pNode)
	{
		if (delNode == pNode->left)
			pNode->left = delChild;
		else
			pNode->right = delChild;
	}
	else
	{
		*pRoot = delChild;
	}


	return delNode;
}

void ShowData(BSTData data)
{
	printf("%d ", data);
}

void BSTShowAll(BTreeNode * bst)
{
	InorderTraverse(bst, ShowData);
}