/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
    while(head)
    {
        if(head >= head->next && head->next != NULL)
            return true;
        head = head->next;        
    }

    // for(int i = 0; i < 4;i++)
    // {
    //     if(head->next)
    //     {
    //         printf("head = 0x%x, next = 0x%x\n", head, head->next);
    //         head = head->next;
    //     }

    // }
    return false;
}