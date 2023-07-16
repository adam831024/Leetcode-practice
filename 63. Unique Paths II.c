#if 0   //time excess limit
void fun(int *ret, int **tbl, int downSize, int rightSize, int index, int targetStep, int downIndex, int rightIndex)
{
    // printf("index = %d, downIndex = %d , rightIndex = %d\n", index, downIndex, rightIndex);
    if(index == targetStep)
    {
        (*ret)++;
    }
    else
    {
        if( downIndex < downSize-1 && tbl[downIndex+1][rightIndex] == 0)
        {
            // printf("down\n");
            fun(ret, tbl,downSize,rightSize, index+1, targetStep, downIndex+1, rightIndex );
        }
        if( rightIndex < rightSize-1 && tbl[downIndex][rightIndex+1] == 0)
        {
            // printf("right\n");
            fun(ret, tbl,downSize,rightSize, index+1, targetStep, downIndex, rightIndex+1 );
        }
    }
}
int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridSize, int* obstacleGridColSize){
    int ret = 0;
    int targetStep = obstacleGridSize+obstacleGridColSize[0]-2;
    if(obstacleGrid[0][0] == 1)
        return 0;

    fun(&ret, obstacleGrid,obstacleGridSize,obstacleGridColSize[0], 0, targetStep, 0, 0 );
    return ret;
}
#else
int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridSize, int* obstacleGridColSize){
    if(obstacleGrid[0][0] == 1)
        return 0;
    int colSize = obstacleGridColSize[0];

    printf("tbl = \n");
    for(int i = 0 ; i < obstacleGridSize; i++)
    {
        for(int j = 0 ; j < colSize; j++)
        {
            obstacleGrid[i][j] = obstacleGrid[i][j] == 1 ? -1: 0;
            printf("%d ", obstacleGrid[i][j]);
        }
        printf("\n");
    }
    obstacleGrid[0][0] = 1;

    for(int i = 1 ; i < obstacleGridSize; i++)
    {
        if(-1 == obstacleGrid[i][0])
            continue;
        else
        {
            obstacleGrid[i][0] = obstacleGrid[i-1][0] == -1 ? 0 : obstacleGrid[i-1][0];
        }
        printf("obstacleGrid[%d][0] = %d\n",i, obstacleGrid[i][0]);
    }
    for(int j = 1 ; j < colSize; j++)
    {
        if(-1 == obstacleGrid[0][j])
            continue;
        else
        {
            obstacleGrid[0][j] = obstacleGrid[0][j-1]  == -1 ? 0: obstacleGrid[0][j-1];
        }
        printf("obstacleGrid[0][%d] = %d\n", j, obstacleGrid[0][j]);
    }
    for(int i = 1 ; i < obstacleGridSize; i++)
    {
        for(int j = 1 ; j < colSize; j++)
        {

            obstacleGrid[i][j] = obstacleGrid[i][j] == -1 ? 0 : (obstacleGrid[i-1][j] == -1 ? 0 : obstacleGrid[i-1][j]) + (obstacleGrid[i][j-1] == -1 ? 0 : obstacleGrid[i][j-1] );
            // obstacleGrid[i][j] = obstacleGrid[i-1][j] + obstacleGrid[i][j-1] ;
        }
    }

    return obstacleGrid[obstacleGridSize-1][colSize-1] < 0 ? 0 : obstacleGrid[obstacleGridSize-1][colSize-1];
}
#endif