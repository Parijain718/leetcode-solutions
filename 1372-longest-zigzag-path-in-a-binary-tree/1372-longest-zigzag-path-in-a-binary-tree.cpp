class Solution {
public:
    int ans = 0;
    void dfs(TreeNode* node, bool left, int length){
        if(node == NULL)
            return;
        ans = max(ans,length);
        if(left){
            dfs(node->right,false,length+1);
            dfs(node->left,true,1);
        }
        else{
            dfs(node->left,true,length+1);
            dfs(node->right,false,1);
        }
    }
    int longestZigZag(TreeNode* root) {
        dfs(root,true,0);
        dfs(root,false,0);
        return ans;
    }
};