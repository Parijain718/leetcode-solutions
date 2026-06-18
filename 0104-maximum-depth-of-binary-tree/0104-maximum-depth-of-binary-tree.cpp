class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        int rightHeight = maxDepth(root->right);
        int leftHeight = maxDepth(root->left);
        int ans = max(rightHeight,leftHeight);
        return 1 + ans;
    }
};