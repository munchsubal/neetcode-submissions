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
            else if (key > root->val) {
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

    TreeNode* mergeTrees(TreeNode* left, TreeNode* right) {
        TreeNode* curr = left;

        if (!curr) return right;

        while (curr->right != nullptr) {
            curr = curr->right;
        }
        curr->right = right;
        return left;
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr) {
            return nullptr;
        }

        auto [x, y] = findNodeAndParent(root, key);
        if (!x) return root;

        TreeNode* left = x->left;
        TreeNode* right = x->right;

        TreeNode* mergedTree = mergeTrees(left, right);

        if (!y) return mergedTree;
        
        if (x == y->left) y->left = mergedTree;
        else y->right = mergedTree;

        x->left = nullptr;
        x->right = nullptr;
        delete x;

        return root;
    }
};