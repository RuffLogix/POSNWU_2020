#include<bits/stdc++.h>

using namespace std;

struct Node{
    int data = 0;
    Node* left = NULL;
    Node* right = NULL;

    Node(int value){
        this->data = value;
    }
};

Node* insert_tree(Node* root,int value);
int query_level(Node* root,int levels);
int get_level(Node* root,Node* new_node);

int main(){
    using namespace std;
    ios_base::sync_with_stdio(false),cin.tie(nullptr);

    /*Create Tree*/
    Node* root = new Node(10);
    root->left = new Node(11);
    root->left->left = new Node(7);
    root->right = new Node(9);
    root->right->left = new Node(15);
    root->right->right = new Node(8);

    
    root = insert_tree(root,12);

    cout << root->left->right->data;
    return 0;
}

int query_level(Node* root,int levels){
    if(root!=NULL)return max(query_level(root->left,levels),query_level(root->right,levels))+1;
    return 0;
}

int get_level(Node* root,Node* new_node){
    return query_level(root,0) - query_level(new_node,0);
}

Node* insert_tree(Node* root,int value){
    if(root==NULL){
        root = new Node(value);
        return root;
    }

    queue<Node* > q;
    q.push(root);

    while(not q.empty()){
        if(q.front()->left == NULL){
            q.front()->left = new Node(value);
            return root;
        }else{
            q.push(q.front()->left);
        }

        if(q.front()->right == NULL){
            q.front()->right = new Node(value);
            return root;
        }else{
            q.push(q.front()->right);
        }

        q.pop();
    }
}