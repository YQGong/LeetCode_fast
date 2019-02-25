//不太熟悉vector<vector<int>>的初始化。卡壳了很久。

static int turbo = [](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return 0;
}();

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> r;
        int level=0;
        levelOrderBottom(level,r,root);
        reverse(r.begin(),r.end());
        return r;
    }
    
    int levelOrderBottom(int level,vector<vector<int>>& r,TreeNode* root){
        if(root==NULL) return 1; 
        if(r.size()<level+1) {
            vector<int> newvector;
            r.push_back(newvector);
            r[level].push_back(root->val);
        }else{
            r[level].push_back(root->val);
        }
        if(root->left!=NULL) levelOrderBottom(level+1,r,root->left);
        if(root->right!=NULL) levelOrderBottom(level+1,r,root->right);
        return 0;
    }
};
