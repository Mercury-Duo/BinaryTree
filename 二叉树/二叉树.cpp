#include<stdio.h>
#include<stdlib.h>
typedef struct TREE {
	int data;
	struct TREE *Ltree;		//左子树
	struct TREE* Rtree;		//右子树
}TREE,*LPTREE;
struct TREE* CreatTree(int data) {				//创建树节点
     LPTREE mytree=(LPTREE)malloc(sizeof(TREE));
	 if (!mytree)exit(-1);
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
void PrintTree4(LPTREE mytree)			//非递归先序遍历
{	 
	if (mytree == NULL)return;
	LPTREE stack[10];					  //存储每次打印节点的位置
	int stackTop = -1;				     //栈顶标记
	LPTREE Pmove = mytree;				//从根节点开始
	while (stackTop != -1 || Pmove)
	{
		while (Pmove)
		{
			printf("%4d", Pmove->data);		//打印
			stack[++stackTop] = Pmove;		//入栈
			Pmove = Pmove->Ltree;
		}
		if (stackTop != -1)
		{
			Pmove = stack[stackTop];       //获取栈顶指针
			stackTop--;                    //出栈
			Pmove = Pmove->Rtree;           //找右子树
		}
	}
}
void PrintTree5(LPTREE mytree)				//非递归中序遍历
{
	if (mytree == NULL)return;
	LPTREE stack[10];					  //存储每次打印节点的位置
	int stackTop = -1;				     //栈顶标记
	LPTREE Pmove = mytree;
	while (Pmove || stackTop != -1)
	{
		while (Pmove)
		{											//一直找到最左边的节点
			stack[++stackTop] = Pmove;
			Pmove = Pmove->Ltree;
		}
		if (stackTop != -1)
		{
			Pmove = stack[stackTop];
			stackTop--;
			printf("%4d",Pmove->data);
			Pmove = Pmove->Rtree;
		}
	}
}
void PrintTree6(LPTREE mytree)
{
	if (mytree == NULL)return;
	LPTREE stack[10];
	int stackTop = -1;
	LPTREE Pmove = mytree;
	LPTREE LastVisit = NULL;		//访问标记
		while (Pmove)
		{
			stack[++stackTop] = Pmove;
			Pmove = Pmove->Ltree;//首先移动到最左边节点
		}
		while (stackTop != -1)
		{
			Pmove = stack[stackTop];
			stackTop--;
			if (Pmove->Rtree == NULL || Pmove == LastVisit)//当前节点左右是否被访问
			{
				printf("%4d",Pmove->data);//如果访问过则打印
				LastVisit = Pmove;
			}
			else 
			{
				stack[++stackTop] = Pmove;
				Pmove = Pmove->Rtree;
				while (Pmove)
				{
					stack[++stackTop] = Pmove;
					Pmove = Pmove->Ltree;//首先移动右子树到最左边节点
				}
			}
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
	printf("递归先序遍历\t");
	PrintTree1(s1);
	printf("\n");
	printf("非递归先序遍历\t");
	PrintTree4(s1);
	printf("\n");
	printf("递归中序遍历\t");
	PrintTree2(s1);
	printf("\n");
	printf("非递归中序遍历\t");
	PrintTree5(s1);
	printf("\n");
	printf("递归后序遍历\t");
	PrintTree3(s1);
	printf("\n");
	printf("非递归后序遍历\t");
	PrintTree6(s1);
}