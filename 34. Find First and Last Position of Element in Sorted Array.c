/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* searchRange(int* nums, int numsSize, int target, int* returnSize){
    printf("numsSize = %d\n", numsSize);
    int* ret = (int*)malloc(sizeof(int)*2);
    int first = -1;
    int last = -1;
    ret[0] = -1;
    ret[1] = -1;
    *returnSize = 2;
    for(int i = 0; i < numsSize;i++)
    {
        if(nums[i] == target)
        {
            if(first == -1)
            {
                first = i;
                last = first;
            }
            else
            {
                last = i;
            }
        }
    }

    if((first>=0) && (last>=0))
    {
        ret[0] = first;
        ret[1] = last;
    }
    return ret;
}