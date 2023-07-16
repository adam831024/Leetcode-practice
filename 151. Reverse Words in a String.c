char * reverseWords(char * s){
    int sLen = strlen(s);
    int storeIndex = 0;
    int index = 0;
    char *tBuf = (char*)malloc(sizeof(char) * sLen);
    memcpy(tBuf, s, sizeof(char) * sLen);
    memset(s, 0, sLen*sizeof(char));
    printf("strlen(s) = %d\n", sLen);
    for(int i = sLen-1; i >=0 ;i--, storeIndex++)
    {
        if(' ' == tBuf[i])
        {
            printf("i = %d, storeIndex = %d, space\n", i, storeIndex);
            for(int j = 0 ; j < storeIndex;j++)
            {
                s[index++] = tBuf[i+j+1];
                if(storeIndex-1 == j)
                    s[index++] = ' ';
            }
                
            storeIndex = -1;
        }
        if(0==i)
        {
            storeIndex++;
            for(int j = 0 ; j < storeIndex;j++)
            {
                s[index++] = tBuf[i+j];
            }
            printf("i = %d, storeIndex = %d, final\n", i, storeIndex);
        }
    }
    free(tBuf);
    for(int i = index-1; i >=0 ;i--)
    {
        if(s[i] == ' ')
            s[i] = 0;
        else
            break;
    }
    return s;
}