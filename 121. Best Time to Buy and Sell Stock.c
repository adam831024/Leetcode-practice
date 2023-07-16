int maxProfit(int* prices, int pricesSize){

  int now = 0;
  int profit = 0;

  now = prices[0];
  for(int i = 0 ; i < pricesSize; i++)
  {
    now = now>prices[i]?prices[i]:now;
    profit = prices[i]-now > profit ? prices[i]-now: profit;
  }

  // printf("profit = %d", profit);
  return profit;
}

