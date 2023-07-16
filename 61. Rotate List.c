/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 void sort(int *arr ,int arrLen)
 {
     int tmp = arr[arrLen-1];
     for(int i = arrLen-1 ; i > 0   ; i--)
     {
         arr[i] = arr[i-1];
     }
     arr[0] = tmp;

 }
struct ListNode* rotateRight(struct ListNode* head, int k){
    int* tBuf = NULL;
    int length = 0;
    struct ListNode* ptr = head;
    struct ListNode* ret = head;
    if(!head)
        return head;
    while(head)
    {
        length++;
        tBuf = realloc(tBuf, length * sizeof(int));
        tBuf[length-1] = head->val;
        head = head->next;
    }
    // sort(tBuf, length);

    for(int i = 0 ; i < (k%length); i++)
    {
        sort(tBuf, length);
    }

    // printf("tBuf = ");
    // for(int i = 0 ; i < length ; i++)
    // {
    //    printf("%d ", tBuf[i]); 
    // }
    // printf("\n");

    for(int i = 0 ; i < length ; i++)
    {
        ptr->val = tBuf[i];
        ptr = ptr->next;
    }
    free(tBuf);
    return ret;
}