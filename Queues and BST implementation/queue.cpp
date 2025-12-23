#include<bits/stdc++.h>
using namespace std;

class myqueue{
    private:
        int capacity;
        int* data;
        int front;
        int back;
    public:
        myqueue(){
            capacity=0;
            data=NULL;
            front = -1;
            back = -1;
        }
        myqueue(int inisize){
            data = new int[inisize];
            capacity=inisize;
            front =-1;
            back =-1;
        }
        bool isempty(){
            return front==-1;
        }
        bool isfull(){
            return (back+1)%capacity==front || data==NULL;
        }
        void resize(){
            int* temp;
            if(capacity)
            temp=new int[2*capacity];
            else{
                temp=new int[1];
            }
            int i=0;
            int j=front;
            do{
                temp[i]=data[j];
                j=(j+1)% capacity;
                i++;
            }while(j!=front);
            int* temp1=data;
            delete[] temp1;
            data=temp;
            front=0;
            back=capacity-1;
            capacity *= 2;
        }
        void enqueue(int value){
            if(isfull()){
                resize();
                back=back+1;
                data[back]=value;
            }
            else if(isempty()){
                front++;
                back++;
                data[back]=value;
            }
            else{
                back=(back+1)%capacity;
                data[back]=value;
            }
        }
        void dequeue(){
            if(isempty()){
                cout << "error" << endl;
                return;
            }
            else if(front==back){
                front=-1;
                back=-1;
            }
            else{
                front=(front+1)%capacity;
            }
        }
        void peek(){
            if(isempty()){
                cout << "error" << endl;
                return;
            }
            cout << data[front] << endl;
        }
};

int main(){
    myqueue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.dequeue();
    q.peek();
    q.dequeue();
    q.peek();
    q.enqueue(6);
    q.dequeue();
    q.peek();
    q.dequeue();
    q.peek();
    q.dequeue();
    q.peek();
    q.dequeue();
    q.peek();
}