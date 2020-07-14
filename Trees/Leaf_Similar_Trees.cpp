/*
Consider all the leaves of a binary tree.  From left to right order, the values of those leaves form a leaf value sequence.

For example, in the given tree above, the leaf value sequence is (6, 7, 4, 9, 8).

Two binary trees are considered leaf-similar if their leaf value sequence is the same.

Return true if and only if the two given trees with head nodes root1 and root2 are leaf-similar.

Constraints:

Both of the given trees will have between 1 and 200 nodes.
Both of the given trees will have values between 0 and 200
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    vector<int> solve(TreeNode* root)
    {
        vector<int> ans;
        if(root == NULL)
        {
            return ans;
        }
        
        vector<int> left = solve(root->left);
        vector<int> right = solve(root->right);
        
        for(int i=0;i<left.size();i++)
        {
            ans.push_back(left[i]);
        }
        if(root->left == NULL && root->right == NULL)
        {
            ans.push_back(root->val);
        }
        for(int i=0;i<right.size();i++)
        {
            ans.push_back(right[i]);
        }
        return ans;
    }
    
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> left = solve(root1);
        vector<int> right = solve(root2);
        
        if(left.size() != right.size())
        {
            return false;
        }
        
        for(int i=0;i<left.size();i++)
        {
            if(left[i] != right[i])
            {
                return false;
            }
        }
        return true;
    }
};
