bool canConstruct(char * ransomNote, char * magazine){
    int r_len = strlen(ransomNote);
    int m_len = strlen(magazine);
    printf("r_len = %d, m_len = %d\n", r_len, m_len);
    int r_tbl[26] = {0};
    int m_tbl[26] = {0};
    for(int i = 0 ; i < r_len ; i++)
    {
        r_tbl[ransomNote[i]-'a'] = r_tbl[ransomNote[i]-'a']+1;
    }
    for(int i = 0 ; i < m_len ; i++)
    {
        m_tbl[magazine[i]-'a'] = m_tbl[magazine[i]-'a']+1;
    }
    for(int i = 0 ; i < 26 ; i++)
    {
        if(r_tbl[i] )
        {
            // printf("r_tbl[i] = %d, m_tbl[i] = %d\n", r_tbl[i], m_tbl[i]);
            if(r_tbl[i]-m_tbl[i] > 0)
                return false;
        }
    }
    return true;
}