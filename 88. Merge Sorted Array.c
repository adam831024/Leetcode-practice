void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    memcpy(&nums1[m], nums2, n*sizeof(int));
    int tmp = 0;
    for(int i = 0 ; i < m+n-1; i++)
    {
        for(int j = 0 ; j < m+n-i-1; j++)
        {
            if(nums1[j+1] < nums1[j])
            {
                tmp = nums1[j];
                nums1[j] = nums1[j+1];
                nums1[j+1] = tmp;
            }
        }
    }
}