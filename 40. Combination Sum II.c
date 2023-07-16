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
void fun(int* candidates, int candidatesSize, int target, int index, int* tBuf, int currentLength, int* returnSize, int** returnColumnSizes, int*** ret) {
    /* Track the previous candidate to avoid duplicate solutions*/
    int prevCan = 0;
    
    /* Loop through all possible candidates to add to the solution */
    for (int i = index; i < candidatesSize; i++) 
    {
        
        /* If the candidate matches the target, add to the answer */
        if (candidates[i] == target) 
        {
            (*returnSize)++;
            
            /* Allocate memory for new answer */
            *ret = (int**)realloc(*ret, (*returnSize) * sizeof(int*));
            (*ret)[(*returnSize) - 1] = (int*)malloc((currentLength+1) * sizeof(int));
            
            /* Copy data into new answer */
            memcpy((*ret)[(*returnSize) - 1], tBuf, currentLength * sizeof(int));
            (*ret)[(*returnSize) - 1][currentLength] = candidates[i];
            
            /* Update the returnColumnSizes array */
            (*returnColumnSizes) = (int*)realloc((*returnColumnSizes), (*returnSize) * sizeof(int));
            (*returnColumnSizes)[(*returnSize) - 1] = currentLength + 1;
            
            /* Break to avoid duplicate answers */
            /* Since the candidates are sorted, any next candidates will be too large */
            break;
        }
        else if (candidates[i] <= (target / 2) && candidates[i] != prevCan) 
        {
            tBuf[currentLength] = candidates[i];
            fun(candidates, candidatesSize, target - candidates[i], i + 1, tBuf, currentLength + 1, returnSize, returnColumnSizes, ret);
            prevCan = candidates[i];
        }
        else if (candidates[i] > target) 
            break;
    }
}

int** combinationSum2(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes){
    
    bubble_sort(candidates, candidatesSize);
    
    int* tBuf = (int*)malloc(100*sizeof(int));
    int** ret = (int**)malloc(sizeof(int*));
    (*returnColumnSizes) = (int*)malloc(sizeof(int));
    (*returnSize) = 0;
    
    fun(candidates, candidatesSize, target, 0, tBuf, 0, returnSize, returnColumnSizes, &ret);
    
    free(tBuf);
    return ret;
}