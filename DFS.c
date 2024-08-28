#include <stdio.h>
#define True 1
#define False 0
#define MAX 10
typedef struct node
{
int info;
struct node* next;
}Node;
int visited [MAX];
void create_graph (Node *[], int);
void input (Node *[], int);
void depth_first_search(int, Node *[]);
void display (Node *[], int);
void main()
{
Node *arr_ptr[MAX];
int nvertex;
printf("\nEnter the number of vertices in Graph: ");
scanf("%d",&nvertex);
create_graph(arr_ptr, nvertex);
input (arr_ptr, nvertex);
printf("\n Values are inputted in the graph");
display (arr_ptr, nvertex);
printf("\n\n Depth First search is: \t");
depth_first_search (1, arr_ptr);
}
void create_graph (Node* arr_ptr[], int num)

{

int i;

for (i=1; i<=num; i++)
arr_ptr[i]=NULL;
}
void input (Node *arr_ptr[],int num)
{
Node *nptr, *save;
int i,j, num_vertex, item;
for(i=1;i<=num;i++)
{

printf("Enter the no. of vertices in adjacency list a[%d] :",i);
scanf("%d", &num_vertex);
for(j=1; j<=num_vertex; j++)
{

printf("Enter the value of vertex:");
scanf("%d",&item);
nptr=( Node*) malloc(sizeof( Node));
nptr->info=item;
nptr->next=NULL;
if (arr_ptr[i]==NULL)
arr_ptr[i]=save=nptr;
else
{
save->next=nptr;
save=nptr;
}
}
}
}
void display (Node *arr_ptr[], int num)
{

int i;
Node *ptr;
printf("\n\nGraph is: \n");
for(i=1;i<=num; i++)
{

ptr=arr_ptr[i];
printf("\na[%d] ",i);
while (ptr != NULL)
{

printf (" -> %d", ptr->info);
ptr=ptr->next;
}}}
void depth_first_search(int v, Node *arr_ptr[])
{

Node *ptr;

visited[v] = True;
printf("\%d\t", v);
ptr=*(arr_ptr+v);

while (ptr!=NULL)
{

if (visited [ptr->info]==False)
depth_first_search(ptr->info, arr_ptr);
else
ptr=ptr->next;
}
}
