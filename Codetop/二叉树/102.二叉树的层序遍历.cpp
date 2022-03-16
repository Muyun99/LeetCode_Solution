// 一刷：2022 03 16 会做广度遍历，

// 时间复杂度：O(n)
// 空间复杂度：O(n)
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == nullptr)
            return ans;
        
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* node = nullptr;
        
        while(!q.empty()){
            int size = q.size();
            vector<int> num(size);
            
            for(int i = 0; i < size; ++i){
                node = q.front();
                q.pop();
                
                if(node->left != nullptr)   q.push(node->left);
                if(node->right != nullptr)  q.push(node->right);
                num[i] = node->val;
            }
            ans.push_back(num);
        }
        return ans;
    }
};