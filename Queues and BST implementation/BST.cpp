#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    int vint;
    char vchar;
    node* left;
    node* right;
    node(char c){
        vint=0;
        vchar=c;
        left=NULL;
        right=NULL;
    }
    node(int i){
        vint=i;
        vchar='\0';
        left=NULL;
        right=NULL;
    }
};

class tree{
    public:
    node* root;
    tree():root(NULL){}
    tree(string s){
        stack<node*> st;
        for(int i=0;i<s.size();i++){
            if(s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='/'){
                node* b=st.top(); st.pop();
                node* a=st.top();st.pop();
                node* newnode=new node(s[i]);
                newnode->left=a;
                newnode->right=b;
                st.push(newnode);
            }
            else{
                node* newnode=new node(s[i]);
                st.push(newnode);
            }
        }
        root=st.top();
        st.pop();
    }

    void inorder(){
        inorder(root);
        cout << endl;
    }
    void inorder(node* curr){
        if(curr){
            inorder(curr->left);
            if(curr->vchar=='\0'){
                cout << curr->vint;
            }
            else{
                cout << curr->vchar;
            }
            inorder(curr->right);
        }
    }
    void postorder(){
        postorder(root);
        cout << endl;
    }
    void postorder(node* curr){
        if(curr){
            postorder(curr->left);
            postorder(curr->right);
            if(curr->vchar=='\0'){
                cout << curr->vint << ' ';
            }
            else{
                cout << curr->vchar << ' ';
            }
        }
    }
    void infix(){
        infix(root);
        cout << endl;
    }
    void infix(node* curr){
        if(curr){
            if(curr->left)
            cout << '(';
            infix(curr->left);
            if(curr->vchar=='\0'){
                cout << curr->vint;
            }
            else{
                cout << curr->vchar;
            }
            infix(curr->right);
            if(curr->left)
            cout << ')';
        }
    }
    void preorder(){
        preorder(root);
        cout << endl;
    }
    void preorder(node* curr){
        if(curr){
            if(curr->vchar=='\0'){
                cout << curr->vint;
            }
            else{
                cout << curr->vchar;
            }
            preorder(curr->left);
            preorder(curr->right);
        }
    }
};

class BST:public tree{
    public:
    BST(){
        root=NULL;
    }
    void Search(int x){
        if(!root){
            insert(x);
            return;
        }
        node* curr=root;
        while(curr){
            if(curr->vint>x){
                curr=curr->left;
            }
            else if(curr->vint<x){
                curr=curr->right;
            }
            else{
                break;
            }
        }
        if(!curr){
            insert(x);
        }
        else{
            return;
        }
    }
    void insert(int x){
        node* newnode = new node(x);
        if(!root){
            root=newnode;
            return;
        }
        node* prev=NULL;
        node* curr=root;
        while(curr){
            prev=curr;
            if(curr->vint>x){
                curr=curr->left;
            }
            else if(curr->vint<x){
                curr=curr->right;
            }
        }
        if(x<prev->vint){
            prev->left=newnode;
        }
        else{
            prev->right=newnode;
        }
    }

    node* Findmin(node* curr){
        while(curr){
            if(!curr->left) return curr;
            Findmin(curr->left);
        }
        return curr;
    }
    void remove(int x){
        remove(x,root);
    }
    void remove(int & x,node* & t){
        if(!t) return;
        else if(t->vint<x){
            remove(x,t->right);
        }
        else if(t->vint>x){
            remove(x,t->left);
        }
        else if(t->left!=NULL && t->right!=NULL){
            t->vint=Findmin(t->right)->vint;
            remove(t->vint,t->right);
        }
        else{
            node* temp=t;
            if(t->left==NULL){
                t=t->right;
            }
            else{
                t=t->left;
            }
            delete temp;
        }
    }
    bool greaterthan(int x,node* curr){
        if(!curr){
            if(x>curr->vint) return false;
            bool left=greaterthan(x,curr->left);
            bool right=greaterthan(x,curr->right);
            return left&&right;
        }
        return true;
    }
    bool lessthan(int x,node* curr){
        if(!curr){
            if(x<curr->vint) return false;
            bool left=lessthan(x,curr->left);
            bool right=lessthan(x,curr->right);
        }
        return true;
    }
    bool isBST(){
        return isBST(root);
    }
    bool isBST(node* curr){
        if(!curr){
            bool left=greaterthan(curr->vint,curr->right);
            bool right=lessthan(curr->vint,curr->left);
            if(left&&right){
                bool checkleft=isBST(curr->left);
                bool checkright=isBST(curr->right);
                return checkleft&&checkright;
            }
            else{
                return false;
            }
        }
        return true;
    }

};

int main(){
    BST t;
    string s;
    while(cin >> s){
        if(s=="Insert"){
            int x;
            cin >> x;
            t.Search(x);
        }
        else if(s=="Delete"){
            int x;
            cin>>x;
            t.remove(x);
        }
        else{
            t.postorder();
        }
    }
}