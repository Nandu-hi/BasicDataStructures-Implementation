#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    int x;
    node* next;
    node(int a):x(a),next(NULL){}

};
class HashTable{
    vector<node*> Table;
    public:
        HashTable(){
            Table.resize(2003);
            for(auto & it:Table){
                it=NULL;
            }
        }
        void insert(int val){
            if(!Search(val)){
                int key=(503*val+1087)%2003;
                node* temp=Table[key];
                Table[key]=new node(val);
                Table[key]->next=temp;
            }
        }

        bool Search(int val){
            int key=(503*val+1087)%2003;
            node* curr=Table[key];
            while(curr!=NULL){
                if(curr->x==val){
                    return true;
                }
                curr=curr->next;
            }
            return false;
        }

        void Delete(int val){
            int key=(503*val+1087)%2003;
            if(Table[key]->x==val){
                node* temp=Table[key];
                Table[key]=Table[key]->next;
                delete temp;
                return;
            }
            node* curr=Table[key]->next;
            node* prev=Table[key];
            while(curr!=NULL){
                if(curr->x==val){
                    node* temp=curr;
                    prev->next=curr->next;
                    delete temp;
                    return;
                }
                prev=curr;
                curr=curr->next;
            }

        }
        void Print(){
            for(int i=0;i<2003;i++){
                node* curr=Table[i];
                if(curr){
                    cout << i << " ";
                    while(curr!=NULL){
                        cout << curr->x << " ";
                        curr=curr->next;
                    }
                    cout << endl;
                }
            }
        }
};

int main(){
    int q;
    cin >> q;
    HashTable H;
    while(q--){
        string s;
        cin >> s;
        if(s=="Insert"){
            int x;
            cin >> x;
            H.insert(x);
        }
        else if(s=="Delete"){
            int x;
            cin >> x;
            H.Delete(x);
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
    H.Print();
}