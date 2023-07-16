#if 0 //time limit exceeded
void fun(int *arr, int arrLen, int position, bool* ret)
{
    if(*ret == false)
    {
        if(position >= (arrLen-1))
            *ret = true;
        else
        {
            for(int i = 1; i <= arr[position]; i++)
            {
                fun(arr, arrLen, position + i, ret);
            }
        }
    }
}
bool canJump(int* nums, int numsSize){
    bool ret = false;
    fun(nums, numsSize, 0, &ret);
    return ret;
}
#else
bool canJump(int* nums, int numsSize){
    int position = 0;
    for(int i = 0 ; i <= position;i++)
    {
        position = position > nums[i]+i ? position : nums[i]+i;
        printf("position = %d\n", position);
        if(position >= (numsSize-1))
            return true;
    }
    return false;
}
#endif