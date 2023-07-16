/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

void fun(char **ret, int *retSize, int target, int index, int zero, char* tBuf)
{
    if( index == (target*2) )
    {
        ret[(*retSize)] = (char*)malloc(sizeof(char)*(target*2+1));
        memcpy(ret[(*retSize)], tBuf, (target*2+1));
        // printf("tBuf[] =");
        // for(uint8_t i = 0 ; i < target*2; i++)
        // {
        //     printf(" %c", tBuf[i]);
        // }
        // printf("\n");
        (*retSize)++;
    }
    else
    {
        if(zero == 0 )
        {
            tBuf[index] = '(';
            fun(ret, retSize, target, index+1, zero+1, tBuf );
            
        }
        else if( zero >= ((target*2)-index) )
        {
            tBuf[index] = ')';
            fun(ret, retSize, target, index+1, zero-1, tBuf );
        }
        else
        {
            for(uint8_t i = 0; i < 2; i ++)
            {
                if(i == 0)
                {
                    tBuf[index] = '(';
                    fun(ret, retSize, target, index+1, zero+1, tBuf);
                }
                else
                {
                    tBuf[index] = ')';
                    fun(ret, retSize, target, index+1, zero-1, tBuf);
                } 
            }
        }
        
    }
}
char ** generateParenthesis(int n, int* returnSize){
    *returnSize = 0;
    char **ret = (char**)malloc(sizeof(char*) * (2 << (2 * n - 1)));
    char *tBuf = (char*)malloc(sizeof(char)*(n*2+1));
    tBuf[2*n] = '\0';
    fun(ret, returnSize, n, 0, 0, tBuf);
    free(tBuf);
    return ret;
}
    