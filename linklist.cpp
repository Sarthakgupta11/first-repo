//linklist
#include <iostream>
using namespace std;
class node
{
    public:
    int data;
    node* next;
    node(int d)
    { 
        data=d;
        next = NULL;
    }
};

class Linklist
{
    public:
    node* head;
    node* tail;

    Linklist()
    {
        head=NULL;
        tail=NULL;
    }

    void insertion_head(int x)
    {
        node* n= new node(x);
        if(head==NULL)
        {
            head=n;
            tail=n;
        }
        else
        {
            n->next=head;
            head=n;
        }
    }

    void insertion_tail(int x)
    {
        node* n= new node(x);
        if(head==NULL)
        {
            head=n;
            tail=n;
        }
        else
        {
            tail->next=n;
            tail=n;
        }
    }

    void insertion_between(int x,int pos)
    {
        if(pos<=0)
        {
            insertion_head(x);
        }
        else if(pos>length())
        {
            insertion_tail(x);
        }
        else
        {
            node* temp=head;
            int moveno=1;
            while(moveno<pos-1)
            {
                temp=temp->next;
                moveno++;
            }
            node* n= new node(x);
            n->next=temp->next;
            temp->next=n;
        }
    
    }

    void deletion_head()
    {
        node* temp=head;
        head=head->next;
        delete temp;

    }

    void deletion_tail()
    {
        node* temp=head;
        while(temp<tail-1)
        {
            temp=temp->next;
        }
        temp->next=NULL;
        delete tail;
        
    }
    
    void print()
    {
        node* temp=head;
        while(temp!=NULL)
        {
            cout<<temp->data<<"->";
            temp=temp->next;
        }
        cout<<endl;
        
    }

    int length()
    {
        node* temp=head;
        int l=0;
        while(temp!=NULL)
        {
            temp=temp->next;
            l++;
        }
        return l;
    }
    
};

int main()
{
    Linklist l;
    l.insertion_head(1);
    l.insertion_head(5);
    l.insertion_head(0);
    l.insertion_tail(100);
    l.insertion_between(25,4);
    l.deletion_head();
    l.deletion_tail();
    
    l.print();
    cout<<l.length();

    return 0;
}
