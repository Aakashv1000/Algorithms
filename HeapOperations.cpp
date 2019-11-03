#include<iostream>

using namespace std;

const int MAX = 20;

class heap{
private:
	int arr[MAX];
	int count;
public:
	heap();
	void insert(int num);
	void makeheap();
	void restoreDown(int pos);
    void restoreUp(int pos);
    int replace(int pos);
    int del();
};

heap::heap(){
	count = 0;

	for(int i=0;i<MAX;i++)
		 arr[i]=0;
	count =0;
}

void heap::insert(int num)
{
	if(cout<MAX)
		arr[count++] = num;
	else
		cout<<"\n array is full \n";
}

void heap::makeheap()
{
   count--;

   for(int i=count/2;i>=1;i--)
   	restoreDown(i);
}

void heap::restoreDown(int pos)
{
   int val = arr[pos];

   int i;

   while(pos <= count/2)
   {
   	i = 2*pos;

   	if((i<count) && (arr[i]<arr[i+1]))
   		i++;
   	if(val>arr[i])
   		break;
   	arr[pos]=arr[i];
   	pos = i;
   }
   arr[pos] = val;
}

