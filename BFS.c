#include<stdio.h>
#define MAX 10
#define True 1
#define False 0
typedef struct node
{
int info;
struct node *next;
}Node;
int visited [MAX];
int queue [MAX];
int Front, Rear;
void create_grap(Node *[], int num);
void input (Node *[],int num);
void breadth_first_search(Node *[]);
void qinsert (int);
int qdelete ();
int isqempty();
void display( Node *[], int num);
void main()
{
Node *arr_ptr[MAX];
int nvertex;
printf("\Enter the number of vertices in Graph: ");
scanf ("%d", &nvertex);
create_graph (arr_ptr, nvertex);
input (arr_ptr, nvertex);
printf("\n Values are inputted in the graph");
display (arr_ptr, nvertex);
Front=Rear=-1;
breadth_first_search (arr_ptr);
}
void create_graph (Node *arr_ptr[], int num)
{

int i;

for (i=1; i<=num; i++)
arr_ptr[i]=NULL;
}
void input (Node *arr_ptr[], int num)
{

Node *nptr, *save;
int i,j,num_vertex,item;
for (i=1; i<=num; i++)
{

printf("Enter the no. of vertices in adjacency list a[%d]",i);

scanf ("%d", &num_vertex);
for (j=1; j<=num_vertex; j++)
{

printf("Enter the value of vertex: ");
scanf ("%d", &item);
nptr=(Node*) malloc(sizeof (Node));
nptr->info=item;
nptr->next=NULL;
if(arr_ptr[i]==NULL)
arr_ptr[i]=save=nptr;
else
{
save->next= nptr;
save=nptr;
}}}}
void display (Node *arr_ptr[], int num)
{
int i;
Node *ptr;
printf ("\n\nGraph is\n");
for(i=1;i<=num;i++)
{
ptr= arr_ptr[i];
printf("\n a[%d]",i);
while(ptr != NULL)
{

printf(" -> %d", ptr->info);
ptr=ptr->next;
}
}
}
void breadth_first_search (Node *arr_ptr[])
{
Node *ptr;
int v=1;
visited[v]=True;
printf("\n Breadth First Search: %d\t" ,v);
qinsert (v);
while (isqempty()==False)
{

v=qdelete();
ptr=*(arr_ptr+v);
while (ptr !=NULL)
{
if( visited[ptr->info]==False)
{
qinsert (ptr->info);
visited[ptr->info] =True;
printf("%d\t", ptr->info);
}
ptr=ptr->next;
}}}
void qinsert(int vertex)
{
if (Rear==6)
{
printf("Overflow! Queue is Full");
exit(0);
}

queue[++Rear]=vertex;
if (Front==-1)
Front=0;
}
int qdelete()
{
int item;
if (Front==-1)
{

printf ("Underflow! Queue is empty");
exit(0);
}
item=queue [Front];
if (Front==Rear)
Front=Rear=-1;

else

Front++;
return item;
}
int isqempty()
{

if (Front==-1)
return True;

return False;
}
