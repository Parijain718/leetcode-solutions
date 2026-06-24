class Solution {
public:
    vector<int> ans;
    void dfs(Node* root){
        if(!root) return;
        ans.push_back(root->val);
        for(Node* child : root->children){
            dfs(child);
        }
    }
    vector<int> preorder(Node* root) {
        dfs(root);
        return ans;
    }
};