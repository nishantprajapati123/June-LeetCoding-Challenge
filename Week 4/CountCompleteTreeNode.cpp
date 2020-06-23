// Time complexity :- O(log(n))
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
    int countNodes(TreeNode* root) {
        
        if(root == NULL)    return 0;
        TreeNode *left_ptr = root, *right_ptr = root;
        int left_h = 0, right_h = 0;
        
        while(left_ptr)
        {
            left_h++;
            left_ptr = left_ptr->left;
        }
        
        while(right_ptr)
        {
            right_h++;
            right_ptr = right_ptr->right;
        }
        
        if(left_h == right_h)   return (1<<left_h)-1;
        
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};