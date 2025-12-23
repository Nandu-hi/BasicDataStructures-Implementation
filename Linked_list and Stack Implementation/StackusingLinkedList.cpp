#include<iostream>
using namespace std;
class node{
    public:
    int value;
    node* next;
    node(): value(0),next(NULL){}
};
class mystack{
    private:
    node* top;
    public:
    mystack():top(NULL){};
    void print1(){
        print2(top);
    }
    void print2(node* top){
        node* top_=top;
        while(top_){
            cout << top_->value << " ";
            top_=top_->next;
        }
        cout << endl;
    }
    void push(int value){
        node* newnode=new node();
        newnode->value=value;
        newnode->next=top;
        top=newnode;
    }
    void pop(){
        if(top){
            node* temp=top;
            top=top->next;
            delete temp;
        }
    }
    int Top(){
        return top->value;
    }
    bool isempty(){
        if(!top){
            return true;
        }
        else{
            return false;
        }
    }
};
int main(){
    mystack l;
    int test;
    cin>> test;
    while(test--){
        string s;
        cin >> s;
        if(s=="PUSH"){
            int value;
            cin >> value;
            l.push(value);
        }
        if(s=="POP"){
            l.pop();
        }

    }
    l.print1();
}
