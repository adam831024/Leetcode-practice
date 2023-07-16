// int findKthLargest(int* nums, int numsSize, int k){
//   int tmp = 0;
//   int* ptr = NULL;
//   for(int i = 0; i < k ; i++)
//   {
//     tmp = nums[i];
//     ptr = NULL;
//     for(int l = i+1; l < numsSize; l++)
//     {
//       if(tmp<nums[l])
//       {
//         tmp = nums[l];
//         ptr = &nums[l];
//       }
//     }
//     if(ptr)
//       *ptr = nums[i]; 
//     nums[i] = tmp;
//   }
//   return nums[k-1];
// }

void swap(int *a, int *b){
    int tmp=*b;
    *b=*a;
    *a=tmp;
}

int partition(int *arr, int low, int high){
    int pivot = arr[high];
    int i = (low-1);
    // printf("high = %d, low = %d\n", high, low);
    for(int j=low; j<high; j++){
      // printf("arr[j] = %d, j = %d, pivot = %d\n",arr[j], j, pivot);
        if(arr[j]>=pivot){
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    // printf("arr[i+1] = %d, i+1 = %d, arr[high] = %d, high = %d\n",arr[i+1], i+1, arr[high], high);
    swap(&arr[i+1], &arr[high]);
    return i+1;
}

int quickselect(int *nums, int low, int high, int k){
    int pi=partition(nums, 0, high);

    if(pi==k)   return pi;
    else if(pi>k)   quickselect(nums, 0, pi-1, k);
    else    quickselect(nums, pi+1, high, k);
    
    return;
}

int findKthLargest(int* nums, int numsSize, int k){
    return nums[quickselect(nums, 0, numsSize-1, k-1)];
}