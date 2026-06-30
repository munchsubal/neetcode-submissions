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
    pair<TreeNode*, TreeNode*> findNodeAndParent(TreeNode* root, int key) {
        if (root == nullptr) {
            return {nullptr, nullptr};
        }

        TreeNode* parent = nullptr;
        while (root != nullptr) {
            if (root->val == key) {
                return {root, parent};
            }
            else if (root->val < key) {
                parent = root;
                root = root->right;
            }
            else {
                parent = root;
                root = root->left;
            }
        }

        return {nullptr, nullptr};
    }

    TreeNode* merge(TreeNode* left, TreeNode* right) {
        if (left == nullptr) {
            return right;
        }

        TreeNode* curr = left;
        while (curr->right != nullptr) {
            curr = curr->right;
        }
        curr->right = right;
        return left;
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        pair<TreeNode*, TreeNode*> p = findNodeAndParent(root, key);
        TreeNode* x = p.first;
        TreeNode* y = p.second;
        if (x == nullptr) {
            return root;
        }

        TreeNode* left = x->left;
        TreeNode* right = x->right;

        TreeNode* newSubtree = merge(left, right);

        if (y == nullptr) {
            return newSubtree;
        }

        if (y->left == x) {
            y->left = newSubtree;
        }
        else {
            y->right = newSubtree;
        }
        
        delete x;
        return root;
    }
};