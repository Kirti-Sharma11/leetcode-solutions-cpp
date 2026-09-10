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

    int sum(TreeNode* root)
    {
        if(root == NULL)
            return 0;

        return root->val + sum(root->left) + sum(root->right);
    }

    int count(TreeNode* root)
    {
        if(root == NULL)
            return 0;

        return 1 + count(root->left) + count(root->right);
    }

    int averageOfSubtree(TreeNode* root)
    {
        if(root == NULL)
            return 0;

        int ans = 0;

        if(sum(root) / count(root) == root->val)
            ans++;

        ans += averageOfSubtree(root->left);
        ans += averageOfSubtree(root->right);

        return ans;
    }
};