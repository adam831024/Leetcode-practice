/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2){
    struct ListNode* ret = NULL;
    struct ListNode* ret_move = NULL;
    ret_move = ret = (struct ListNode*)malloc(sizeof(struct ListNode));
    ret_move->val = 0;
    ret_move->next = NULL;
    if(!list2 && !list1)
        return list1;
    while(list1 || list2)
    {
        int addVal = 0;
        if(list1 && list2)
        {
            if(list1->val <= list2->val)
            {
                addVal = list1->val;
                list1 = list1->next;
            }
            else
            {
                addVal = list2->val;
                list2 = list2->next;
            }
        }
        else if(list1)
        {
            addVal = list1->val;
            list1 = list1->next;
        }
        else if(list2)
        {
            addVal = list2->val;
            list2 = list2->next;
        }

        ret_move->val = addVal;

        if(!list2 && !list1)
            break;
        ret_move->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        ret_move = ret_move->next;
        ret_move->next = NULL;
        ret_move->val = 0;
    }
    
    return ret;
}