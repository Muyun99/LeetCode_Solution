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
class Solution
{
public:
    vector<vector<int>> path;
    vector<int> prefix;

    vector<vector<int>> pathSum(TreeNode *root, int targetSum)
    {
        if (!root)
            return path;

        prefix.push_back(root->val);
        if (!root->left && !root->right)
            if (root->val == targetSum)
                path.push_back(prefix);

        pathSum(root->left, targetSum - root->val);
        pathSum(root->right, targetSum - root->val);
        prefix.pop_back();
        return path;
    }
};