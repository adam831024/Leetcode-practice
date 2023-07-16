
int convert(char x)
{
    switch(x)
    {
        case 'I':
            return 1;
        case 'V':
            return 5;
        case 'X':
            return 10;
        case 'L':
            return 50;
        case 'C':
            return 100;
        case 'D':
            return 500;
        case 'M':
            return 1000;
        default:
            break;
    }
    return 0;
}
int romanToInt(char * s){
    int ans = 0;
    for(uint8_t i = 0 ; i < strlen(s) ; i++)
    {
        if(convert(s[i]) < convert(s[i+1]))
        {
            ans -= convert(s[i]);
        }
        else
        {
            ans += convert(s[i]);
        }
    }
    return ans;
}