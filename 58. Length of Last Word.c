int lengthOfLastWord(char * s){
    int ret = 0;
    int index = strlen(s)-1;

    while(s[index] == ' ' && index >=0)
    {
        index--;
    }
        
    while( index >=0 && s[index--] != ' ' )
    {
        ret++;
    }
        

    return ret;
}