int search(int* nums, int numsSize, int target){
    int ret = -1;
    for(int i = 0 ; i < numsSize;i++)
    {
        if(nums[i] == target)
            ret = (ret+i+1);
    }
    return ret;
}