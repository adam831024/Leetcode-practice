/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 void fun(int *arr, int arrLen, int target, int* ret, int start, int end)
 {
     if(arr[start] + arr[end] == target)
     {
         ret[0] = start+1;
         ret[1] = end+1;
     }
     else if(arr[start] + arr[end] > target)
     {
         fun(arr, arrLen, target, ret, start, end-1);
     }
     else
     {
         fun(arr, arrLen, target, ret, start+1, end);
     }
 }
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize){
    int *ret = malloc(sizeof(int) * 2);
    *returnSize = 2;
    fun(numbers, numbersSize, target, ret, 0, numbersSize-1);
    return ret;
}