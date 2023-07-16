int removeElement(int* nums, int numsSize, int val)
{
    int tmp = 0;
    int delete = 0;
    for(int i = 0; i < numsSize; i++)
    {
        if(nums[i] == val)
        {
            nums[i] = 0xFF;
            delete++;
        }
    }
    //sort
    for(int i = 0; i < numsSize; i++)
    {
        for(int j = (i+1) ;j < numsSize; j++)
        {
            if(nums[i] > nums[j])
            {
                tmp = nums[i]; 
                nums[i] = nums[j];
                nums[j] = tmp;
            }

        }
    }
    for(int i = 0; i < numsSize;i++)
    {
        if(nums[i] == 0xFF)
            nums[i] = 0;
        printf("nums[%d] = %d\n", i, nums[i]);
    }
    return (numsSize-delete);
}