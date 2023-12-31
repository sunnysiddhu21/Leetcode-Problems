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
    Node* connect(Node* root) {
        Node* levelStart = root;

        while (levelStart) {
            Node* current = levelStart;
            Node* prev = nullptr;

            while (current) {
                if (current->left) {
                    if (prev) {
                        prev->next = current->left;
                    } else {
                        levelStart = current->left;
                    }
                    prev = current->left;
                }

                if (current->right) {
                    if (prev) {
                        prev->next = current->right;
                    } else {
                        levelStart = current->right;
                    }
                    prev = current->right;
                }

                current = current->next;
            }

            while (levelStart && !levelStart->left && !levelStart->right) {
                levelStart = levelStart->next;
            }
        }
        return root;
    }
};