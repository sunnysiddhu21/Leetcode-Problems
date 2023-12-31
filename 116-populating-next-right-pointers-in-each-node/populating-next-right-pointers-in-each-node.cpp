/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
void helper(Node* &root)//by refrence pass kiye hai taki changes originally reflect ho sake
{
    if(root==nullptr)
    {
        return;
    }
    if(root->left)
    {
        //agr left exist krta hai it mean ki obviou right v exist krta hai kyuki kisi v parent ka left and right dono hai question me de rkha hai inhone phle se hi
        root->left->next=root->right;
        //and agr root->next agr exist kr rha hai to use v jod do
        if(root->next!=nullptr)
        {
            root->right->next=root->next->left;
        }
    }
    helper(root->left);
    helper(root->right);
}
    Node* connect(Node* root) {
        //lets do with the recursive solution
        helper(root);
        return root;
    }
};