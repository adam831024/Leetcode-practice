/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

 void swap(int* a, int* b) 
 {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void func(int index, int* array, int arrLen, int* tBuf, int** ret, int* count, int** returnColumnSizes)
{
    if(index == (arrLen-1))
    {
        ret[(*count)] = (int*)malloc(sizeof(int) * arrLen);
        (*returnColumnSizes)[(*count)] = arrLen;
        memcpy(ret[*count], array, sizeof(int) * arrLen);
        // printf("ret[%d] = ", *count);
        // for(int i =0;i < arrLen; i++)
        // {
        //     printf("%d ", ret[*count][i]);
        // }
        // printf("\n");
        (*count) = (*count) + 1;
    }
    else
    {
        for(int i = index ; i < (arrLen); i++)
        {
            swap(&array[index], &array[i]);
            func(index+1, array, arrLen, tBuf, ret, count, returnColumnSizes);
            swap(&array[index], &array[i]);
        }
    }
}
int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    int **ret = NULL;
    int tBuf[numsSize];
    int possibility = 1;
    *returnSize = 0;
    for (int i = 1; i <= numsSize; i++)
        possibility *= i;
    printf("possibility = %d\n",possibility);
    ret = (int**)malloc(sizeof(int*) * (possibility));
    (*returnColumnSizes) = (int*)malloc(sizeof(int)* possibility);
    func(0, nums, numsSize, tBuf, ret, returnSize, returnColumnSizes);
    return ret;
}