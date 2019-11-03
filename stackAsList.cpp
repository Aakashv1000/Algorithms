#include<iostream>

using namespace std;

class stack{
private:
	struct node
	{
		int data;
		node *link;
	}*top;
public:
	stack();
	void push(int item);
	int pop();
	~stack();
};

stack::stack()
{
	top = NULL;
}

void stack::push(int item){

	node *temp;

   if(temp == NULL)
   	    cout<<"\n stack is full\n";

	temp = new node;
	temp->data = item;
	temp->link = top;

	top = temp;
}

int stack::pop()
{
	if(top == NULL)
		cout<<"\n stack is empty \n";
    
    node *temp;
    temp = top;
	int item = temp->data;
	top=top->link;

	delete temp;
	return item;
}

stack::~stack()
{
	if(top == NULL)
		return;

	node *temp;

	while(top != NULL)
	{
		temp = top;
		top=top->link;
		delete temp;
	}
}

int main()
{
	stack s;

	s.push(14);
	s.push(-3);
	s.push(18);
    s.push(29);
    s.push(31);
    s.push(16);

    int i = s.pop();

    cout<<i<<" ";

    i = s.pop();
    cout<<i<<" ";
}

