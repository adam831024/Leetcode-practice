int reverse(int x)
{
    long int ret = 0;
    int minus = 0;
    if(x < -2147483647)
        return 0;
    if(x<0)
    {
        minus = 1;
        x = ~(x)+1;
    }
    while(x>0)
    {
        // printf("ret = %d\n", ret);
        if(ret*10 > 2147483648)    
            return 0;
        ret *= 10;
        ret += (x%10);
        x /= 10;
    }
    if(minus)
    {
        ret = ~(ret)+1;
    }
        
    return (int)ret;
}