// Time complexity :- O(n)
// Space complexity :- O(1)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        
        while(node->next->next != NULL)
        {
            node->val = node->next->val;
            node = node->next;
        }
        node->val = node->next->val;
        delete node->next->next;
        node->next = NULL;
    }
};