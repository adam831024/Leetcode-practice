/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head){
    struct ListNode* tmp_head = head;
    while(tmp_head && tmp_head->next)
    {
        if(tmp_head->next)
        {
            if(tmp_head->val == tmp_head->next->val)
            {
                tmp_head->next = tmp_head->next->next;
            }
            else
            {
                tmp_head = tmp_head->next;
            }
        }
        // tmp_head = tmp_head->next;
    }
    return head;
}