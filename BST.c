#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *right;
    struct node *left;
};
struct node* search(struct node *root, int x)
{
    if(root==NULL || root->data==x)
        return root;
    else if(x>root->data)
        return search(root->right, x);
    else
        return search(root->left,x);
}


struct node* findminimum(struct node *root)
{
    if(root == NULL)
        return NULL;
    else if(root->left != NULL)
        return findminimum(root->left);
    return root;
}

struct node* new_node(int x)
{
    struct node *p;
    p = (struct node*)malloc(sizeof(struct node));
    p->data = x;
    p->left = NULL;
    p->right = NULL;

    return p;
}

struct node* insert(struct node *root, int x)
{

    if(root==NULL)
        return new_node(x);
    else if(x>root->data)
        root->right = insert(root->right, x);
    else
        root->left = insert(root->left,x);
    return root;
}

struct node* deletenode(struct node *root, int x)
{

    if(root==NULL)
        return NULL;
    if (x>root->data)
        root->right = deletenode(root->right, x);
    else if(x<root->data)
        root->left = deletenode(root->left, x);
    else
    {

        if(root->left==NULL && root->right==NULL)
        {
            free(root);
            return NULL;
        }


        else if(root->left==NULL || root->right==NULL)
        {
            struct node *temp;
            if(root->left==NULL)
                temp = root->right;
            else
                temp = root->left;
            free(root);
            return temp;
        }


        else
        {
            struct node *temp = findminimum(root->right);
            root->data = temp->data;
            root->right = deletenode(root->right, temp->data);
        }
    }
    return root;
}

void display(struct node *root)
{
    if(root!=NULL)
    {
        display(root->left);
        printf(" %d ", root->data);
        display(root->right);
    }
}

int main()
{

	int val,ch;
    struct node *root=NULL;
    do{
    	printf("\nMENU\n1.Insert\n2.Delete\n3.Display\n4.Exit");
    	printf("Enter your choice:");
    	scanf("%d",&ch);
    	switch(ch)
    	{
    		case 1:
					printf("Enter value to insert:");
    				scanf("%d",&val);
					if(root==NULL)
						root = new_node(val);
					else
						insert(root,val);
					break;
    		case 2:
    				printf("Enter value to delete");
					scanf("%d",&val);
					root = deletenode(root,val);
					break;
			case 3:
					display(root);
    				printf("\n");
					break;
			case 4:
					break;
			default:
					printf("Wrong choice");
		}
}while(ch!=4);





    return 0;
}
