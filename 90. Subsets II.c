/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
 void bubble_sort(int *arr, int arrLen)
{
    int tmp = 0;
    for(int i = 0; i < arrLen-1; i++)
    {
        for(int j = 0; j <arrLen-i-1; j++)
        {
            if(arr[j]>arr[j+1])
            {
                tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
            }
        }
    }
}
int check_duplicate(int** ret, int returnSize, int* returnColumnSizes, int* arr, int arrLen)
{
    for(int i = 0 ; i < returnSize ; i++)
    {
        if(returnColumnSizes[i] == arrLen)
        {
            if( 0 == memcmp(ret[i], arr, arrLen*sizeof(int)) )
                return 1;
        }
    }
    return 0;
}

void fun(int *arr, int arrLen, int **ret, int* returnSize, int* returnColumnSizes, int index, int targetSize, int *tBuf, 
int index2)
{
    if(index == targetSize)
    {
        if(0 == check_duplicate(ret, *returnSize, returnColumnSizes, tBuf, targetSize))
        {
            ret[(*returnSize)] = (int*)malloc(sizeof(int) *(targetSize));
            memcpy(ret[(*returnSize)], tBuf, sizeof(int) * (targetSize));
            returnColumnSizes[(*returnSize)] = targetSize;
            (*returnSize)++;
        }
    }
    else
    {
        for(int i = index2 ; i < arrLen; i++)
        {
            tBuf[index] = arr[i];
            fun(arr, arrLen, ret, returnSize, returnColumnSizes, index+1, targetSize, tBuf, i+1);
        }
    }
}
int** subsetsWithDup(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    int tBuf[numsSize];
    int **ret = (int**)malloc(sizeof(int*) * 2000);
    (*returnColumnSizes) = (int*)malloc(sizeof(int) * 2000);
    (*returnColumnSizes)[0] = 0;
    *returnSize = 1;
    bubble_sort(nums, numsSize);
    for(int i = 1; i <= numsSize ; i++)
    {
        fun(nums, numsSize, ret, returnSize, *returnColumnSizes, 0,  i, tBuf, 0);
    }
    return ret;
}