#include <iostream>

using namespace std;

class reverseList
{
private:
	struct node{
		int data;
		node *link;
	}*p;
public:
	reverseList();
	void reverse();
	void display();
	~reverseList();
	
};

reverseList::reverseList(){
	p = NULL;
}

void reverseList::convert()
{
	node *r,*q,*prev;

	q = p;
	r = NULL;

	while(q != NULL)
	{
		prev = r;
		r = q;
		r->link = prev;
        q=q->link;
    }
	p = r;
}


void reverseList::display()
{
  node *temp;

  temp = p;

  while(temp != NULL)
  {
  	cout<<" "<<temp->data;
  	temp = temp->link;
  }
}

reverseList::~reverseList()
{
	node *temp;

	while(p != NULL)
	{
       temp = p->link;
       delete p;
       p =temp;
	}
}

int main()
{
	reverseList l;

	
}