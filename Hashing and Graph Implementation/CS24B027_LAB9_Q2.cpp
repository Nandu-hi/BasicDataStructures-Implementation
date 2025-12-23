#include<bits/stdc++.h>
using namespace std;
class HashTable{
    vector<int> Table;
    public:
        HashTable(){
            Table.resize(2003);
            for(auto & it:Table){
                it=INT_MIN;
            }
        }
        int getnextQuad(int & val,int & loc){
            val++;
            loc=(loc-((val-1)*(val-1))+(val)*(val));
            return loc;
        }
        int getnextdouble(int val,int & loc){
            loc=loc+((val*val)+1)%61;
            return loc;
        }
        void Insert(int val){
            if(Search(val)) return;
            int key=(503*val+1087)%2003;
            int loc=key;
            int i=0;
            while(Table[key]!=INT_MIN){
                key=getnextQuad(i,loc)%2003;
            }
            Table[key]=val;
        }
        void InsertD(int val){
            if(Search(val)) return;
            int key=val%61;
            int loc=key;
            while(Table[key]!=INT_MIN){
                key=getnextdouble(val,loc)%2003;
            }
            Table[key]=val;
        }
        bool Search(int val){
            bool ans=false;
            for(int i=0;i<2003;i++){
                if(Table[i]==val){
                    return true;
                }
            }
            return false;
        }
        
        void Delete(int val){
            int key=(503*val+1087)%2003;
            int i=0;
            int loc=key;
            while(Table[key]!=val){
                if(Table[key]==INT_MIN){
                    return;
                }
                key=getnextQuad(i,loc)%2003;
            }
            Table[key]=INT_MIN;
            return;
        }
        void DeleteD(int val){
            int key=val%61;
            int loc=key;
            while(Table[key]!=val){
                if(Table[key]==INT_MIN){
                    return;
                }
                key=getnextdouble(val,loc)%2003;
            }
            Table[key]=INT_MIN;
            return;
        }
        void print(){
            for(int i=0;i<2003;i++){
                if(Table[i]!=INT_MIN){
                    cout << i << " " << Table[i] << endl;
                }
            }
        }
        
};
int main(){
    int q;
    cin >> q;
    string type;
    cin >> type;
    HashTable H;
    while(q--){
        string s;
        cin >> s;
        if(s=="Insert"){
            int x;
            cin >> x;
            if(type=="Quad")
            H.Insert(x);
            else{
                H.InsertD(x);
            }
        }
        else if(s=="Delete"){
            int x;
            cin >> x;
            if(type=="Quad")
            H.Delete(x);
            else H.DeleteD(x);
        }
        else if (s=="Search"){
            int x;
            cin >> x;
                if(H.Search(x)){
                    cout << "TRUE" << endl;
                }
                else{
                    cout << "FALSE" << endl;
                }
            
        }
    }
    H.print();
}