// TIme complexity :- O(n)
// Space complexity :- O(1)
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
    void buildNo(TreeNode* root, int num, int &sum)
    {
        if(root == NULL)    return;
        num = num*10 + root->val;
        
        if(root->left == NULL && root->right == NULL)
        {
            sum += num;
            return;
        }
        
        buildNo(root->left, num, sum);
        buildNo(root->right, num, sum);
    }
    int sumNumbers(TreeNode* root) {
        if(root == NULL)    return 0;
        int sum = 0;
        int num = 0;
        buildNo(root, num, sum);
        return sum;
    }
};