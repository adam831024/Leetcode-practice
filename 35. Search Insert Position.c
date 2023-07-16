int searchInsert(int* nums, int numsSize, int target){
    if(nums[0] >= target)
        return 0;
    for(int i = 0 ; i < numsSize-1; i++)
    {
        if((target-nums[i])>0 && (target-nums[i+1])<=0)
            return i+1;
    }
    return numsSize;
}