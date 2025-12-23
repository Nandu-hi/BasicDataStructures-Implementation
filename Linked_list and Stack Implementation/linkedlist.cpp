#include<iostream>
using namespace std;
class node{
    public:
    int value;
    node* next;
    node(): value(0),next(NULL){}
};
class MyList{
    private:
    node* head;
    public:
    MyList():head(NULL){}
    void insertf(int value){
        node* newnode=new node();
        newnode->value=value;
        newnode->next=head;
        head=newnode;
    }
    void print1(){
        print2(head);
    }
    void print2(node* head){
        node* temp=head;
        while(temp){
            cout << temp->value << " ";
            temp=temp->next;
        }
        cout << endl;
    }
    void insertb(int value){
        node* newnode=new node();
        newnode->value=value;
        newnode->next=NULL;
        node* temp=head;
        if(head==NULL){
            head=newnode;
        }
        else{
            while(temp->next){
                temp=temp->next;
            }
            temp->next=newnode;
        }
    }
    void remove(int value){
        node* prev=NULL;
        node* temp=head;
        while(temp){
            if(temp->value==value){
                if(prev==NULL){
                    head=temp->next;
                    delete temp;
                    return;
                }
                else{
                    prev->next=temp->next;
                    delete temp;
                    return;
                }
            }
            else{
                prev=temp;
                temp=temp->next;
            }
        }
    }
};

int main(){
    int cases;
    cin >> cases;
    MyList l;
    while(cases--){
        string s;
        cin >>s;
        if(s=="PB"){
            int value;
            cin>> value;
            l.insertf(value);
        }
        if(s=="PE"){
            int value;
            cin>> value;
            l.insertb(value);
        }
        if(s=="DEL"){
            int value;
            cin>> value;
            l.remove(value);
        }
    }
    l.print1();
}