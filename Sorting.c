#include<stdio.h>
int array[100];
int size;
void bubblesort()
{
	int  temp,i,j,flag;
    flag=1;
	for(i=0;(i<size-1&&flag==1);i++)
    {
        flag=0;
        for(j=0;j<size-i-1;j++)
        {
            if(array[j]>array[j+1])
            {
                flag=1;
                temp=array[j];
                array[j]=array[j+1];
                array[j+1]=temp;
            }
        }
    }
}
void selectionsort()
{
	int i,j,small,pos;
	for(i=0;i<size-1;i++)
    {
        small=array[i];
        pos=i;
        for(j=i+1;j<size;j++)
        {
            if(array[j]<small)
            {
                small=array[j];
                pos=j;
            }
        }
        array[pos]=array[i];
        array[i]=small;
    }
}
void insertionsort()
{
	 int i,temp,j;
     for(i=1;i<size;i++)
   	 {
        temp=array[i];
        for(j=i-1;(temp<array[j]&&j>=0);j--)
        {
            array[j+1]=array[j];
        }
        array[j+1]=temp;
    }
}
void  quicksort(int array[],int low, int high)
{
    int pi;
    if(low<high)
    {
        pi=partition(array,low,high);
        quicksort(array,low,pi-1);
        quicksort(array,pi+1,high);
    }
}
int partition(int array[],int low,int high)
{
    int i,j,pivot,temp;
    pivot=array[high];
    i=low-1;
    for(j=low;j<=high-1;j++)
    {
        if(array[j]<pivot)
        {
            i++;
            temp=array[i];
            array[i]=array[j];
            array[j]=temp;
        }
    }
    temp=array[i+1];
    array[i+1]=array[high];
    array[high]=temp;
    return(i+1);
}
void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    int L[n1], R[n2];


    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];


    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }


    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }


    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}


void mergesort(int arr[], int l, int r)
{
    if (l < r)
    {

        int m = l+(r-l)/2;


        mergesort(arr, l, m);
        mergesort(arr, m+1, r);

        merge(arr, l, m, r);
    }
}
void heapsort()
 {
	int n,i,last,temp;
	n=size;
	for(i=n;i>=1;i--)
	{
		array[i]=array[i-1];

	}

	array[0]=n;
	create(array);


	while(array[0] > 1)
	{

		last=array[0];
		temp=array[1];
		array[1]=array[last];
		array[last]=temp;
		array[0]--;
		down_adjust(array,1);
	}
 	size++;

}

void create(int array[])
{
	int i,n;
	n=array[0];
	for(i=n/2;i>=1;i--)
		down_adjust(array,i);
}

void down_adjust(int array[],int i)
{
	int j,temp,n,flag=1;
	n=array[0];

	while(2*i<=n && flag==1)
	{
		j=2*i;
		if(j+1<=n && array[j+1] > array[j])
			j=j+1;
		if(array[i] > array[j])
			flag=0;
		else
		{
			temp=array[i];
			array[i]=array[j];
			array[j]=temp;
			i=j;
		}
	}
}
int main()
{

	int ch,i;
	do
	{
		printf("\nEnter the size of array:");
		scanf("%d",&size);
		printf("Enter the Array:");
		for(i=0;i<size;i++)
			scanf("%d",&array[i]);
		printf("Unsorted Array is: ");
		for(i=0;i<size;i++)
			printf("%d ",array[i]);
		printf("\nMENU:\n1.Bubble Sort\n2.Selection Sort\n3.Insertion Sort\n4.Quick Sort\n5.Merge Sort\n6.Heap Sort\n7.Exit");
		printf("\nEnter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
					bubblesort();
							printf("Sorted Array: ");
    	for(i=0;i<size;i++)
	   		printf(" %d",array[i]);
					break;
			case 2:
					selectionsort();
							printf("Sorted Array: ");
    	for(i=0;i<size;i++)
	   		printf(" %d",array[i]);
					break;
			case 3:
					insertionsort();
							printf("Sorted Array: ");
    	for(i=0;i<size;i++)
	   		printf(" %d",array[i]);
					break;
			case 4:
					quicksort(array,0,size-1);
						printf("Sorted Array: ");
    	for(i=0;i<size;i++)
	   		printf(" %d",array[i]);
					break;
			case 5:
					mergesort(array,0,size-1);
							printf("Sorted Array: ");
    	for(i=0;i<size;i++)
	   		printf(" %d",array[i]);
					break;
			case 6:
					heapsort();
							printf("Sorted Array: ");
    	for(i=1;i<size;i++)
	   		printf(" %d",array[i]);
					break;
			case 7:
					exit(0);
			default:
					printf("Wrong Choice");
		}
	}while(ch!=7);
	return 0;
}
