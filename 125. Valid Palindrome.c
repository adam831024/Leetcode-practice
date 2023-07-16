char filter(char a)
{
    if('a' <= a && 'z' >= a)
    {
        return a;
    }
    else if('A' <= a && 'Z' >= a)
    {
        return a+0x20;
    }
    else if('0' <= a && '9' >= a)
    {
        return a;
    }
    else
    {
        return 0;
    }
}
bool check_Palindrome(char* arr, int arrLen)
{
    for(int i = 0 ; i <arrLen/2; i++)
    {
        if(arr[i] != arr[arrLen-1-i])
            return false;
    }
    return true;
}
bool isPalindrome(char * s){
    int s_len = strlen(s);
    char arr[s_len];
    int arr_len = 0;
    for(int i = 0 ; i < s_len; i++)
    {
        char tmp_char = filter(s[i]);
        if(tmp_char)
            arr[arr_len++] = tmp_char;
    }
    // for(int i = 0 ; i < arr_len; i++)
    //     printf("%c", arr[i]);
    return check_Palindrome(arr, arr_len);
}