#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    int vint;
    node* left;
    node* right;
    node(int i){
        vint=i;
        left=NULL;
        right=NULL;
    }
};

class tree{
    public:
    node* root;
    tree():root(NULL){}

    void inorder(){
        inorder(root);
        cout << endl;
    }
    void inorder(node* curr){
        if(curr){
            inorder(curr->left);
            cout << curr->vint << ' ';
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
            cout << curr->vint << ' ';
        }
    }
    void preorder(){
        preorder(root);
        cout << endl;
    }
    void preorder(node* curr){
        if(curr){
            cout << curr->vint << " ";
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
    
    BST(vector<int> v){
        if(v.size()==0){
            root=NULL;
        }
        else{
            stack<node*> st;
            root = new node(v[0]);
            st.push(root);
            for(int i=1;i<v.size();i++){
                if(v[i]<st.top()->vint){
                    st.top()->left=new node(v[i]);
                    st.push(st.top()->left);
                }
                else{
                    node* peek;
                    while(!st.empty() && st.top()->vint<v[i]){
                        peek = st.top();
                        st.pop();
                    }
                    peek->right=new node(v[i]);
                    st.push(peek->right);
                }
            }
        }
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
    int n;
    cin >> n;
    vector<int> v;
    for(int i=0;i<n;i++){
        int value;
        cin >> value;
        v.push_back(value);
    }
    BST t(v);
    t.postorder();
}