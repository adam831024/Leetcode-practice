#define CHECK_USED(x) (x & 0x80)//1<<7
#define USED(x) (x|=0x80)//1<<7
#define UN_USED(x) (x &= ~0x80)
void fun(char** board, int a_index, int a_max, int b_index, int b_max, bool* ret, char *word, int wordLen, int index)
{
    // printf("gotcha =%x\n", board[b_index][a_index]);
    // printf("b_index = %d, a_index = %d\n",b_index, a_index );
    if(wordLen == index)
    {
        // printf("get the answer \n");
        (*ret) = true;
        return;
    }

    if(b_index > 0)
    {
        if(0==CHECK_USED(board[b_index-1][a_index]))
        {
            // printf("board[col_index-1][row_index] = %d\n", board[b_index-1][a_index]);
            if( board[b_index-1][a_index] == word[index])
            {
                // printf("^|\n");
                USED( board[b_index-1][a_index]);
                fun(board, a_index, a_max, b_index-1, b_max, ret, word, wordLen, index+1);
                UN_USED( board[b_index-1][a_index]);
            }
        }
    }
    if(b_index < b_max-1)
    {
        if(0==CHECK_USED(board[b_index+1][a_index]))
        {
            // printf("board[b_index+1][a_index] = %d\n", board[b_index+1][a_index]);
            if(board[b_index+1][a_index] == word[index])
            {
                // printf("v|\n");
                USED(board[b_index+1][a_index]);
                fun(board, a_index, a_max, b_index+1, b_max, ret, word, wordLen, index+1);
                UN_USED(board[b_index+1][a_index]);
            }
        }
    }
    if(a_index > 0)
    {
        if(0==CHECK_USED(board[b_index][a_index-1]))
        {
            // printf("board[b_index][a_index-1]= %d\n", board[b_index][a_index-1]);
            if(board[b_index][a_index-1] == word[index])
            {
                // printf("<-\n");
                USED(board[b_index][a_index-1]);
                fun(board, a_index-1, a_max, b_index, b_max, ret, word, wordLen, index+1);
                UN_USED(board[b_index][a_index-1]);
            }
        }
    }
    if(a_index < a_max-1)
    {
        if(0==CHECK_USED(board[b_index][a_index+1]))
        {
            // printf("board[b_index][a_index+1] = %d\n", board[b_index][a_index+1]);
            if(board[b_index][a_index+1] == word[index])
            {
                // printf("->\n");
                USED(board[b_index][a_index+1]);
                fun(board, a_index+1, a_max, b_index, b_max, ret, word, wordLen, index+1);
                UN_USED(board[b_index][a_index+1]);
            }
        }
    }

}
bool exist(char** board, int boardSize, int* boardColSize, char * word){
    bool ret = false;

    for(int i = 0; i < boardSize; i++)
    {
        for(int j = 0 ; j <  boardColSize[0]; j++)
        {
            // printf("%d ", board[i][j]);
            if(word[0] == board[i][j])
            {
                // fun(board, j, row_max, i, col_max, ret, word, wordLen, index+1);
                USED(board[i][j]);
                fun(board, j,  boardColSize[0],i,  boardSize, &ret, word, strlen(word), 1);
                UN_USED(board[i][j]);
            }
        }
        // printf("\n");
    }

    
    return ret;
}