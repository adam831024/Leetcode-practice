/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
 void func(int *arr, int arrLen, int *returnSize, int** returnColumnSizes, int targetSize, int index, int** ret, int* tBuf, int index2)
 {
     if(index == targetSize)
     {
         (*returnColumnSizes)[(*returnSize)] = targetSize;
         ret[(*returnSize)] = (int*)malloc(sizeof(int) * targetSize);
         memcpy(ret[(*returnSize)], tBuf, sizeof(int)*targetSize);
         (*returnSize) = (*returnSize) +1;

        // printf("tBuf = ");
        //  for(int i = 0 ; i < targetSize;i++)
        //  {
        //      printf("%d ", tBuf[i]);
        //  }
        //  printf("\n");
     }
     else
     {
         for(int i = index2; i < arrLen; i++)
         {
             tBuf[index] = arr[i];
             func(arr, arrLen, returnSize, returnColumnSizes,  targetSize, index+1, ret, tBuf, i+1);
         }
     }
 }
int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    
    int **ret = (int**)malloc(sizeof(int*) * 2000);
    (*returnColumnSizes) = (int*)malloc(sizeof(int) * 2000);
    int *tBuf = (int*)malloc(sizeof(int) * numsSize);
    *returnSize = 0;
    for(int i = 0; i <= numsSize ; i++)
        func(nums, numsSize, returnSize, returnColumnSizes,  i,0,  ret, tBuf, 0);

    free(tBuf);
    return ret;
}