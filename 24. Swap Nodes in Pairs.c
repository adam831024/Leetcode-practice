/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapPairs(struct ListNode* head){
  struct ListNode* pNext = head;
  struct ListNode* pLast = NULL;
  int count = 0;
  int tmpVal = 0;
  while(pNext)
  {
    if(count%2)
    {
      tmpVal = pLast->val;
      pLast->val = pNext->val;
      pNext->val = tmpVal;
      printf("pLast->val = %d, pNext->val = %d,  count = %d\n", pLast->val, pNext->val, count);
    }
    pLast = pNext;
    pNext = pNext->next; 
    // printf("pLast->val = %d,   count = %d\n", pLast->val,  count);

    count++;
  }
  return head;
}