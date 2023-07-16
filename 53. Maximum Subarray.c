
int maxSubArray(int* nums, int numsSize){
    int ret = nums[0];
    int max = 0;
    for(int i = 0 ; i < numsSize; i++)
    {
        max = nums[i]>nums[i]+max?nums[i]:nums[i]+max;
        ret = ret > max?ret:max;
    }
    return ret;
}