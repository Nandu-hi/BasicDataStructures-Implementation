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
    node* root;
    public:
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
                cout << curr->vint;
            }
            else{
                cout << curr->vchar;
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

int main(){
    string s;
    cin >> s;
    tree t(s);
    t.infix();
    t.preorder();
}