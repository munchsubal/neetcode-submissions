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
private:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == nullptr || q == nullptr) {
            return (p == q);
        }

        return (p->val == q->val) && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }

    bool checkSubtree(TreeNode* root, TreeNode* subRoot, bool& ans) {
        if (root == nullptr) {
            return (root == subRoot);
        }

        ans = ans || isSameTree(root, subRoot);
        return checkSubtree(root->left, subRoot, ans) || checkSubtree(root->right, subRoot, ans);
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        bool ans = false;
        checkSubtree(root, subRoot, ans);
        return ans;
    }
};
