void rotate(int** matrix, int matrixSize, int* matrixColSize){
    // printf("matrixSize = %d\n", matrixSize);
    // printf("matrixColSize = %d\n", *matrixColSize);
    int **tBuf = (int**) malloc(sizeof(int*) * matrixSize);
    
    for(uint8_t i = 0 ; i < matrixSize;i++)
        tBuf[i] = (int*)malloc(sizeof(int) * matrixSize);
    for(int i = 0 ; i < matrixSize; i++)
    {
        for(int j = 0 ; j < matrixSize; j++)
        {
            tBuf[i][j] = matrix[i][j];
        }
    }
    // printf("tBuf =");
    for(int i = 0 ; i < matrixSize; i++)
    {
        for(int j = 0 ; j < matrixSize; j++)
        {
            matrix[i][j] = tBuf[matrixSize-1-j][i];
            // printf(" %d", tBuf[matrixSize-1-j][i]);
        }
        // printf("\n");
    }
    for(uint8_t i = 0 ; i < matrixSize;i++)
        free(tBuf[i]);
    free(tBuf);
}