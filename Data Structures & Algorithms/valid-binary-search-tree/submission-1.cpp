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
    bool checkValidBST(TreeNode* root, int l, int r) {
        if (root == nullptr) {
            return true;
        }

        if (root->val <= l || root->val >= r) {
            return false;
        }

        return checkValidBST(root->left, l, min(r, root->val)) && checkValidBST(root->right, max(l, root->val), r);
    }
public:
    bool isValidBST(TreeNode* root) {

        return checkValidBST(root, INT_MIN, INT_MAX);

    }
};
