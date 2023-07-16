int kthFactor(int n, int k){
    int now = 0;

    for(int i = 1;i <= n ; i++ )
    {
        if(n%i == 0)
        {
            now++;
            if(now == k)
            {
                return i;
            }
        }
    }
    return -1;
}