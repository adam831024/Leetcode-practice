int count_arr(int* arr)
{
    int ret = 0;
    for(uint8_t i = 0 ; i < 255;i++)
    {
        if(arr[i] != 0)
            ret++;
    }
    return ret;
}
int lengthOfLongestSubstring(char * s){
    int count = 0;
    int s_len = strlen(s);
    int tbl[255] = {0};
    memset(tbl, 0, sizeof(int)*255);
    for(int i = 0 ; i < s_len;i++)
    {
        for(int j = i; j < s_len;j++)
        {
            if(0 == tbl[s[j]])
                tbl[s[j]] = 1;
            else
                break;
        }
        count = count < count_arr(tbl) ? count_arr(tbl): count;
        memset(tbl, 0, sizeof(int)*255);
    }
    return count;
}