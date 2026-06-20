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

        int diam = find_diam(root->left, ans) + find_diam(root->right, ans) + 1;
        ans = max(ans, diam);
        return 1 + max(find_diam(root->left, ans), find_diam(root->right, ans));
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        int ans = INT_MIN;
        find_diam(root, ans);
        return ans - 1;
    }   
};
