#include<iostream>
using namespace std;

template <typename T>
class Node {
    public:
    T value;
    Node<T>* next;
public:
    Node():value(0),next(NULL){}
};


template<typename T>
class circular_list{
    private:
    Node<T>* head;
    Node<T>* tail;
    public:
    circular_list():head(NULL),tail(NULL){}

    void inserttoback(T value){
        if(head==NULL){
            head=new Node<T>();
            head->next=head;
            head->value=value;
            tail=head;
        }
        else{
            Node<T>* temp=head;
            while(temp->next!=head){
                temp=temp->next;
            }
            Node<T>* newnode = new Node<T>();
            newnode->value=value;
            newnode->next=head;
            temp->next=newnode;
            tail=newnode;
        }
    }
    void remove(T value){
        if(!head) return;
        Node<T>* temp=head;
        Node<T>* prev=NULL;
        while(prev==NULL || head!=temp){
            if(temp->value==value){
                if(prev==NULL){
                    if(head==tail){
                        delete head;
                        head=NULL;
                        tail=NULL;
                    }
                    else{
                        Node<T>* to_free = head;
                        tail->next=head->next;
                        head=head->next;
                        delete to_free;
                    }
                    temp=head;
                }
                else{
                    if(temp==tail){
                        Node<T>* to_free=tail;
                        tail=prev;
                        tail->next=head;
                        delete to_free;
                        return;
                    }
                    else{
                        Node<T>* to_free=temp;
                        prev->next=temp->next;
                        delete to_free;
                        temp=prev->next;
                    }
                }
            }
            else{
                prev=temp;
                temp=temp->next;
            }
        }
    }

    void print(){
        if(!head) return;
        Node<T>* temp=head;
        do{
            cout << temp->value << ' ';
            temp=temp->next;
        }while(temp!=head);
        cout << "\n";
    }
};

int main(){
    circular_list<int> l;
    l.inserttoback(1);
    l.print();
    l.inserttoback(2);
    l.print();
    l.inserttoback(3);
    l.print();
    l.inserttoback(1);
    l.print();
    l.remove(1);
    l.print();




}