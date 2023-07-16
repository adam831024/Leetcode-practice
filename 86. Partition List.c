/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* partition(struct ListNode* head, int x){
    if(!head)
        return NULL;
    struct ListNode* tmp_head = head;
    int fifo[200] = {0};
    int fifo_count = 0;
    while(tmp_head)
    {
        if(tmp_head->val < x)
            fifo[fifo_count++] = tmp_head->val;
        tmp_head = tmp_head->next;
    }
    tmp_head = head;
    while(tmp_head)
    {
        if(tmp_head->val >= x)
            fifo[fifo_count++] = tmp_head->val;
        tmp_head = tmp_head->next;
    }
    tmp_head = head;
    printf("fifo = ");
    for(int i = 0; i < 200;i++)
    {
        if(fifo[i])
            printf("%d ", fifo[i]);
    }
    printf("\n");
    for(int i = 0 ;i < fifo_count; i++)
    {
        tmp_head->val = fifo[i];
        tmp_head = tmp_head->next;
    }
    return head;
}