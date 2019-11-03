#include<iostream>

using namespace std;

const int MAX = 10;


void sort(int arr[],int n){
	int temp;

	for(int i=0;i<n-1;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(arr[i]>arr[j])
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}

void merge(int a[],int b[],int c[],int n1,int n2,int n3)
{
	int i,j,k;

	for( i=j=k=0 ; j<n1 || k<n2 ;)
	{
		if(a[j]<=b[k])
			c[i++] = a[j++];
		else
			c[i++] = b[k++];

	    if(j == n1 || k == n2)
	        break; 
	}

	for( ; j<n1 ; )
		c[i++] = a[j++];


	for(; k<n2 ;k++ )
		c[i++] = b[k];
}

int main()
{
	int n1,n2,n3;
	cin>>n1>>n2;
    
    n3 = n1+ n2;

	int a[n1],b[n2],c[n3];

	for(int i=0;i<n1;i++)
	   cin>>a[i];

	for(int i=0;i<n2;i++)
	    cin>>b[i];

    cout<<"\n First unsorted array: \n";
	for(int i=0;i<n1;i++)
	   cout<<a[i]<<" ";
    
    cout<<"\n Second unsorted array: \n";
	for(int i=0;i<n2;i++)
	   cout<<b[i]<<" ";

	 sort(a,n1);
	 sort(b,n2);

	 cout<<"\n First sorted array: \n";
	for(int i=0;i<n1;i++)
	   cout<<a[i]<<" ";

	cout<<"\n Second sorted array: \n";
	for(int i=0;i<n2;i++)
	   cout<<b[i]<<" ";

	 merge(a,b,c,n1,n2,n3);

	 cout<<"\n Sorted array: \n";
	 for(int i=0;i<n3;i++)
	   cout<<c[i]<<" "; 

}