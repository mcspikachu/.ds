#include <stdio.h>
void heapify(int arr[], int n, int i)
{
	int largest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;
	int temp;

	if (l < n && arr[l] > arr[largest])
		largest = l;


	if (r < n && arr[r] > arr[largest])
		largest = r;


	if (largest != i) {

		temp=arr[i];
		arr[i]=arr[largest];
		arr[largest]=temp;

		heapify(arr, n, largest);
	}
}

void buildHeap(int arr[], int n)
{
    int i, start = (n / 2) - 1;

    for ( i = start; i >= 0; i--) {
        heapify(arr, n, i);
    }
}




int main()
{

	int arr[100];
	int size,i,start,ch,val;
	printf("Enter the size:");
	scanf("%d",&size);
	printf("Enter the array elements:");
	for(i=0;i<size;i++)
	scanf("%d",&arr[i]);
	buildHeap(arr,size);
	do{
	printf("\nMENU:\n1.Insert\n2.Delete\n3.Display\n4.Exit");
	printf("\nEnter a choice");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1: printf("Enter value to insert:");
				scanf("%d",&val);
				size++;
				arr[size-1]=val;
				buildHeap(arr,size);
				break;
		case 2: val=arr[0];
				arr[0]=arr[size-1];
				size--;
				buildHeap(arr,size);
				break;
		case 3: printf("Array representation of Heap is:\n");
				for ( i = 0; i < size; ++i)
					printf("%d",arr[i]);
				break;
		case 4: break;
		default: printf("Wrong choice.");

	}


}while(ch!=4);
	return 0;
}

