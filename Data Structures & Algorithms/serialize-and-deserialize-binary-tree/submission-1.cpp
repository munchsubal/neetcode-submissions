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

class Codec {
private:
    vector<string> tokenize_string(string s) {
        int i = 0;

        vector<string> tokens;
        while (i < s.size()) {
            string token = "";
            while (s[i] != ',') {
                token += s[i];
                i++;
            }
            tokens.push_back(token);
            i++;
        }

        return tokens;
    }
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == nullptr) return "n";
        
        string serialised_bt = "";
        queue<TreeNode*> q;
        q.push(root);
        serialised_bt += to_string(root->val);
        serialised_bt += ",";

        while (!q.empty()) {
            int level = q.size();

            for (int i=0; i<level; i++) {
                TreeNode* node = q.front();
                q.pop();

                if (node->left != nullptr) {
                    q.push(node->left);
                    serialised_bt += to_string(node->left->val);
                    serialised_bt += ",";
                }
                else {
                    serialised_bt += "n,";
                }

                if (node->right != nullptr) {
                    q.push(node->right);
                    serialised_bt += to_string(node->right->val);
                    serialised_bt += ",";
                }
                else {
                    serialised_bt += "n,";
                }  
            }
        }
        cout << serialised_bt;
        return serialised_bt;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data == "n") return nullptr;

        vector<string> tokens = tokenize_string(data);

        queue<TreeNode*> q;
        TreeNode* root = new TreeNode(stoi(tokens[0]));
        q.push(root);
        int idx = 0;
        while (!q.empty()) {
            int level = q.size();

            for (int i=0; i<level; i++) {
                TreeNode* node = q.front();
                int leftChild = idx + 1;
                int rightChild = idx + 2;
                q.pop();

                if (leftChild < tokens.size() && tokens[leftChild] != "n") {
                    TreeNode* newNode = new TreeNode(stoi(tokens[leftChild]));
                    node->left = newNode;
                    q.push(newNode);
                }
                else {
                    node->left = nullptr;
                }
                
                if (rightChild < tokens.size() && tokens[rightChild] != "n") {
                    TreeNode* newNode = new TreeNode(stoi(tokens[rightChild]));
                    node->right = newNode;
                    q.push(newNode);
                }
                else {
                    node->right = nullptr;
                }

                idx += 2;
            }
        }

        return root;
    }
};
