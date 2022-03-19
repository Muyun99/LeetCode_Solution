// 一刷：2022 03 18 会做


// 定义一个 flag 变量，每一次反向
// 时间复杂度：O(N)
// 空间复杂度：O(N)
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == nullptr)
            return ans;
        
        queue<TreeNode* > q;
        q.push(root);
        
        TreeNode* node = nullptr;
        int flag = 0;
        while(!q.empty()){
            int size = q.size();
            vector<int> vec(size);

            if(flag == 0){
                for(int i = 0; i < size; ++i){
                    node = q.front();
                    q.pop();
                    vec[i] = node->val;
                    if(node->left)   q.push(node->left);
                    if(node->right) q.push(node->right);
                }
                flag = 1;
            }
            else{
                for(int i = size - 1; i >= 0; --i){
                    node = q.front();
                    q.pop();
                    vec[i] = node->val;
                    if(node->left)   q.push(node->left);
                    if(node->right) q.push(node->right);
                }
                flag = 0;
            }
            ans.push_back(vec);
        }
        return ans;
    }
};

// 双端队列
// 时间复杂度：O(N)
// 空间复杂度：O(N)
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == nullptr)
            return ans;
        
        queue<TreeNode* > q;
        q.push(root);
        
        TreeNode* node = nullptr;
        bool flag = true;
        while(!q.empty()){
            int size = q.size();
            deque<int> levelList;
            for(int i = 0; i < size; ++i){
                node = q.front();
                q.pop();

                if(flag)
                    levelList.push_back(node->val);
                else
                    levelList.push_front(node->val);

                if(node->left)  q.push(node->left);
                if(node->right)  q.push(node->right);
            }
            flag = !flag;
            ans.push_back(vector<int>{levelList.begin(), levelList.end()});
        }
        return ans;
    }
};