bool check(char* data, uint16_t dataLen)
{
    for(uint16_t i = 0; i < (dataLen/2); i++)
    {
        if(data[i] != data[dataLen-i-1])
            return false;
    }
    return true;
}
char * longestPalindrome(char * s){
    uint16_t length = strlen(s);
    char *result = NULL;
    uint16_t max = 0;

    // printf("length = %d\n", length);
    for(uint16_t i = 0 ; i < length ; i++)
    {
        for(uint16_t j = (length-1); j > i ; j--)
        {
            // printf("s[j] =%c, s[i] = %c, j = %d, i = %d\n", s[j], s[i], j, i);
            if(true == check(&s[i], j-i+1))
            {
                if(max < (j-i+1))
                    max = (j-i+1);
                // printf("max = %d\n", max);
                // return &s[i];
            }

        }
    }
    if(max == 0)
    {
        s[1] = 0;
        return s;
    }
    
    for(uint16_t i = 0 ; i < length ; i++)
    {
        for(uint16_t j = (length-1); j > i ; j--)
        {
            if(true == check(&s[i], j-i+1))
            {
                if(max == (j-i+1))
                {
                    s[j+1] = 0;
                    return &s[i];
                }
            }
        }
    }

    return result;
}