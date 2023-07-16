#if 0
void fun(int col, int row, int* ret, int index, int right_index, int down_index)
{
    if(index >= (row+col-2))
    {
        (*ret) = (*ret) +1;
    }
    else
    {
        if(right_index < row-1)
            fun(col, row, ret, index+1, right_index+1, down_index);
        if(down_index < col-1)
            fun(col, row, ret, index+1, right_index, down_index+1);
    }
}

int uniquePaths(int m, int n){
    int ret = 0;
    fun(n, m, &ret, 0, 0, 0);
    return ret;
}

#endif
#if 1
int uniquePaths(int m, int n){
    int ret[m][n] ;
    for(int i = 0 ; i < m ; i++)
        ret[i][0] = 1;
    for(int i = 0 ; i <n ; i++)
        ret[0][i] = 1;
    
    for(int i = 1 ; i < m ; i++)
    {
        for(int j = 1 ; j <n ; j++)
        {
            ret[i][j] = ret[i-1][j] + ret[i][j-1];
        }
    }
    return ret[m-1][n-1];
}

#endif