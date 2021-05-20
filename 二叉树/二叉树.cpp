#include<stdio.h>
#include<stdlib.h>
typedef struct TREE {
	int data;
	struct TREE *Ltree;		//左子树
	struct TREE* Rtree;		//右子树
}TREE,*LPTREE;
struct TREE* CreatTree(int data) {				//创建树节点
     LPTREE mytree=(LPTREE)malloc(sizeof(TREE));
	 mytree->data = data;
	 mytree->Ltree = NULL;
	 mytree->Rtree = NULL;
	 return mytree;
}
void PrintTree1(LPTREE mytree)				//递归先序遍历
{
	if (mytree != NULL)
	{
		printf("%4d",mytree->data);
		PrintTree1(mytree->Ltree);
		PrintTree1(mytree->Rtree);
	}
}
void PrintTree2(LPTREE mytree)				//递归中序遍历
{
	if (mytree != NULL)
	{
		PrintTree2(mytree->Ltree);
		printf("%4d", mytree->data);
		PrintTree2(mytree->Rtree);
	}
}
void PrintTree3(LPTREE mytree)				//递归后序遍历
{
	if (mytree != NULL)
	{
		PrintTree3(mytree->Ltree);
		PrintTree3(mytree->Rtree);
		printf("%4d", mytree->data);
	}
}
void PrintTree4(LPTREE mytree)
{	 
	if (mytree == NULL)return;
	LPTREE stack[10];					  //存储每次打印节点的位置
	int stackTop = -1;				     //栈顶标记
	LPTREE Pmove = mytree;				//从根节点开始
	while (stackTop != -1 || Pmove)
	{
		printf("%4d", Pmove->data);
		stack[++stackTop] = Pmove;
		Pmove = Pmove->Ltree;
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
	printf("递归先序遍历");
	PrintTree1(s1);
	printf("\n");
	printf("递归中序遍历");
	PrintTree2(s1);
	printf("\n");
	printf("递归后序遍历");
	PrintTree3(s1);
}