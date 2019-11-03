#include<iostream>

using namespace std;

void makeHeap(int arr[],int n)
{
	for(int i=1;i<n;i++)
	{
		int value = arr[i];
		int s = i;
		int f = (s-1)/2;

		while(s>0 && value >arr[f])
		{  arr[s] = arr[f];
             s = f;
             f=(s-1)/2;
		}

		arr[s] = value;
	}
}

void heapSort(int arr[],int n)
{
	for(int i = n-1; i>0;i--)
	{
		int ivalue = arr[i];
		arr[i] = arr[0];

		int f = 0;

		int s;
		if(i == 1)
			s = -1;
		else
			s = 1;

		if(i>2 && arr[2]>arr[1])
			s = 2;

		while(s>=0 && ivalue < arr[s])
		{
			arr[f] = arr[s];
			f = s;
			s = 2*f+1;

			if(s+1<=i-1 && arr[s]<arr[s+1])
				s++;
			if(s>i-1)
				s = -1;
		}

		arr[f] = ivalue;

		for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
	}


}

void display(int arr[],int n)
{
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
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



	makeHeap(arr,n);

	cout<<"\n Unsorted array \n";
	display(arr,n);

    
	heapSort(arr,n);

	cout<<"\n Sorted array \n";
	display(arr,n);


}