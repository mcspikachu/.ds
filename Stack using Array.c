#include<stdio.h>
int main()
{
    int stack[100];
    int top=-1;
    int val,ch,i,size;
    printf("\nEnter size:");
    scanf("%d",&size);
    do
    {
        printf("\nMENU:");
        printf("\n1.Push\n2.Pop\n3.Display\n4.Exit");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: if(top==size-1)
                    {
                        printf("Stack Overflow!");
                        break;
                    }
                    else
                    {
                    	printf("Enter value to PUSH");
                  		scanf("%d",&val);
                        top++;
                        stack[top]=val;
                    }
                    break;
            case 2: if(top==-1)
                    {
                        printf("Stack Underflow!");
                    }
                    else
                    {
                        val=stack[top];
                        top--;
                        printf("Value Popped is:%d",val);
                    }
                    break;
            case 3: if(top==-1)
            		{
                        printf("Stack Underflow!");
                    }
                    else
                    {
                    	for(i=top;i>=0;i--)
                    	{
                    		printf("%d ",stack[i]);
						}
					}
			case 4: break;
			default:printf("Wrong Choice.");
        }
    }while(ch!=4);
   return 0;
}
