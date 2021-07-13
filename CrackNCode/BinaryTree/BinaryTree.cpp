#include <bits/stdc++.h>

using namespace std;

struct Node{
    int value;
    Node* left = NULL;
    Node* right = NULL;
    Node(int value){
        this->value = value;
    }
};

void addNode(Node* root,int value){
    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        if(q.front()->left == NULL){
            q.front()->left = new Node(value);
            return;
        }else{
            q.push(q.front()->left);
        }

        if(q.front()->right == NULL){
            q.front()->right = new Node(value);
            return;
        }else{
            q.push(q.front()->right);
        }

        q.pop();
    }
}

void inOrder(Node* root){
    if(root!=NULL){
        inOrder(root->left);
        cout << root->value << " ";
        inOrder(root->right);
    }
}

void preOrder(Node* root){
    if(root!=NULL){
        cout << root->value << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

void postOrder(Node* root){
    if(root!=NULL){
        postOrder(root->left);
        postOrder(root->right);
        cout << root->value << " ";
    }
}

void bfs(Node* root){
    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        cout << q.front()->value << " ";
        if(q.front()->left != NULL){
            q.push(q.front()->left);
        }

        if(q.front()->right != NULL){
            q.push(q.front()->right);
        }

        q.pop();
    }
}

int main(){
    ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);

    Node* root = new Node(1);
    addNode(root,2);
    addNode(root,3);
    addNode(root,4);
    addNode(root,5);

    preOrder(root); cout << "\n";
    inOrder(root); cout << "\n";
    postOrder(root); cout << "\n";
    bfs(root); cout << "\n";

    return 0;
}