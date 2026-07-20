class Solution {
public:
    unordered_map<long long, int> prefix;
    int ans = 0;
    void dfs(TreeNode* root, long long currSum, int target){
        if(root == NULL){
            return;
        }
        currSum += root->val;
        if(prefix.count(currSum - target))
            ans += prefix[currSum - target];
        prefix[currSum]++;
        dfs(root->left, currSum, target);
        dfs(root->right, currSum, target);
        prefix[currSum]--;
    }
    int pathSum(TreeNode* root, int targetSum) {
        prefix[0] = 1;
        dfs(root,0,targetSum);
        return ans;
    }
};