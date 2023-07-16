 int calculate(int* arr, int arrLen)
 {
     int ret = 0;
     for(int i =0; i < arrLen; i++)
     {
         ret +=arr[i];
     }
        return ret;
 }
 
 void sort(int *arr, int arrLen)
 {
     int tmp = 0;
     for(int i = 0 ; i < arrLen-1;i++)
     {
         for(int j = 0 ; j < arrLen-i-1;j++)
         {
             if(arr[j] > arr[j+1])
             {
                 tmp = arr[j+1];
                 arr[j+1] = arr[j];
                 arr[j] = tmp;
             }
         }
     }
 }
 void func(int* tBuf, int index, int* arr, int arrLen, uint8_t end, int target,int** ret, int *count, int** returnColumnSizes, int start)
 {
    if(index == end)
    {
    //   printf("tBuf = "); 
    //     for(int i = 0 ; i < index ;i++)
    //     {
    //         printf("%d ", tBuf[i]);
    //     }
    //     printf(", sum = %d ", calculate(tBuf, index));
    //     printf("\n");
        if(target == calculate(tBuf, index))
        {
            (*returnColumnSizes)[(*count)] = index;
            ret[(*count)] = (int*)malloc(sizeof(int) * index);
            memcpy(ret[(*count)], tBuf, sizeof(int) * index);
            (*count)++;
        }
    }
    else
    {
        int i = 0;
        for( i = start ; i < arrLen; i++)
        {
            tBuf[index] = arr[i];
            if(calculate(tBuf, index) <= target)
                func(tBuf, index+1, arr, arrLen, end,  target, ret, count, returnColumnSizes, i);
            else
                break;
        }
    }
 }
int** combinationSum(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes)
{
    // printf("candidatesSize = %d\n", candidatesSize);
    sort(candidates, candidatesSize);
    uint8_t max_loop = 0;
    int **ret = NULL;
    for(int i = 0 ; i < candidatesSize;i++)
    {
        if(candidates[i] > target)
        {
            candidatesSize = i;
            break;
        }
    }
    *returnSize = 0;
    *returnColumnSizes = (int*) malloc(200 * sizeof(int));

    max_loop = target/candidates[0];
    if(target%candidates[0])
        max_loop++;
    // printf("max_loop = %d\n", max_loop);

    ret = (int**)malloc(sizeof(int*) * 200);
    int *tBuf = (int*)malloc(sizeof(int) * max_loop);

    for(uint8_t i = max_loop; i > 0; i-- )
    {
        // printf("i = %d\n", i);
        func(tBuf, 0, candidates, candidatesSize, i,  target, ret, returnSize, returnColumnSizes, 0);
    }

    free(tBuf);
    // printf("returnSize = %d\n", (*returnSize));
    return ret;
}