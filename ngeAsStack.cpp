#include<iostream>
#include<algorithm>
#include<map>
#include<stack>

using namespace std;


int main(int argc, char const *argv[])
{

	int t;
	cin>>t;

	while(t)
	{
		long n;
		stack <long> s;
		cin>>n;
		long a[n];
		map<long, long> temp;
		for (long i = 0; i < n; i++)
		{
			cin>>a[i];
		}
        s.push(a[0]);

		for(long i=1;i<n;i++)
		{
			if(s.empty()){
				s.push(a[i]);
				continue;
			}

			while(s.empty() == false && s.top()<a[i])
			{
				temp.insert(pair<long,long>(s.top(),a[i]));
				s.pop();
			}

			s.push(a[i]);
		}

		while(s.empty() == false)
		{
			temp.insert(pair<long,long>(s.top(),-1));
			s.pop();
		}

		for(long i=0;i<n;i++)
		{
			cout<<temp.find(a[i])->second<<" ";
		}

		cout<<endl;

		t--;
	}
	
	return 0;
}