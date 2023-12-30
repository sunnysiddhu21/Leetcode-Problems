/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* flattenTree(TreeNode* root){
        if(root == NULL){
            return NULL;
        }
        if(root->left == NULL && root->right == NULL){
            return root;
        }
        
        TreeNode* lastLeftPtr = flattenTree(root->left);
        TreeNode* lastRightPtr = flattenTree(root->right);
        if(lastLeftPtr != NULL){
            if(root->right){
                lastLeftPtr->right=root->right;
            }
            root->right = root->left;
            root->left = NULL;
        }
            
       
        if(lastRightPtr == NULL){
            return lastLeftPtr;
        }
        return lastRightPtr;
    }

    void printTree(TreeNode* root){
        if(root==NULL){
            return;
        }
        cout << "root->val:  " << root->val << endl;
        if(root->left){
            cout << "root->left->val:  " << root->left->val<<  endl;
        }
        if(root->right){
            cout << "root->right->val:  " << root->right->val<<  endl;
        }
        printTree(root->left);
        printTree(root->right);
    }


    void flatten(TreeNode* root) {
        cout << "*********************" << endl;
        if(root == NULL){
            return;
        }
        flattenTree(root);
        if(root->left == NULL){
            flattenTree(root->right);
        }
        cout << "Printing Tree" << endl;
        printTree(root);
    }
};