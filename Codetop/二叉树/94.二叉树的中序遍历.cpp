// 一刷：2022 03 18 会做递归和迭代，不会Morris

// 递归法
// 时间复杂度：O(n)，其中 n 为二叉树节点的个数。二叉树的遍历中每个节点会被访问一次且只会被访问一次。
// 空间复杂度：O(n)。空间复杂度取决于递归的栈深度，而栈深度在二叉树为一条链的情况下会达到 O(n) 的级别。
class Solution {
public:
    vector<int> ans;
    vector<int> inorderTraversal(TreeNode* root) {
        if(root == nullptr) return ans;
        inorderTraversal(root->left);
        ans.push_back(root->val);
        inorderTraversal(root->right);

        return ans;
    }
};

// 迭代法
// 时间复杂度：O(n)，其中 n 为二叉树节点的个数。二叉树的遍历中每个节点会被访问一次且只会被访问一次。
// 空间复杂度：O(n)。空间复杂度取决于栈深度，而栈深度在二叉树为一条链的情况下会达到 O(n) 的级别。

class Solution {
public:
    
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root == nullptr) return ans;

        stack<TreeNode*> nodeStack;
        nodeStack.push(root);
        TreeNode* node = nullptr;

        while(!nodeStack.empty()){
            node = nodeStack.top();
            nodeStack.pop();

            if(node != nullptr){
                if(node->right)  nodeStack.push(node->right);
                nodeStack.push(node);
                nodeStack.push(nullptr);
                if(node->left)  nodeStack.push(node->left);
            }
            else{
                node = nodeStack.top();
                nodeStack.pop();
                ans.push_back(node->val);
            }
        }
        return ans;
    }
};

// Morris 中序遍历
// 时间复杂度：O(n)
// 空间复杂度：O(1)

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        TreeNode *predecessor = nullptr;
        TreeNode* node = root;

        while (node != nullptr) {
            if (node->left != nullptr) {
                // predecessor 节点就是当前 node 节点向左走一步，然后一直向右走至无法走为止
                predecessor = node->left;
                while (predecessor->right != nullptr && predecessor->right != node) {
                    predecessor = predecessor->right;
                }
                
                // 让 predecessor 的右指针指向 node，继续遍历左子树
                if (predecessor->right == nullptr) {
                    predecessor->right = node;
                    node = node->left;
                }
                // 说明左子树已经访问完了，我们需要断开链接
                else {
                    res.push_back(node->val);
                    predecessor->right = nullptr;
                    node = node->right;
                }
            }
            // 如果没有左孩子，则直接访问右孩子
            else {
                res.push_back(node->val);
                node = node->right;
            }
        }
        return res;
    }
};