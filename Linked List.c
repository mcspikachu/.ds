#include<stdio.h>
struct node
{
    int data;
    struct node *next;
}*head,*temp,*n,*prev;
void insertatbeg(int);
void insertatpos(int,int);
void insertatend(int);
int deletebeg();
int count();
int deleteend();
int deletepos(int);
void display();
int search(int);
void createnode(int);
int main()
{
    int ch;
    int val,pos;
    do
    {
    printf("\nMENU:\n1.Insert at beginning\n2.Insert at End\n3.Insert atPosition\n4.Delete at beginning\n5.Delete at Position\n6.Delete at end\n7.Display\n8.Search\n9.Exit");
    printf("\nEnter the choice");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1: printf("Enter value to insert:");
                   scanf("%d",&val);
                   insertatbeg(val);
                break;
        case 2:printf("Enter value to insert:");
                   scanf("%d",&val);
                   insertatend(val);
                   break;
        case 3:printf("Enter value to insert:");
                   scanf("%d",&val);
                   printf("Enter position to insert:");
					scanf("%d",&pos);
	               insertatpos(val,pos);
                   break;
        case 4:
               	val= deletebeg();
               	if(val==-1)
               		printf("Value not deleted");
               	else
               	printf("Value deleted s:%d",val);
                break;
        case 5: printf("Enter position to delete:");
                scanf("%d",&pos);
               	val= deletepos(pos);
               	printf("Value deleted is:%d",val);
                break;
        case 6: val=deleteend();
		printf("value deleted is:%d",val);
		break;
        case 7: display();
                break;
        case 8:printf("Enter value to search");
        scanf("%d",&val);
        pos=search(val);
        if(pos==-1)
        printf("Not found");
        else
        printf("Found at:%d",pos);
         break;
		 case 9:break;
		 default:printf("Invalic]d choice");
    }

    }while(ch!=9);
}
void createnode(int val)
{
    head = (struct node *)malloc(sizeof(struct node ));
    head->next=NULL;
    head->data=val;
}
void insertatend(int val)
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
void insertatbeg(int val)
{
    if(head==NULL)
    {
        createnode(val);
    }
    else
    {
            n = (struct node *)malloc(sizeof(struct node));
            n->next=head;
            n->data=val;
            head=n;
    }
}
void insertatpos(int val,int pos)
{
	int c,i;
	c=count();
	if(pos>c+1)
	{
		printf("\nPosition doesnt exist");
	}
	else
	{
		if(pos==1)
		{
			insertatbeg(val);
		}
		else if(pos==(c+1))
		{
			insertatend(val);
		}
		else{
		i=2;
		temp=head;
		while(temp->next!=NULL&&i<=(pos-1))
		{
				i++;
			temp=temp->next;

		}
		 n = (struct node *)malloc(sizeof(struct node));
            n->next=temp->next;
            n->data=val;
			temp->next=n; }
	}
}
int count()
{
	int count=0;
	if(head==NULL)
		count=0;
	else
	{
			temp=head;
			while(temp!=NULL)
				{
					count++;
					temp=temp->next;
				}


	}
	return count;
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
            printf("%d",temp->data);
            temp=temp->next;
        }
    }
}
int deletepos(int pos)
{	int c,i,val;
	c=count();

	if(pos>c+1)
	{
		printf("Position doesnt exist");
		return -1;
	}
   else{

    if(head==NULL)
    {
        printf("Linked List is empty.");
    }
    else if(pos==1)
    {
    	return(deletebeg());
	}
	else if(pos==(c))
	{
		return(deleteend());
	}
    else
    {
    	i=1;
        temp=head;
        while(temp->next!=NULL&&i<=(pos-1))
        {
        	prev=temp;
        	     i++;
            temp=temp->next;

        }
        n=prev->next;

        prev->next=n->next;
		val= n->data;
		free(n);
		return val;

    }}
}
int deletebeg()
{int val;
if(head==NULL)
    {
        printf("Linked List is empty.");
    	return -1;
    }
    else
    {

    	temp=head;
    	head=temp->next;
    	val=temp->data;
    	free(temp);
    	return val;
	}

}
int deleteend()
{
	int val;
	if(head==NULL)
    {
        printf("Linked List is empty.");
        return -1;
    }
    else if(head->next==NULL)
    {
    	val=deletebeg();
    	return val;
	}
    else
    {
    	temp=head;
    	while(temp->next!=NULL)
    	{
    		prev=temp;
		temp=temp->next;
		}
		n=prev->next;
		val=n->data;
			prev->next=NULL;
		return val;

	}
}
int search(int val)
{
	int i=0;
		if(head==NULL)
    {
        printf("Linked List is empty.");
        return -1;
    }
    else
    {
    	i=0;
    	temp=head;
    	while(temp!=NULL)
		{
			if(temp->data==val)
			{
				return (i+1);
			}
			else
			{
				i++;
				temp=temp->next;
			}
		}
		return -1;
}
}
