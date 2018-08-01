#include "BinaryTree3.h"
#include "BinarySearchTree2.h"
#include <stdio.h>

int main()
{
	BTreeNode * bstRoot;
	BTreeNode * sNode;

	BSTMakeAndInit(&bstRoot);

	BSTInsert(&bstRoot, 9);
	BSTInsert(&bstRoot, 1);
	BSTInsert(&bstRoot, 6);
	BSTInsert(&bstRoot, 2);
	BSTInsert(&bstRoot, 8);
	BSTInsert(&bstRoot, 3);
	BSTInsert(&bstRoot, 5);
	BSTInsert(&bstRoot, 1);
	BSTInsert(&bstRoot, 3);

	sNode = BSTSearch(bstRoot, 1);
	if (sNode == NULL)
		printf("Å½»ö ½ÇÆÐ\n");
	else
		printf("Å°:%d\n", BSTGetNodeData(sNode));

	sNode = BSTSearch(bstRoot, 4);
	if (sNode == NULL)
		printf("Å½»ö ½ÇÆÐ\n");
	else
		printf("Å°:%d\n", BSTGetNodeData(sNode));

	sNode = BSTSearch(bstRoot, 6);
	if (sNode == NULL)
		printf("Å½»ö ½ÇÆÐ\n");
	else
		printf("Å°:%d\n", BSTGetNodeData(sNode));

	sNode = BSTSearch(bstRoot, 7);
	if (sNode == NULL)
		printf("Å½»ö ½ÇÆÐ\n");
	else
		printf("Å°:%d\n", BSTGetNodeData(sNode));

	BSTShowAll(bstRoot);
	
	BSTRemove(&bstRoot, 9);
	//BSTRemoveK(&bstRoot, 9);

	return 0;
}
