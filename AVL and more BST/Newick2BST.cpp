#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    char vchar;
    node* left;
    node* right;
    node(char c){
        vchar=c;
        left=NULL;
        right=NULL;
    }
};

class tree{
    node* root;
    public:
    tree():root(NULL){}


    void Newick2BT(string s){
        Newick2BT(s,root);
    }
    void Newick2BT(string s,node* & root){
        int n=s.size();
        node* newnode = new node(s[n-1]);
        root=newnode;
        if(n==1) return;
        int i=1;
        vector<char> open;
        int comma=n-1;
        open.push_back('(');
        while(i<n){
            if(open.size()==1 && s[i]==','){
                comma=i;
                break;
            }
            else if(s[i]=='('){
                open.push_back('(');
            }
            else if(s[i]==')'){
                open.pop_back();
            }
            i++;
        }
        if(comma==n-1){
            string left="";
            for(int i=1;i<n-2;i++){
                left+=s[i];
            }
            Newick2BT(left,root->left);
        }
        else{
            string left="";
            string right="";
            int j;
            for(j=1;j<comma;j++){
                left+=s[j];
            }
            j++;
            while(j<n-2){
                right+=s[j];
                j++;
            }
            Newick2BT(left,root->left);
            Newick2BT(right,root->right);
        }
    }

    bool isBST(string s){
        int n=s.size();
        if(n==1) return true;
        int i=1;
        vector<char> open;
        int comma=n-1;
        open.push_back('(');
        while(i<n){
            if(open.size()==1 && s[i]==','){
                comma=i;
                break;
            }
            else if(s[i]=='('){
                open.push_back('(');
            }
            else if(s[i]==')'){
                open.pop_back();
            }
            i++;
        }
        if(comma==n-1){
            string left="";
            for(int i=1;i<n-2;i++){
                left+=s[i];
            }
            for(int i=0;i<left.size();i++){
                if(left[i]>='A' && left[i]<='Z'){
                    if(left[i]>s[n-1]){
                        return false;
                    }
                }
            }
            return isBST(left);
        }
        else{
            string left="";
            string right="";
            int j;
            for(j=1;j<comma;j++){
                left+=s[j];
            }
            j++;
            while(j<n-2){
                right+=s[j];
                j++;
            }
            for(int i=0;i<left.size();i++){
                if(left[i]>='A' && left[i]<='Z'){
                    if(left[i]>s[n-1]){
                        return false;
                    }
                }
            }
            for(int i=0;i<right.size();i++){
                if(right[i]>='A' && right[i]<='Z'){
                    if(right[i]<s[n-1]){
                        return false;
                    }
                }
            }
            return isBST(left) && isBST(right);
        }
    }

    void inorder(){
        inorder(root);
        cout << endl;
    }
    void inorder(node* curr){
        if(curr){
            inorder(curr->left);
            cout << curr->vchar << " ";
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
            cout << curr->vchar << " ";
            
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
            cout << curr->vchar;
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
            cout << curr->vchar << " ";
            preorder(curr->left);
            preorder(curr->right);
        }
    }
};
int main(){
    tree t;
    string s;
    cin >> s;
    t.Newick2BT(s);
    t.inorder();
    t.preorder();
}
