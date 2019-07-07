# BSTree_
search binary tree 
/*
  搜索二叉树：二叉树中存储集合中所有的元素
 */
#include <stdio.h>
#include <stdlib.h>

typedef int Status;

typedef struct BSTnode{
	int key;		//二叉树 中存储的int 类型数据
	BSTnode *LChild;
	BSTnode *RChild;
}BSTnode;

typedef struct {
	BSTnode *root;
}Tree;

int  display(BSTnode *p);
Status insert(Tree *tree,int value)
{
		BSTnode *node=(BSTnode*)malloc(sizeof(BSTnode));
		node->key=value;
		node->LChild=NULL;
		node->RChild=NULL;
		if(tree->root==NULL)
			tree->root=node;
		else 
		{
				BSTnode *tmp=tree->root;
				while(tmp)
				{
						if(value <tmp->key)
						{
								if(tmp->LChild==NULL)
								{
										tmp->LChild=node;
										return 0;
								}
								else 
									tmp=tmp->LChild;
						}
						else 
						{
								if(tmp->RChild==NULL)
								{
									tmp->RChild=node;
									return 0;
								}
								else 
									tmp=tmp->RChild;
						}
				}
		}
	return 0;
}
void  find(BSTnode *node,int value)
{
		if(value ==node->key)
		{
				display(node);
				return ;
		}
		else 
		{
				if(value < node->key)
				{
					if(node->LChild==NULL)
							return ;
					node=node->LChild;
					find(node,value);
				}
				else if(value> node->key)
				{
					if(node->RChild==NULL)
							return ;
					node=node->RChild;\
					find(node,value);
				}
		}
	
}
int display(BSTnode *p)
{
  printf("exist %d!",p->key);
  return 0;
 }

int main(void)
{
		Tree tree;
		tree.root=NULL;

		int n;
		printf("二叉树的节点个数:");
		scanf_s("%d",&n,1);

		for(int i=0;i<n;i++)
		{
					int value;
					printf("键入节点数值:\t");
					scanf_s("%d",&value,1);
					insert(&tree,value);
		}

		int num;
		printf("在树种寻找数值:");
		scanf_s("%d",&num,1);
		BSTnode *p=tree.root;
		find(p,num);

		system("pause");
		return 0;
}

