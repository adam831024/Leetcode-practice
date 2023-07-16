char * longestCommonPrefix(char ** strs, int strsSize){
  // printf("strsSize = %d\n", strsSize);
  // printf("strlen(strs[0]) = %d\n", strlen(strs[0]));

  uint8_t count = 0;
  uint8_t strLen = strlen(strs[0]);
  char tmp = 0;

  uint8_t stop = 0;
    
    for(uint8_t j =0; j<strLen;j++)
    {
      tmp = strs[0][j];
      for(uint8_t i = 0; i < strsSize; i++)
      {
        if(tmp != strs[i][j])
        {
          stop = 1;
        }
      }
      if(stop)
        break;
      else
        count++;
    }
  // printf("count = %d\n", count);
  memset(&strs[0][count], 0, strLen-count);
  return strs[0];
}