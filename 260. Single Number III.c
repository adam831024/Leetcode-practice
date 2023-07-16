/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* singleNumber(int* nums, int numsSize, int* returnSize){
    if(numsSize == 2)
        return nums;
    int *ret = (int*)malloc(sizeof(int) * 2);
    memset( ret, 0, sizeof (int) * 2 );
    *returnSize = 2;
    long int xor = 0;
    for (int i = 0; i < numsSize; i ++)
    {
        xor ^= nums[i];
    }
    // printf("xor = %d\n", xor);
    int lowBit = xor & (~xor + 1);
    // printf("lowBit = %d", lowBit);
    for (int i = 0; i < numsSize; i ++)
    {
        if(nums[i] & lowBit)
        {
            ret[0] ^= nums[i];
        }
        else
        {
            ret[1] ^= nums[i];
        }
    }
    return ret;
}