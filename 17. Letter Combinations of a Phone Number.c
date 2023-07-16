/**
 * Note: The returned array must be malloced, assume caller calls free().
 */





void gogogo(char *arr,uint16_t length, uint8_t index, char** ret, uint8_t* tBuf, uint8_t* count)
{
    char table[8][5]={{'a','b','c'},{'d','e','f'},{'g','h','i'},{'j','k','l'},{'m','n','o'},{'p','q','r','s'},{'t','u','v'},{'w','x','y','z'}};

    if(index == length)
    {
        tBuf[length] = 0;
        ret[*count] = (char*)malloc(sizeof(char) * (length+1));
        memcpy(ret[*count], tBuf, (length+1));
        (*count) = (*count) +1;
        printf("tBuf[0] = %c\n", tBuf[0]);
        printf("count = %d\n", *count);
    }
    else
    {
        printf("strlen(table[atoi(pgDigits[index])]) = %d\n", (strlen(table[(arr[index] -'2')])));
        for(uint16_t i = 0; i < strlen(table[(arr[index]-'2')]); i++)
        {
            tBuf[index] = table[(arr[index]-'2')][i];
            gogogo(arr, length, index+1, ret, tBuf, count);
        }
    }
}
char ** letterCombinations(char * digits, int* returnSize){
    uint16_t length = strlen(digits);
    char **ret = NULL;
char table[8][5]={{'a','b','c'},{'d','e','f'},{'g','h','i'},{'j','k','l'},{'m','n','o'},{'p','q','r','s'},{'t','u','v'},{'w','x','y','z'}};
    printf("digital length = %d\n", length);
    
    if(length)
    {
        *returnSize = 1;
        for(uint8_t i = 0; i < length; i++)
            (*returnSize) *= strlen(table[(digits[i] -'2')]);
    }
    else
    {
        (*returnSize) = 0;
        return ret;
    }

    printf("(*returnSize) = %d\n", (*returnSize));
    ret = (char**)malloc(sizeof(char*) * (*returnSize));
    uint8_t tBuf[5] = {0,0,0,0,0};
    uint8_t count = 0;
    gogogo(digits, length, 0, ret, tBuf, &count);
    return ret;
}