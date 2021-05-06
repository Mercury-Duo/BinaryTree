#include<stdio.h>
#include<stdlib.h>
typedef struct TREE {
	int data;
	struct TREE *Ltree;
	struct TREE* Rtree;
}TREE,*LPTREE;
struct TREE* CreatTree(int data) {
     LPTREE mytree=(LPTREE)malloc(sizeof(TREE));
	 mytree->data = data;
	 mytree->Ltree = NULL;
	 mytree->Rtree = NULL;
	 return mytree;
}
void Printt1(LPTREE mytree)//先序遍历
{
	if (mytree != NULL)
	{
		printf("%d",mytree->data);
		Printt1(mytree->Ltree);
		Printt1(mytree->Rtree);
	}
}
void Printt2(LPTREE mytree)//中序遍历
{
	if (mytree != NULL)
	{
		Printt2(mytree->Ltree);
		printf("%d", mytree->data);
		Printt2(mytree->Rtree);
	}
}
void Printt3(LPTREE mytree)//中序遍历
{
	if (mytree != NULL)
	{
		Printt3(mytree->Ltree);
		Printt3(mytree->Rtree);
		printf("%d", mytree->data);
	}
}
int main(void)
{
	LPTREE s1 = CreatTree(1);
	LPTREE s2 = CreatTree(2);
	LPTREE s3 = CreatTree(3);
	LPTREE s4 = CreatTree(4);
	LPTREE s5 = CreatTree(5);
	s1->Ltree = s2;s1->Rtree = s3;
	s2->Ltree = s4;s2->Rtree = s5;
	Printt1(s1);
	printf("\n");
	Printt2(s1);
	printf("\n");
	Printt3(s1);
}