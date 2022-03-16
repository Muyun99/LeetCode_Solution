// 一刷：2022 03 16 两种方案都不会做，

// 自顶向下的递归
// 时间复杂度：O(n^2)
// 空间复杂度：O(n)
class Solution {
public:
    int height(TreeNode* root){
        if(root == nullptr)
            return 0;
        return max(height(root->left), height(root->right)) + 1;
    }
    bool isBalanced(TreeNode* root) {
        if(root == nullptr)
            return true;

        if(abs(height(root->left) - height(root->right)) <= 1)
            return isBalanced(root->left) && isBalanced(root->right);
        else
            return false;
    }  
};


// 自底向上的递归
// 时间复杂度：O(n)
// 空间复杂度：O(n)
class Solution {
public:
    int height(TreeNode* root){
        if(root == nullptr)
            return 0;
            
        int leftheight = height(root->left);
        int rightheight = height(root->right);
        
        if(abs(leftheight - rightheight) > 1 || leftheight == -1 || rightheight == -1)
            return -1;
        else
            return max(leftheight, rightheight) + 1;
        
    }
    bool isBalanced(TreeNode* root) {
        return height(root) != -1;
    }
};