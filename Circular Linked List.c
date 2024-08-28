#include<stdio.h>
struct node
{
    int data;
    struct node *next;
}*head,*temp,*n;
void insertnode(int);
void deletenode();
void display();
void createnode(int);
int main()
{
    int ch;
    int val;
    do
    {
    printf("\nMENU:\n1.Insert\n2.Delete\n3.Display\n4.Exit");
    printf("\nEnter the choice");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1: printf("Enter value to insert:");
                   scanf("%d",&val);
                   insertnode(val);
                break;
        case 2: deletenode();
                break;
        case 3: display();
                break;
        case 4: break;
        default: printf("Wrong Choice");

    }

    }while(ch!=4);
}
void createnode(int val)
{
    head = (struct node *)malloc(sizeof(struct node));
    head->next=head;
    head->data=val;
}
void insertnode(int val)
{
    if(head==NULL)
    {
        createnode(val);
    }
    else
    {
            temp=head;
            while(temp->next!=head)
            {
                temp=temp->next;
            }
            n = (struct node *)malloc(sizeof(struct node));
            n->next=head;
            n->data=val;
            temp->next=n;
    }
}
void display()
{
    if(head==NULL)
    {
        printf("Empty Linked List");
    }
    else
    {
    	printf("%d",head->data);
        temp=head->next;
        while(temp!=head)
        {
            printf("%d",temp->data);
            temp=temp->next;
        }
    }
}
void deletenode()
{
    if(head==NULL)
    {
        printf("Empty Linked List");
    }
    else if(head->next==head)
    {
        n=head;
        free(n);
        head=NULL;
    }
    else{

        temp=head;
        while(temp->next->next!=head)
        {
            temp=temp->next;
        }
        n=temp->next;
        temp->next=head;
        free(n);
}
}
