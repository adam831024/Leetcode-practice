bool isValid(char * s){
    uint16_t length = strlen(s);
    if(length <= 1)
        return false;
    uint8_t *filo = (uint8_t*)malloc(sizeof(uint8_t)*length+1);
    uint16_t index = 0;
    printf("length = %d\n", length);
    for(uint16_t i = 0; i < length ; i++)
    {
        switch(s[i])
        {
            case '[':
            case '{':
            case '(':
            {
                index++;
                filo[index] = s[i];
            }
            break;
            case '}':
            {
                if(filo[index] == '{')
                    index--;
                else
                {
                    free(filo);
                    return false;
                }
            }
            break;
            case ')':
            {
                if(filo[index] == '(')
                    index--;
                else
                {
                    free(filo);
                    return false;
                }
            }
            break;
            case ']':
            {
                if(filo[index] == '[')
                    index--;
                else
                {
                    free(filo);
                    return false;
                }       
            }
            break;
            default:
                break;
        }
    }
    free(filo);

    if(index == 0)
        return true;
    return false;
}