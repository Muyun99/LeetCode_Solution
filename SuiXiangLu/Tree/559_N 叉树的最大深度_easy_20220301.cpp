/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int maxDepth(Node* root) {
        int depth = 0;
        if(root == nullptr) return depth;
        queue<Node*> q;
        q.push(root);

        Node* node = nullptr;

        while(!q.empty()){
            int size = q.size();
            for(int i = 0; i < size; ++i){
                node = q.front();
                q.pop();
                
                for(int j = 0;j < node->children.size(); ++j){
                    q.push(node->children[j]);
                }
            }
            ++depth;
        }
        return depth;
    }
};