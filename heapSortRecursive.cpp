#include<iostream>

using namespace std;

void display(int arr[],int n)
{
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
}

void swap(int i,int largest,int arr[])
{
	int temp = arr[i];
	arr[i] = arr[largest];
	arr[largest] = temp;
}

void max_heapify(int arr[],int n,int idx)
{
	int l = 2*idx;
	int r = 2*idx+1;
	int largest;

	if(l<= n-1 && arr[l]>arr[idx])
		largest = l;
	else
		largest = idx;
	if(r<=n-1 && arr[r]>arr[largest])
		largest = r;
	if(largest != idx)
	{
		swap(idx,largest,arr);
		max_heapify(arr,n,largest);
	}
		
}

void heapSort(int arr[],int n)
{
	for(int i=n/2-1;i>=0;i--)
		max_heapify(arr,n,i);
	for (int i=n-1; i>=0; i--) 
    {  
        swap(arr[0], arr[i]); 
        max_heapify(arr, i, 0); 
    } 
}

int main()
{
	int n;
	cin>>n;
	int arr[n];

	for(int i=0;i<n;i++)
		cin>>arr[i];

	cout<<"\n Unsorted array \n";
	display(arr,n);

	heapSort(arr,n);

	cout<<"\n Sorted array \n";
	display(arr,n);
}