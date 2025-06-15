#include <vector>
#include <queue>
#include <iostream>
#include <map>
#include <stack>
using namespace std;

class Node{
    public:
int data;
Node *left;
Node *right;

    Node(int data){
           this->data = data;
           this->left = nullptr;
           this->right = nullptr;
    }
};

class Tree{
    private:
    Node* tree_root = nullptr;

    public:

    void insert_node(int data){
        Node* new_node = new Node(data);

        if (tree_root == nullptr){
            tree_root = new_node;
            return;
        }

        Node* traveller = tree_root;
        Node* parent = nullptr;

        while(traveller!=nullptr){
            parent = traveller;
            if(new_node->data>traveller->data){
                traveller = traveller->right;
            }
            else traveller = traveller->left;
        }

        if (parent->data < new_node->data) parent->right = new_node;
        else parent->left = new_node;

    }

    // Accending Order (Left->Root->Right)
    void assending_inorder_traversal(){
        Node* traveller = tree_root;
        stack<Node*> st;
        while(traveller!=nullptr || !st.empty()){
            while(traveller!=nullptr){
                st.push(traveller);
                traveller = traveller -> left;
            }
            traveller = st.top();
            cout<< traveller->data << " ";
            st.pop();
            traveller = traveller->right;
        }
    }

    // Descending Order (Right->Root->Left)
    void descending_inorder_traversal(){
        Node* traveller = tree_root;
        stack<Node*> st;
        while(traveller!=nullptr || !st.empty()){
            while(traveller!=nullptr){
                st.push(traveller);
                traveller = traveller -> right;
            }
            traveller = st.top();
            cout<< traveller->data << " ";
            st.pop();
            traveller = traveller->left;
        }
    }
};

int main(){
Tree my_tree;
my_tree.insert_node(10);
my_tree.insert_node(5);
my_tree.insert_node(15);
my_tree.insert_node(3);
my_tree.insert_node(7);
my_tree.insert_node(12);
my_tree.insert_node(18);

my_tree.assending_inorder_traversal();
std::cout<<"\n";
my_tree.descending_inorder_traversal();

return 0;
}