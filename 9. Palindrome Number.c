int power(int val, int power)
{
  int x = 1;
  for(int i = 0; i < power ; i++)
  {
    x *= val;
  }
  printf("power = %d, x = %d\n", power, x);
  return x;
}
bool isPalindrome(int x)
{
  bool ret = false;
  int level = 0;
  int y = x;
  if(x < 0)
    return false;
  else if(x == 0)
    return true;
  while(x)
  {
    level++;
    x%10;
    x/=10;
  }
  printf("level = %d\n", level);

  for(int i = 0; i < (level/2); i++)
  {
    if(y%10 != y/(power(10, level-(i*2+1))))
    {
      ret = false;
      break;
    }
    
    y%=(power(10, level-(i*2+1)));
    y/=10;
    ret = true;
    if(y==0)
      break;
  }
  if(level == 1)
    ret = true;

  return ret;
}