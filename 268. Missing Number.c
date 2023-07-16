void sort(int* arr, int arrLen)
{
    int tmp = 0;
    for(int i = 0 ; i <arrLen-1 ; i++)
    {
        for(int j = 0 ; j <arrLen-i-1 ; j++)
        {
            if(arr[j] > arr[j+1])
            {
                tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
            }
        }
    }
}
int missingNumber(int* nums, int numsSize){
    // sort(nums, numsSize);
    // for(int i = 0 ; i < numsSize; i++)
    // {
    //     if(nums[i] != i)
    //     {
    //         return i;
    //     }   
    // }
    // return numsSize;
       int n=numsSize;
   int sum=0;
   for(int i=0;i<numsSize;i++)
   {
       sum=sum+nums[i];
   }
   int res=(n*(n+1)/2)-sum ;
   return res;
}