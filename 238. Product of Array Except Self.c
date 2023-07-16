/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int productWithout(int *arr, int arrLen, int without)
{
    int value = 1;
    for(int i = 0; i < arrLen;i++)
    {
        if(i == without)
            continue;
        value *= arr[i];
    }
    return value;
}
int* productExceptSelf(int* nums, int numsSize, int* returnSize){
    int *ret = malloc(sizeof(int) * numsSize); 
    *returnSize = numsSize;
    int tVal = 1;
    for(int i = 0; i < numsSize;i++)
    {
        tVal *= nums[i];
    }
    for(int i = 0; i < numsSize;i++)
    {
        if(nums[i] == 0)
        {
            ret[i] = productWithout(nums, numsSize, i);
        }
        else
        {
            ret[i] = tVal/nums[i];
        }
    }
    return ret;
}