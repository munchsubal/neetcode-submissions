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
    int findMaxPathSum(TreeNode* root, int& maxSum) {
        if (root == nullptr) return 0;

        int leftMaxPathSum = findMaxPathSum(root->left, maxSum);
        int rightMaxPathSum = findMaxPathSum(root->right, maxSum);
        int currMaxPathSum = leftMaxPathSum + rightMaxPathSum + root->val;
        maxSum = max(maxSum, currMaxPathSum);

        return max(root->val + max(leftMaxPathSum, rightMaxPathSum), 0);
    }
public:
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;

        findMaxPathSum(root, ans);

        return ans;
    }
};
