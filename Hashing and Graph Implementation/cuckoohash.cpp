#include<bits/stdc++.h>
using namespace std;

void swap(int & a,int & b){
    int temp=a;
    a=b;
    b=temp;
}
int computeh1(int key,int size){
    return (key*13+7)%size;
}
void insert(int* & arr,int value,int & size);
void rehash(int* & arr,int value,int &size){
    size=2*size;
    vector<int> v;
    for(int i=0;i<size;i++){
        if(arr[i]!=INT_MIN){
            v.push_back(arr[i]);
        }
    }
    int* temp=arr;
    delete[] temp;
    arr=new int[size*2];
    for(int i=0;i<2*size;i++){
        arr[i]=INT_MIN;
    }
    for(auto it:v){
        insert(arr,it,size);
    }
    
}
int computeh2(int key,int size){
    return ((key*29)%23)%size +size;
}

void insert(int* & arr,int value,int & size){
    int f=2;
    int key=computeh1(value,size);
    swap(arr[key],value);
    int steps=1;
    int msteps=6*log(max(2,size));
    while(value!=INT_MIN && steps<msteps){
        if(f==1){
            key=computeh1(value,size);
            f=3-f;
            swap(arr[key],value);
        }
        else{
            key=computeh2(value,size);
            f=3-f;
            swap(arr[key],value);
        }
        steps++;
    }
    if(value!=INT_MIN){
        rehash(arr,value,size);
    }
}


void print(int* & arr,int size){
    for(int i=0;i<size;i++){    
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main(){
    int size;
    cin >> size;
    int * arr = new int[2*size];
    for(int i=0;i<2*size;i++){
        arr[i]=INT_MIN;
    }
    insert(arr,53,size);
    insert(arr,41,size);
    insert(arr,33,size);
    insert(arr,21,size);
    insert(arr,103,size);
    insert(arr,91,size);
    insert(arr,23,size);
    insert(arr,11,size);
    print(arr,size);

}