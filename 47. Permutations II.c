/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
 void switchVal(int* a, int *b)
 {
     int tmp = 0;
     tmp = *a;
     *a = *b;
     *b = tmp;
 }

 void func(int** ret, int** returnColumnSizes, int index, int* arr, int arrSize, int* returnSize)
 {
     if(index == arrSize)
     {
         uint8_t ok = 1;
        //  printf("arr = ");
        //  for(int i = 0 ;i < arrSize; i++)
        //  {
        //      printf("%d ", arr[i]);
        //  }
        //  printf("\n");
         for(int i = 0 ; i < (*returnSize) ; i++)
         {
             if(!memcmp(arr, ret[i], arrSize*sizeof(int)))
             {
                 ok = 0;
                 break;
             }
         }
        // printf("(*returnSize) = %d\n", (*returnSize));
         if(ok)
         {
             ret[(*returnSize)] = (int*)malloc(sizeof(int) * arrSize);
             (*returnColumnSizes)[(*returnSize)] = arrSize;
             memcpy(ret[(*returnSize)], arr, arrSize*sizeof(int));
             (*returnSize) = (*returnSize)+1;
         }
     }
     else
     {
         for(int i = index ; i < arrSize; i++)
         {
             switchVal(&arr[index], &arr[i]);
             func(ret, returnColumnSizes, index+1, arr, arrSize, returnSize);
             switchVal(&arr[index], &arr[i]);
         }
     }
 }
int** permuteUnique(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    int possible = 1;
    int **ret = NULL;
    (*returnSize) = 0;
    for(int i = numsSize; i > 0; i--)
        possible *= i;

    printf("possible = %d\n", possible);
    ret = (int**)malloc(sizeof(int*) * possible);
    (*returnColumnSizes) = (int*)malloc(sizeof(int) * possible);
    func(ret, returnColumnSizes, 0, nums, numsSize, returnSize);

    return ret;
}