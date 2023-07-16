void swap(int* a, int* b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
void qucik_sort(int* arr, int left, int right)
{
    if(left < right)
    {
        int i = left-1; 
        int j = right+1;
        int s = arr[(left+right)/2];
        while(1)
        {
            while(arr[++i] < s);
            while(arr[--j] > s);
            if(i>=j)
                break;
            swap(&arr[i], &arr[j]);
        }
        qucik_sort(arr, left, i-1);
        qucik_sort(arr, j+1, right);
    }
}
int majorityElement(int* nums, int numsSize){
    qucik_sort(nums, 0, numsSize-1);
    return nums[numsSize/2];
}