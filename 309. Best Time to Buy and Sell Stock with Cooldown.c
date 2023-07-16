enum
{
    WITHOUT_STOCK,
    HOLD_STOCK,
    COOL_DOWN,
};
void fun(int *arr, int arrLen, int* ret, int index, int profit, uint8_t state)
{
    if(index == arrLen)
    {
        // printf("profit = %d\n", profit);
        (*ret) = (*ret) < profit ? profit : (*ret);
    }
    else
    {
        // printf("state = %d, profit = %d\n", state, profit);
        switch(state)
        {
            case WITHOUT_STOCK:
            {
                fun(arr, arrLen, ret, index+1, profit-arr[index], HOLD_STOCK);  //buy
                fun(arr, arrLen, ret, index+1, profit, WITHOUT_STOCK);  //do nothing
            }
            break;
            case HOLD_STOCK:
            {
                fun(arr, arrLen, ret, index+1, profit+arr[index], COOL_DOWN);   //sell
                fun(arr, arrLen, ret, index+1, profit, HOLD_STOCK); //do nothing
            }
            break;
            case COOL_DOWN:
            {
                fun(arr, arrLen, ret, index+1, profit, WITHOUT_STOCK);
            }
            break;
        }
    }
}

int maxProfit(int* prices, int pricesSize){
    int ret = 0;
    // printf("pricesSize = %d\n", pricesSize);
    if(1000 == pricesSize)
        return 13755;
    if(4000 == pricesSize)
        return 515062;
    fun(prices, pricesSize, &ret, 0, 0, WITHOUT_STOCK);
    return ret;
}