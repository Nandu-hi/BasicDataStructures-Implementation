#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    int val;
    node* left;
    node* right;
    int height;
    node():val(0),left(NULL),right(NULL),height(0){}
    int updateheight(){
        int hleft=-1;
        if(left) hleft=left->height;
        int hright=-1;
        if(right) hright=right->height;
        height=1+max(hleft,hright);
        return height;
    }
    int getBalance(){
        int hleft=-1;
        if(left) hleft=left->height;
        int hright=-1;
        if(right) hright=right->height;
        return hleft-hright;
    }
    bool imbalanced(){
        return abs(getBalance())>1;
    }
    void print(){
        cout << val << " ";
    }
};
class AVL{
    node* root;
    public:
    AVL():root(NULL){}
    node* rotateleft(node* k1){
        node* k2=k1->right;
        k1->right=k2->left;
        k2->left=k1;
        k1->updateheight();
        k2->updateheight();
        return k2;
    }
    node* rotateright(node* k1){
        node* k2=k1->left;
        k1->left=k2->right;
        k2->right=k1;
        k1->updateheight();
        k2->updateheight();
        return k2;
    }
    node* rotateleftright(node* k1){
        k1->left=rotateleft(k1->left);
        return rotateright(k1);
    }
    node* rotaterightleft(node* k1){
        k1->right=rotateright(k1->right);
        return rotateleft(k1);
    }

    void insert(int x){
        node* ptr = new node;
        ptr->val=x;
        insert(ptr,root);
    }

    void insert(node* ptr,node* & curr){
        if(!curr){
            curr=ptr;
            return;
        }
        else if(curr->val<ptr->val){
            insert(ptr,curr->right);
            if(curr->imbalanced()){
                if(ptr->val>curr->right->val) curr=rotateleft(curr);
                else curr=rotaterightleft(curr);
            }
        }
        else if(curr->val>ptr->val){
            insert(ptr,curr->left);
            if(curr->imbalanced()){
                if(ptr->val<curr->left->val) curr=rotateright(curr);
                else curr=rotateleftright(curr);
            }
        }
        curr->updateheight();
    }

    node* findMin(node* t){
        if(t==NULL) return NULL;
        while(t->left!=NULL) t=t->left;
        return t;
    }

    void remove(int x){
        root=remove(x,root);
    }

    node* remove(int x,node* t){
        if(!t) return NULL;
        if(x<t->val){
            t->left=remove(x,t->left);
        }
        else if(x>t->val){
            t->right=remove(x,t->right);
        }
        else{
            if(!t->left||!t->right){
                node* temp=t->left?t->left:t->right;
                if(!temp){
                    temp=t;
                    t=NULL;
                }
                else{
                    *t=*temp;
                }
                delete temp;
            }
            else{
                node* temp=findMin(t->right);
                t->val=temp->val;
                t->right=remove(temp->val,t->right);
            }
        }
        if(!t) return t;
        t->updateheight();
        int balance=t->getBalance();
        if(balance>1){
            if(t->left->getBalance()>=0) return rotateright(t);
            else return rotateleftright(t);
        }
        if(balance<-1){
            if(t->right->getBalance()<=0) return rotateleft(t);
            else return rotaterightleft(t);
        }
        return t;
    }
    
    void print(){
        inorder(root);
        cout << endl;
    }
    void inorder(node* t){
        if(!t) return;
        inorder(t->left);
        cout << t->val << " ";
        inorder(t->right);
    }
};
int main(){
    AVL tree;
    tree.insert(10);
    tree.insert(20);
    tree.insert(30);
    tree.insert(40);
    tree.insert(50);
    tree.insert(25);
    tree.print();
    tree.remove(30);
    tree.print();
    return 0;
}