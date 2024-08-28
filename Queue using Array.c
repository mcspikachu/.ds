#include<stdio.h>
int main()
{
    int queue[100];
    int front=-1,rear=-1;
    int val,ch,i,size;
    printf("\nEnter size:");
    scanf("%d",&size);
    do
    {
        printf("\nMENU:");
        printf("\n1.Insert\n2.Delete\n3.Display\n4.Exit");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: if(rear==size-1)
                    {
                        printf("Queue Full!");
                        break;
                    }
                    else if(front==-1 && rear==-1)
                    {
                    front++;
                    rear++;
					}
                    else
                    {
                        rear++;
                    }
                    printf("Enter value to Insert");
                  	scanf("%d",&val);
                    queue[rear]=val;
                    break;
            case 2: if(front==-1&&rear==-1)
                    {
                        printf("Queue Empty!");
                        break;
                    }
                    else if(front==rear)
                    {
                    	val=queue[front];
                    	front=-1;
                    	rear=-1;
					}
                    else
                    {
                        val=queue[front];
                        front++;
                    }
                    printf("Value deleted is:%d",val);
                    break;
            case 3: if(front==-1&&rear==-1)
            		{
                        printf("Queue Empty!");
                    }
                    else if(front==rear)
                    {
                    	printf("%d ",queue[front]);
					}
                    else
                    {
                    	for(i=front;i<=rear;i++)
                    	{
                    		printf("%d ",queue[i]);
						}
					}
			case 4: break;
			default:printf("Wrong Choice.");
        }
    }while(ch!=4);
   return 0;
}
