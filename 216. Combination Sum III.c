/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int sum_array(int *arr, int arrLen)
{
   int sum = 0;
   for(int i = 0 ; i < arrLen;i++)
   {
      sum +=arr[i];  
   }
   return sum;
}
 void fun(int **ret, int target, int max_index, int index, int *returnSize, int* returnColumnSizes, int index2, int *tBuf)
 {
    if(index == max_index)
    {
   if(target == sum_array(tBuf, index))
   {
      ret[(*returnSize)] = (int*)malloc(sizeof(int) * index);
      memcpy(ret[(*returnSize)], tBuf, sizeof(int)*index);
      returnColumnSizes[(*returnSize)] = index;
      (*returnSize)++;
   }
    }
    else
    {
        for(int i = index2; i <= 9 ; i++)
        {
            tBuf[index] = i;
            fun(ret, target, max_index, index+1, returnSize, returnColumnSizes, i+1, tBuf);
        }
    }
 }
int** combinationSum3(int k, int n, int* returnSize, int** returnColumnSizes){
    int tBuf[k];
    int **ret = NULL;
    *returnSize = 0;
    ret = (int**)malloc(sizeof(int*) * 100);
    *returnColumnSizes = (int*)malloc(sizeof(int) * 100);
    fun(ret, n, k, 0, returnSize, *returnColumnSizes, 1, tBuf);
    return ret;
}