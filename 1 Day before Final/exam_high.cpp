#include <bits/stdc++.h>

using namespace std;

class Node{
    public : 
        int data;
        Node *left = NULL;
        Node *right = NULL;

        Node (int data){
            this->data = data;
        }
};

Node* addNode(Node* root,int data){
    if(root==NULL){root = new Node(data);return root;}

    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        if(q.front()->left==NULL){
            q.front()->left = new Node(data);
            break;
        }else if(q.front()->left->data!=-1){
            q.push(q.front()->left);
        }

        if(q.front()->right==NULL){
            q.front()->right = new Node(data);
            break;
        }else if(q.front()->right->data!=-1){
            q.push(q.front()->right);
        }

        q.pop();
    }

    return root;
}

int getLevel(Node* root){
    if(root==NULL || root->data==-1)return 0;
    return max(getLevel(root->left),getLevel(root->right))+1;
}

int main(){
    ios_base::sync_with_stdio(0),cout.tie(0),cin.tie(0);

    Node* root = NULL;

    int x = 0;
    do{
        scanf("%d",&x);
        if(x==-2)break;
        root = addNode(root,x);
    }while(x!=-2);

    printf("%d",getLevel(root));
    return 0;
}