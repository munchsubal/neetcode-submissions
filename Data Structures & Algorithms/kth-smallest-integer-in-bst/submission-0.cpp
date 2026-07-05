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
    void findKthSmallest(TreeNode* root, int k, int& ans, int& cnt) {
        if (root == nullptr) {
            return;
        }

        findKthSmallest(root->left, k, ans, cnt);
        cnt++;
        if (cnt == k) {
            ans = root->val;
            return;
        }
        findKthSmallest(root->right, k, ans, cnt);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        if (root == nullptr) {
            return -1;
        }

        int ans = -1;
        int cnt = 0;
        findKthSmallest(root, k, ans, cnt);
        return ans;
    }
};
