/*
  012     345     678
0 0       1       2
1 012     345     678
2 
3 3       4       5
4 012     345     678
5
6 6       7       8
7 012     345     678
8
*/

bool check_box(char** board, uint8_t no)
{
    uint8_t array[9];
    uint8_t index = 0;
    memset(array, 0, 9);
    for(uint8_t i = 0; i < 3; i++)
    {
       for(uint8_t j = 0; j < 3 ; j++)
       {
            if(board[(no-(no%3))+i][((no%3)*3)+j] == '.')
                continue;
            else
            {
                array[index++] = board[(no-(no%3))+i][((no%3)*3)+j];
            }
       }
    }
    for(uint8_t i = 0 ;i < strlen(array); i++)
    {
        uint8_t tmp = array[i];
        for(uint8_t j = i+1 ; j < strlen(array); j++)
        {
            if(tmp == array[j])
                return false;
        }
    }
    return true;
}

bool check_col(char** board, uint8_t no)
{
    for(uint8_t i = 0; i < 9; i++)
    {
        if(board[i][no] == '.')
            continue;
        else
        {
            for(uint8_t j = (i+1); j < 9; j++)
            {
                if(board[i][no] == '.')
                    continue;
                else
                {
                    if(board[i][no] == board[j][no])
                        return false;
                }
            }
        }
    }
    return true;
}
bool check_row(char** board, uint8_t no)
{
    for(uint8_t i = 0; i < 9; i++)
    {
        if(board[no][i] == '.')
            continue;
        else
        {
            for(uint8_t j = (i+1); j < 9; j++)
            {
                if(board[no][j] == '.')
                    continue;
                else
                {
                    if(board[no][i] == board[no][j])
                        return false;
                }
            }
        }
    }
    return true;
}
bool isValidSudoku(char** board, int boardSize, int* boardColSize){
    printf("boardSize = %d, boardColSize = %d \n", boardSize, *boardColSize);
    for(uint8_t i = 0; i < boardSize; i++)
    {
        if(false == check_row(board, i))
            return false;
        if(false == check_col(board, i))
            return false;
        if(false == check_box(board, i))
            return false;
    }
    return true; 
}