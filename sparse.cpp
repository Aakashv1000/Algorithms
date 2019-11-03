#include<iostream>

using namespace std;

const int MAX1 = 3;
const int MAX2 = 3;

class sparse{
private:
	int *sp=NULL;
	int row;
public:
	void create_array();
	void display();
	int count();
	void create_tuple(sparse &s);
	void display_tuple();
	~sparse();

};

void sparse::create_array()
{
	int n;
	sp = new int [MAX1 * MAX2];
	for(int i=0; i<MAX1*MAX2; i++)
	{
		cout<<"\n enter element number: "<<i<<" :";
		cin>>n;
		*(sp +i) = n;
	}
}

void sparse::display()
{
  for(int i=0;i<MAX1*MAX2;i++)
  {
  	if(i%MAX2==0)
  		cout<<endl;
  	cout<<*(sp+i)<<" ";
  }
}

int sparse::count(){
	int cnt = 0;

	for(int i = 0; i<MAX1*MAX2 ; i++)
	{
		if(*(sp+i) != 0 )
			cnt++;
	}
	return cnt;
}

void sparse::create_tuple(sparse &s)
{
	int r=0,c=-1,l=-1;

	row=s.count()+1;

	sp = new int(row*3);
	*(sp +0) = MAX1;
	*(sp + 1) = MAX2;
	*(sp + 2) = row -1;
	l = 2;


	for(int i=0;i<MAX1*MAX2;i++)
	{
		c++;
		if(((i%MAX2)==0) && (i!=0)){
			r++;
			c=0;
		}

		if(*(s.sp+i) !=0 )
		{
			l++;
			*(sp+l)=r;
			l++;
			*(sp +l) = c;
			l++;
			*(sp+l)=*(s.sp + i);
		}
	}

}

void sparse::display_tuple()
{
	for(int i=0;i<row*3;i++)
	{
		if(i%3==0)
			cout<<endl;
		cout<<*(sp+i)<<" ";
	}
}

sparse::~sparse()
{
  delete sp;
}

int main()
{
  sparse s1;
  s1.create_array();
  cout<<"\n elements is sparse matrix: \n";
  s1.display();
  int c=s1.count();

  sparse s2;

  s2.create_tuple(s1);
  cout<<"\n array of non zero elements: \n";
  s2.display_tuple();
}