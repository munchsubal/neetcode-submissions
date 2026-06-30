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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == nullptr) {
            return new TreeNode(val);
        }
        
        TreeNode* parent = nullptr;
        TreeNode* curr = root;

        while (curr != nullptr) {
            if (val < curr->val) {
                parent = curr;
                curr = curr->left;
            }
            else {
                parent = curr;
                curr = curr->right;
            }
        }

        TreeNode* newNode = new TreeNode(val);
        if (val < parent->val) {
            parent->left = newNode;
        }
        else {
            parent->right = newNode;
        }

        return root;
    }
};