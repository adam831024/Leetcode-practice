
int minSubArrayLen(int target, int* nums, int numsSize)
{
   int index = 0;
   int ret = 0x0FFFFFFF;
   int sum = 0;
   for (int i = 0; i < numsSize; i ++)
   {
      sum += nums[i];
      while (sum >= target)
      {
         //found it
         printf("ret = %d, i = %d, index = %d\n", ret, i , index);
            ret = ret < i - index + 1 ? ret : i - index + 1;

         // try to shrink the window from left pointer
         sum -= nums[index ++];
      }
   }
   return ret == 0x0FFFFFFF ? 0: ret;
}