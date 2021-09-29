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
// 用双DFS来做
class Solution
{
private:
    int count = 0;

public:
    void rootSum(TreeNode *root, int targetSum)
    {
        if (!root)
            return;
        if (root->val == targetSum)
            count++;
        rootSum(root->left, targetSum - root->val);
        rootSum(root->right, targetSum - root->val);
    }
    int pathSum(TreeNode *root, int targetSum)
    {
        // 双DFS + 条件判断
        if (!root)
            return 0;
        rootSum(root, targetSum);
        pathSum(root->left, targetSum);
        pathSum(root->right, targetSum);

        return count;
    }
};

// 用前缀和来做，prefix定义的是从根节点到当前节点为length长度的节点数目。
class Solution
{
private:
    int count = 0;
    map<int, int> prefix;

public:
    void dfs(TreeNode *root, int curr, int targetSum)
    {
        if (!root)
            return;

        curr += root->val;
        if (prefix.count(curr - targetSum))
        {
            count += prefix[curr - targetSum];
        }

        prefix[curr]++;
        dfs(root->left, curr, targetSum);
        dfs(root->right, curr, targetSum);
        prefix[curr]--;
    }

    int pathSum(TreeNode *root, int targetSum)
    {
        // 前缀和
        prefix[0] = 1;
        dfs(root, 0, targetSum);
        return count;
    }
};