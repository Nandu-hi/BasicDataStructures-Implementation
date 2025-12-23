#include<bits/stdc++.h>
using namespace std;

class mydeque{
    public:
    int size;
    int capacity;
    int* data;
    int front;
    int back;
    mydeque(int x){
        capacity=x;
        data=new int[capacity];
        front=-1;
        back=-1;
        size=0;
    }
    void push_front(int x){
        if(size==capacity){
            cout << "Deque is full" << endl;
            return;
        }
        if(front==-1){
            front++;
            back++;
            data[front]=x;
        }
        else{
            if(front==0){
                front=capacity-1;
            }
            else{
                front--;
            }
            data[front]=x;
        }
        size++;
    }
    void push_back(int x){
        if(size==capacity){
            cout << "Deque is full" << endl;
            return;
        }
        else{
            if(front==-1){
                front++;
                back++;
                data[back]=x;
            }
            else{
                back=(back+1)%capacity;
                data[back]=x;
            }
        }
        size++;
    }
    void pop_front(){
        if(size==0){
            cout << "Deque is empty" << endl;
            return;
        }
        cout << data[front] << endl;
        if(size==1){
            front=-1;
            back=-1;
        }
        else{
            front=(front+1)%capacity;
        }
        size--;
    }
    void pop_back(){
        if(size==0){
            cout << "Deque is empty" << endl;
            return;
        }
        cout << data[back] << endl;
        if(size==1){
            front=-1;
            back=-1;
        }
        else{
            if(back==0){
                back=capacity-1;
            }
            else{
                back--;
            }
        }
        size--;
    }
    bool isempty(){
        if(size==0){
            return true;
        }
        return false;
    }
};

int main(){
    int size;
    cin >> size;
    int q;
    cin >> q;

    mydeque dq(size);

    while(q--){
        string s;
        cin >> s;
        if(s=="push"){
            string s1;
            cin >> s1;
            int x;
            cin >> x;
            if(s1=="front"){
                dq.push_front(x);
            }
            else{
                dq.push_back(x);
            }
        }
        else if(s=="pop"){
            string s1;
            cin >> s1;
            if(s1=="front"){
                dq.pop_front();
            }
            else{
                dq.pop_back();
            }
        }
        else if(s=="isEmpty"){
            if(dq.isempty()){
                cout << "True" << endl;
            }
            else{
                cout << "False" << endl;
            }
        }
    }
}