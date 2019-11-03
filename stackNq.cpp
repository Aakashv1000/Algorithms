#include <iostream>
using namespace std;

struct node
{
  int data;
  node* next;
};

int main()
{
  cout << "s for Stack or q for Queue\n";
  char c;
  cin >> c;
  if(c=='s')
  {
    node *front = NULL;
    node *rear = NULL;
    int n;
    cout<<"enter the number of values: ";
    cin>>n;
    cout << "Enter data.\n";
    while(n!=0)
    {
      node *temp = new node;
      cin >> temp->data;
      temp->next = NULL;
      if(temp->data < 0)
      {
        delete temp;
        break;
      }

      if(rear)
      {
        rear->next = temp;
        rear = rear->next;
      }

      else front = rear = temp;

      n--;
    }

    cout << "\n after removing from queue\n";
    while(front)
    {
      cout << front->data << " " ;
      node *temp = front;
      front = front->next;
      delete temp;
    }
  }
  else if(c=='q')
  {
    node *top = NULL;
    int n;
    cout<<"enter the number of values: ";
    cin>>n;
    cout << "Enter the values: \n";
    while(n>0)
    {
      node *temp = new node;
      cin >> temp->data;
      temp->next = NULL;

      if(temp->data < 0)
      {
        delete temp;
        break;
      }

      if(top)
      {
        temp->next = top;
        top = temp;
      }
      else top = temp;
      n--;
    }

    cout << "\n After Popping: \n";

    while(top)
    {
      node *temp = top;
      cout << temp->data << " ";
      top = top->next;
      delete temp;
    }
  }
  return 0;
}