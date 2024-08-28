//Queue using Linked List
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
        default:printf("Wrong choice");
    }

    }while(ch!=4);
}
void createnode(int val)
{
    head = (struct node *)malloc(sizeof(struct node));
    head->next=NULL;
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
            while(temp->next!=NULL)
            {
                temp=temp->next;
            }
            n = (struct node *)malloc(sizeof(struct node));
            n->next=NULL;
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
        temp=head;
        while(temp!=NULL)
        {
            printf("%d ",temp->data);
            temp=temp->next;
        }
    }
}
void deletenode()
{
    if(head==NULL)
    {
        printf("Linked List is empty.");
    }
    else if(head->next==NULL)
    {

        printf("Value deleted: %d",head->data);
            free(head);
        head=NULL;
    }
    else
    {
        temp=head;
        head=temp->next;
        printf("Value deleted: %d",temp->data);
        free(temp);

    }
}
