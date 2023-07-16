int singleNumber(int* nums, int numsSize){
    int ret = 0;
    for(uint8_t i = 0; i < 32; i++)
    {
        int count = 0;
        for(int j = 0 ; j < numsSize; j++)
        {
            if((nums[j]>>i) & 1 )
            {
                count++;
            }
        }
        if(count % 3)
            ret |= (1u<<i);
    }
    return ret;
}