int maxArea(int* height, int heightSize){

    int ret = 0;
    int tmpVal = 0;
    int start = 0;
    int end =  heightSize-1;

    while(start < end)
    {
        if(height[start] > height[end])
        {
            tmpVal = (end-start)*height[end];
            end--;
        }
        else
        {
            tmpVal = (end-start)*height[start];
            start++;
        }
        if(tmpVal > ret)
            ret = tmpVal;
    }
    return ret;
}