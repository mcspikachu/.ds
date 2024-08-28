#include<stdio.h>
int empty=0;
struct node{
int data;
struct node * right, * left;
}*root;
void insert(struct node ** tree, int val)
{
    struct node *temp = NULL;
    if(!(*tree))
    {
        temp = (struct node *)malloc(sizeof(struct node));
        temp->left = temp->right = NULL;
        temp->data = val;
        *tree = temp;
        return;
    }

    if(val < (*tree)->data)
    {
        insert(&(*tree)->left, val);
    }
    else if(val > (*tree)->data)
    {
        insert(&(*tree)->right, val);
    }

}

void preorder(struct node * tree)
{if(empty==1){

    	printf("Empty Tree");
    	exit(0);
    }
    if (tree)
    {
        printf("%d\n",tree->data);
        preorder(tree->left);
        preorder(tree->right);
    }


}

void inorder(struct node * tree)
{if(empty==1){

    	printf("Empty Tree");
    	exit(0);
    }
    if (tree)
    {
        inorder(tree->left);
        printf("%d\n",tree->data);
        inorder(tree->right);
    }

}

void postorder(struct node * tree)
{
	if(empty==1){

    	printf("Empty Tree");
    	exit(0);
    }if (tree)
    {
        postorder(tree->left);
        postorder(tree->right);
        printf("%d\n",tree->data);
    }

}

void deltree(struct node * tree)
{
    if (tree)
    {
        deltree(tree->left);
        deltree(tree->right);
        free(tree);
        printf("Tree Deleted");
        empty=1;
    }
}

struct node* search(struct node ** tree, int val)
{
    if(!(*tree))
    {
        return NULL;
    }

    if(val < (*tree)->data)
    {
        search(&((*tree)->left), val);
    }
    else if(val > (*tree)->data)
    {
        search(&((*tree)->right), val);
    }
    else if(val == (*tree)->data)
    {
        return *tree;
    }
}

void main()
{
    struct node *root;
    struct node *tmp;
    int val,ch;
    root = NULL;
    do
    {
    	printf("\nMENU\n1.Insert\n2.Delete\n3.PreOrder\n4.InOrder\n5.PostOrder\n6.Search\n7.Exit");
    	printf("Enter your choice");
    	scanf("%d",&ch);
    	switch(ch)
    	{
    		case 1: printf("Enter value to insert:");
					scanf("%d",&val);
					 insert(&root,val);
					 break;
			 case 2: deltree(root);break;
			 case 3:printf("Pre Order Display\n");
   					 preorder(root);
   					 break;
    case 4: printf("In Order Display\n");
  				  inorder(root);
 					   break;
    case 5:printf("Post Order Display\n");
  				  postorder(root);
  				  break;
    case 6: printf("Enter value to search");
  				  scanf("%d",&val);
					tmp = search(&root,val);
  				  if (tmp)
  				  {
		  			     printf("Searched node=%d\n", tmp->data);
					    }
   				 else
   					 {
   					     printf("Data Not found in tree.\n");
   					 }
   					 break;
   	 case 7:break;
    default:printf("Wrong chpice");
		}
	}while(ch!=7);






}
