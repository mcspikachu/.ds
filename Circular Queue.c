#include<stdio.h>
int main()
{
    int queue[100];
    int i,ch,size,temp,f,r,val;
    f=-1;
    r=-1;
    printf("enter the size");
    scanf("%d",&size);
    do
    {
        printf("\nMENU: \n1.Insert\n2.Delete\n3.Display\n4.Exit");
        printf("Enter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                    if(f==-1 && r==-1)
                    {
                        f=0;
                        r=0;
                        printf("Enter a number to insert:");
                        scanf("%d",&val);
                        queue[r]=val;
                    }
                    else if((r==size-1 && f==0) || r==(f-1))
                    {
                        printf("Queue is full.");
                        break;
                    }
                    else
                    {
                        if(r==size-1 && f!=0)
                        {
                            r=0;
                			printf("Enter a number to insert:");
                        scanf("%d",&val);
                        queue[r]=val;
                        }
                        else
                        {

                        r++;
                        printf("Enter a number to insert:");
                        scanf("%d",&val);
                        queue[r]=val;
                    }
                    }
                    break;
            case 2: if(f==-1 && r==-1)
                    {
                    printf("Queue is empty.");
                    break;
                    }
                    if(f==r)
                    {
                        val=queue[f];
                        f=-1;
                        r=-1;
                        printf("The value deleted is: %d",val);
                    }
                    else if(f==size-1)
                        {
                        val=queue[f];
                        f=0;
                        printf("The value deleted is: %d",val);
                        }
                        else
                        {
                        val=queue[f];
                        f++;
                        printf("The value deleted is: %d",val);

                    }
                    break;
            case 3:if(f==-1 && r==-1)
                {
                    printf("Queue is empty");
                }
                else
                {
                    printf("Queue is:");
                    if(f<=r)
                    {
                        for(i=f;i<=r;i++)
                            printf("%d",queue[i]);
                    }
                    else
                    {
                        for(i=f;i<size;i++)
                            printf("%d",queue[i]);
                        for(i=0;i<=r;i++)
                            printf("%d",queue[i]);
                    }
                }
                    break;
            case 4: break;
            default:printf("Wrong Choice");
        }
    }while(ch!=4);
    return 0;
}

