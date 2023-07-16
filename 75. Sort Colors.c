void sortColors(int* nums, int numsSize){
    int tmp = 0;

    for(int i = 0 ; i < numsSize; i++)
    {
        for(int j = i+1 ; j < numsSize; j++)
        {
            if(nums[i] > nums[j])
            {
                tmp = nums[j]; 
                nums[j] = nums[i];
                nums[i] =tmp;
            }
        }
    }
}