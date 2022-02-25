// 解法1：递归遍历，时间复杂度O(n)，空间复杂度O(n)
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
public:
    void traversal(TreeNode* root, vector<int> &result){
        if(root == nullptr) return;
        result.push_back(root->val);
        traversal(root->left, result);
        traversal(root->right, result);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        traversal(root, result);
        return result;
    }
};

// 解法2：迭代遍历，时间复杂度O(n)，空间复杂度O(n)
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        if(root == nullptr) return result;

        stack<TreeNode*> s;
        s.push(root);
        while(!s.empty()){
            TreeNode* p = s.top();
            s.pop();
            
            result.push_back(p->val);
            if(p->right != nullptr)  s.push(p->right);
            if(p->left != nullptr)  s.push(p->left);
        }
        return result;
    }
};