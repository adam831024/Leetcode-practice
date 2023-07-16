/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void reorderList(struct ListNode* head){
    struct ListNode** tbl = (struct ListNode**)malloc(sizeof(struct ListNode*)*50000);
    struct ListNode* tmp_head = head;
    int head_size = 0;
    while(tmp_head)
    {
        tbl[head_size++] = tmp_head;
        tmp_head = tmp_head->next;
    }
    for(int i = 0 ; i < head_size/2;i++)
    {
        tbl[i]->next = tbl[head_size-1-i];
        tbl[head_size-1-i]->next = tbl[i+1];
        if(i == (head_size/2-1))
        {
            if(head_size%2 == 0)
            {
                tbl[head_size-1-i]->next = NULL;
            }
            else
            {
                tbl[head_size/2]->next = NULL;
            }
        }
        // printf("tbl[%d]->val = %d\n", i,tbl[i]->val);
    }
    
        
    free(tbl);
}