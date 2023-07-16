char * addBinary(char * a, char * b)
{
    int a_len = strlen(a);
    int b_len = strlen(b);
    int bigger_len = a_len > b_len ? a_len : b_len;
    int index = 0;
    bool flag = false;
    printf("a_len = %d, b_len = %d, bigger_len = %d\n", a_len, b_len,bigger_len );
    char *ret = (char*)malloc(sizeof(char) * (bigger_len+2));
    memset(ret, 0, sizeof(char) * (bigger_len+2));
    printf("a = ");
    for(int i = 0 ; i < a_len; i++)
    {
        printf("%c ", a[i]);
        if(a[i])
            ret[bigger_len - i] += a[a_len-1-i] - '0';
    }
    printf("\n");
    printf("b = ");
    for(int i = 0 ; i < b_len; i++)
    {
        printf("%c ", b[i]);
        if(b[i])
            ret[bigger_len - i] += b[b_len-1-i] - '0';
    }
    printf("\n");
    for(int i = bigger_len ; i >= 1; i--)
    {
        if(ret[i] >= 2)
        {
            ret[i] -= 2;
            ret[i-1] += 1;
        }
        printf("%x ", ret[i]);
    }
    printf("\n");
    for(int i = 0 ; i < bigger_len+1; i++)
    {
        if(false == flag && ret[i] == 0)
        {
            index++;
            continue;
        }
        flag = true;
        ret[i] +=0x30;
        printf("%x ", ret[i]);
    }
    printf("\nindex = %d ", index);
    if(index == bigger_len+1)
    {
        free(ret);
        return a;
    }
    return ret+index;
}
