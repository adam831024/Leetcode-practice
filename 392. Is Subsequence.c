bool isSubsequence(char * s, char * t){
    int count = 0;
    // while(t)
    // {
    //     printf("*t = %c, *s = %c\n", *t, *s);
    //     if(*t == *s)
    //     {
    //         s++;
    //         count++;
    //     }
    //     t++;
    // }
    for(int i = 0 ; i < strlen(t); i++)
    {
        if(s[count] == t[i])
            count++;
    }
    printf("count = %d", count);
    return count == strlen(s);
}