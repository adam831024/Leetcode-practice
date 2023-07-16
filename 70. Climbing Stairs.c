int climbStairs(int n){
    int ret = 1;
    int prev = 1;
    int prevprev = 1;

    if(n <=1)
        return ret;
    
    for(int i = 0; i < n-1 ;i++)
    {
        ret = prev + prevprev;
        prevprev = prev;
        prev = ret;
    }
    return ret;
}