#if 0 //recursion
void permute(int **grid, int r, int d,int r_index,int d_index, int *ret, int tVal )
{
  tVal += grid[d_index][r_index];
  if(r == r_index && d == d_index)
  {
    *ret = *ret > tVal? tVal : *ret;
  }
    
  if(r_index < r)
    permute(grid, r,d,r_index+1, d_index, ret, tVal);
  if(d_index < d)  
    permute(grid, r,d,r_index, d_index+1, ret, tVal);
}
int minPathSum(int** grid, int gridSize, int* gridColSize){
    int ret = 0x0FFFFFFF;
    permute(grid, gridColSize[0]-1, gridSize-1,  0, 0, &ret, 0);
    return ret;
}
#endif

int minPathSum(int** grid, int gridSize, int* gridColSize){
    int ret = 0x0FFFFFFF;
    int d = gridSize;
    int r = gridColSize[0];
    int tbl[d+1][r+1];
    memset(tbl, 0, sizeof(tbl));
    if(d == 0)
        return 0;

    tbl[0][0] = grid[0][0];

    for(int i=1;i<r;i++)
        tbl[0][i]=tbl[0][i-1] + grid[0][i];
    for(int i=1;i<d;i++)
        tbl[i][0]=tbl[i-1][0] + grid[i][0];

    for(int i=1;i<d;i++)
    {
        for(int j=1;j<r;j++)
        {
            int right= grid[i][j]+ tbl[i-1][j];
            int down= grid[i][j]+ tbl[i][j-1];
             tbl[i][j]=  fmin(right,down);
        }
    }
    return tbl[d-1][r-1];
}