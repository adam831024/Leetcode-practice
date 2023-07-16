/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    struct ListNode* tmp = head;
    uint8_t count = 0;
    uint8_t count_now = 0;
    while(tmp)
    {
        count++;
        tmp = tmp->next;
    }
    tmp = head;
    printf("count = %d\n", count);
    if(count-n <= 0)
        return tmp->next;
    while(tmp)
    {
        
        if(count_now == (count-n-1))
        {
            printf("val = %d", tmp->val);
            if(tmp->next->next)
                tmp->next = tmp->next->next;
            else
                tmp->next = NULL;
        }
        count_now++;
        tmp = tmp->next;
    }
    return head;
}