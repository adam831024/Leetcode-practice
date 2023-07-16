/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* insertionSortList(struct ListNode* head){
    struct ListNode* tmp_head = head;
    int swap = 0;
    int count = -1;
    while(tmp_head && tmp_head->next)
    {
        if(tmp_head->val > tmp_head->next->val)
        {
            swap = tmp_head->val;
            tmp_head->val = tmp_head->next->val;
            tmp_head->next->val = swap;
        }
        tmp_head = tmp_head->next;
        count++;
    }
    printf("count = %d", count);
    
    for(int i = 0; i < count ; i++)
    {
        tmp_head = head;
        for(int j = 0 ;j < count;j++)
        {
            if(tmp_head->val > tmp_head->next->val)
            {
                swap = tmp_head->val;
                tmp_head->val = tmp_head->next->val;
                tmp_head->next->val = swap;
            }
            tmp_head = tmp_head->next;
        }
    }
    return head;
}