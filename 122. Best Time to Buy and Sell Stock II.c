int maxProfit(int* prices, int pricesSize){
    int profit = 0;

    for(int i = 0; i < pricesSize-1; i++)
    {
        if(prices[i+1] > prices[i])
            profit+=(prices[i+1] - prices[i]);
    }
    return profit;
}