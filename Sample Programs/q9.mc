//Write a program to compute the sum of two input matrices.

void main()
{
    int i;
    int j;
    int n;
    callout("print", "n = ");
    n = callout("read", n);
    int m;
    callout("print", "m = ");
    m = callout("read", m);
    int mat1[n][m];
    for(i=0;i< n;i=i+1)
    {
        for(j=0;j< m;j=j+1)
        {
            mat1[i][j] = callout("read",mat1[i][j]);
        }
    }
    int mat2[n][m];
    for(i=0;i< n;i=i+1)
    {
        for(j=0;j< m;j=j+1)
        {
            mat2[i][j] = callout("read",mat2[i][j]);
            mat2[i][j] = mat2[i][j] +  mat1[i][j];
        }
    }
    for(i=0;i< n;i=i+1)
    {
        for(j=0;j< m;j=j+1)
        {
            callout("print",mat2[i][j]);
        }
        callout("print","\n");
    }
    return;
}
