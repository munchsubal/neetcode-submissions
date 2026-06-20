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
    int find_diam(TreeNode* root, int& ans) {
        if (root == nullptr) {
            return 0;
        }

        int lh = find_diam(root->left, ans);
        int rh = find_diam(root->right, ans);

        ans = max(ans, lh + rh);

        return 1 + max(lh, rh);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = INT_MIN;
        find_diam(root, ans);
        return ans;
    }   
};
