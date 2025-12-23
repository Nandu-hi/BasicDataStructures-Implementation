#include<iostream>
#include<algorithm>
using namespace std;

class MyArray{
    private:
        int* data;
        int size;
        int capacity;
        void resize(int ncap){
            int* newarr=new int[ncap];
            for(int i=0;i<size;i++){
                newarr[i]=data[i];
            }
            capacity=ncap;
            delete[] data;
            int* data = newarr;
        }
    public:
        MyArray(){
            data=NULL;
            size=0;
            capacity=0;
        }
        MyArray(int n){
            data=new int[n];
            size=n;
            capacity=n;
            for(int i=0;i<n;i++){
                data[i]=0;
            }
        }
        MyArray(int n,int value){
            data=new int[n];
            size=n;
            capacity=n;
            for(int i=0;i<n;i++){
                data[i]=value;
            }
        }

        void InsertAt(int index,int value){
            if(index>=0 && index<size){
                if(size==capacity){
                    int ncap;
                    if(size==0){
                        ncap=1;
                    }
                    else{
                        ncap=capacity*2;
                    }
                    resize(ncap);
                }
                size++;
                int i=size-2;
                while(i!=index-1){
                    data[i+1]=data[i];
                    i--;
                }
                data[index]=value;
            }
        }

        int Size(){
            return size;
        }

        bool empty(){
            return size==0;
        }

        int at(int index){
            if(index>=0 && index<size){
                return data[index];
            }
            else{
                exit(-1);
            }
        }

        bool IsSorted(){
            for(int i=0;i<size-1;i++){
                if(data[i+1]>data[i]){
                    return false;
                }
            }
            return true;
        }

        bool PairSumEqualTo(int k){
            if(!IsSorted()){
                sort(data,data+size);
            }
            int l=0;
            int r=size-1;
            while(l<r){
                if(data[l]+data[r]<k){
                    l++;
                }
                else if(data[l]+data[r]>k){
                    r--;
                }
                else{
                    return true;
                }
            }
            return false;

        }
        int& operator[](int index){
            if(index>=0 && index<size){
                return data[index];
            }
            else{
                exit(-1);
            }
        }


};
int main(){
    int n;
    cin >> n;
    MyArray v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    int k;
    cin >> k;
    bool ret=v.PairSumEqualTo(k);
    if(ret==true){
        cout << "Yes"<< endl;
    }
    else{
        cout << "No"<<endl;
    }

}