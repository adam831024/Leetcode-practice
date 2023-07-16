void setZeroes(int** matrix, int matrixSize, int* matrixColSize){
    int x_line[200] = {0};
    int y_line[200] = {0};

    for(int i = 0 ; i < matrixSize;i++)
    {
        for(int j = 0 ; j < matrixColSize[0];j++)
        {
            printf("%d ", matrix[i][j]);
            if(0 == matrix[i][j])
            {
                x_line[j] = 1;
                y_line[i] = 1; 
            }
        }
        printf("\n");
    }
    for(int i = 0 ; i < matrixSize;i++)
    {
        if(1 == y_line[i])
        {
            for(int j = 0 ; j < matrixColSize[0]; j++)
                matrix[i][j] = 0;
        }
    }
    for(int j = 0 ; j < matrixColSize[0];j++)
    {
        if(1 == x_line[j])
        {
            for(int i = 0 ; i < matrixSize; i++)
                matrix[i][j] = 0;
        }
    }
}