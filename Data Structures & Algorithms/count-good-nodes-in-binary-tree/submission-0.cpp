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
    void solve(TreeNode* root, int curr_max, int& count) {
        if (root == nullptr) {
            return;
        }

        if (root->val >= curr_max) {
            curr_max = root->val;
            count++;
        }

        solve(root->left, curr_max, count);
        solve(root->right, curr_max, count);
    }
public:
    int goodNodes(TreeNode* root) {
        int count = 0;
        solve(root, root->val, count);

        return count;
    }
};
