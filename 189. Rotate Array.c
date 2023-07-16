void rotate(int* nums, int numsSize, int k){
    if(1 == numsSize)
        return ;
    k = k %numsSize;
    int *tmp = (int*)malloc(sizeof(int) * k);
    memcpy(tmp, &nums[numsSize-k], sizeof(int) * k);
    // memcpy(&nums[k-1], &nums[0], sizeof(int)*(numsSize-k));
    for(int i = 0 ; i < (numsSize-k);i++)
    {
        nums[numsSize-i-1] = nums[numsSize-1-k-i];
    }
    memcpy(nums, tmp, sizeof(int)*k);
    free(tmp);
}