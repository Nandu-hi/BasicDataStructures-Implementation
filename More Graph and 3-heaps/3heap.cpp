#include<bits/stdc++.h>
using namespace std;
class theap{
    private:
        vector<int> data;
    public:
        void swap(int & a,int & b){
            int temp=a;
            a=b;
            b=temp;
        }
        void percolateup(){
            int i=data.size()-1;
            while(i>0 && data[i%3==0 ? i/3-1 : i/3]<data[i]){
                swap(data[i],data[i/3]);
                i=i%3==0 ? i/3-1 : i/3;
            }
        }
        void insert(int x){
            data.push_back(x);
            percolateup();
        }
        void percolatedown(int index){
            if(index>=data.size()) return;
            if(3*index+1>=data.size()){
                return;
            }
            else{
                int maxindex=3*index+1;
                if(3*index+2<data.size() && data[3*index+2]>data[maxindex]) maxindex=3*index+2;
                if(3*index+3<data.size() && data[3*index+3]>data[maxindex]) maxindex=3*index+3;
                if(data[maxindex]>data[index]){
                    swap(data[maxindex],data[index]);
                    percolatedown(maxindex);
                }
                else{
                    return;
                }
            }
        }
        void deletemax(){
            if(data.size()==0){
                return;
            }
            swap(data[0],data[data.size()-1]);
            data.pop_back();
            percolatedown(0);
        }
        void maximum(){
            if(data.size()==0){
                cout << "Empty" << endl;
                return;
            }
            else{
                cout << data[0] << endl;
            }
        }
        void buildheap(vector<int> v){
            data.clear();
            for(auto it:v){
                data.push_back(it);
            }
            for(int i=v.size()/3;i>=0;i--){
                percolatedown(i);
            }
        }
        vector<int> printgtK(int k){
            vector<int> ans;
            printgtK(k,0,ans);
            return ans;
        }

        //below is an order k algo
        void printgtK(int k,int index,vector<int> & ans){
            if(index<data.size() && data[index]>k){
                printgtK(k,3*index+1,ans);
                printgtK(k,3*index+2,ans);
                printgtK(k,3*index+3,ans);
                ans.push_back(data[index]);
            }
            else{
                return;
            }
        }
};
int main(){
    int size,k;
    cin >> size >> k;
    vector<int> data;
    for(int i=0;i<size;i++){
        int val;
        cin >> val;
        data.push_back(val);
    }
    theap H;
    H.buildheap(data);
    vector<int> ans=H.printgtK(k);
    sort(ans.begin(),ans.end());
    for(auto it: ans){
        cout << it << endl;
    }

}