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
        if(top==NULL){
            return true;
        }
        else{
            return false;
        }
    }
};
int main(){
    string s;
    cin >> s;
    mystack c;
    for(auto it : s){
        if(it=='(' || it =='{' || it == '['){
            c.push(it);
        }
        else if(it==')'){
            if(c.isempty()){
                cout << "False" << endl;
                return 0;
            }
            if(c.Top()=='('){
                c.pop();
            }
            else{
                cout << "False" << endl;
                return 0;
            }
        }
        else if(it=='}'){
            if(c.isempty()){
                cout << "False" << endl;
                return 0;
            }
            if(c.Top()=='{'){
                c.pop();
            }
            else{
                cout << "False" << endl;
                return 0;
            }
        }
        else if(it==']'){
            if(c.isempty()){
                cout << "False" << endl;
                return 0;
            }
            if(c.Top()=='['){
                c.pop();
            }
            else{
                cout << "False" << endl;
                return 0;
            }
        }
    }
    if(c.isempty()){
        cout << "True" << endl;
        return 0;
    }
    else{
        cout << "False" << endl;
        return 0;
    }
}