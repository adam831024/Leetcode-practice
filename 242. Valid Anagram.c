bool isAnagram(char * s, char * t){
    int tbl[26] = {0};
    memset(tbl, 0, sizeof(char)*26);
    for(int i = 0 ; i < strlen(s);i++)
    {
        tbl[s[i]-'a']++;
    }
    for(int i = 0 ; i < strlen(t);i++)
    {
        tbl[t[i]-'a']--;
    }
    for(int i = 0 ; i < 26;i++)
    {
        if(0 != tbl[i])
            return false;
    }
    return true;
}