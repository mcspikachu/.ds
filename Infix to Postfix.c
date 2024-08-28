#include<stdio.h>
#include<ctype.h>
#include<string.h>
char stack[100];
int top=-1;
void push(char);
char pop();
int precedence(char);
void InfixToPostfix(char[], char[]);
int main()
{
	char infix[100], postfix[100];
	printf("\nEnter Infix expression :");
	scanf("%s",infix);
	InfixToPostfix(infix,postfix);
	printf("Postfix Expression: %s",postfix);
	return 0;
}
void push(char val)
{
	if(top >=99)
	{
		printf("\nStack Overflow.");
	}
	else
	{
		top++;
		stack[top] = val;
	}
}
char pop()
{
	char val ;
	if(top <0)
	{
		printf("Invalid Expression");
	}
	else
	{
		val = stack[top];
		top--;
		return(val);
	}
}
int precedence(char symbol)
{
	if(symbol == '^')
	{
		return(3);
	}
	else if(symbol == '*' || symbol == '/')
	{
		return(2);
	}
	else if(symbol == '+' || symbol == '-')
	{
		return(1);
	}
	else
	{
		return(0);
	}
}

void InfixToPostfix(char infix[], char postfix[])
{
	int i, j;
	char val;
	char x;

	push('(');
	strcat(infix,")");
	i=0;
	j=0;
	val=infix[i];

	while(val != '\0')
	{
		if(val == '(')
		{
			push(val);
		}
		else if( isdigit(val) || isalpha(val))
		{
			postfix[j] = val;
			j++;
		}
		else if(val == '^' || val == '*' || val == '/' || val == '+' || val =='-' || val=='%')
		{
			x=pop();
			while((val == '^' || val == '*' || val == '/' || val == '+' || val =='-'|| val=='%') && precedence(x)>= precedence(val))
			{
				postfix[j] = x;
				j++;
				x = pop();
			}
			push(x);
			push(val);
		}
		else if(val == ')')
		{
			x = pop();
			while(x != '(')
			{
				postfix[j] = x;
				j++;
				x = pop();
			}
		}
		else
		{
			printf("\nInvalid infix Expression.\n");

		}
		i++;


		val = infix[i];
	}
	if(top>0)
	{
		printf("\nInvalid infix Expression.\n");

	}
	if(top>0)
	{
		printf("\nInvalid infix Expression.\n");

	}


	postfix[j] = '\0';


}

