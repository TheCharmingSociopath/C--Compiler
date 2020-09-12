//Write a program to compute the sum of two input matrices.

void main()
{
    int i, j, n;
    callout("print", "Enter n: ");
    n = callout("read", "int");
    int m;
    callout("print", "m = ");
    m = callout("read", "int");
    int mat1[n][m];
    for(i=0;i<n;i+=1)
    {
        for(j=0;j<m;j+=1)
        {
            mat1[i][j] = callout("read","int");
        }
    }
    int mat2[n][m];
    for(i=0;i<n;i+=1)
    {
        for(j=0;j<m;j+=1)
        {
            mat2[i][j] = callout("read","int");
            mat2[i][j] += mat1[i][j];
        }
    }
    for(i=0;i<n;i+=1)
    {
        for(j=0;j<m;j+=1)
        {
            callout("print","int",mat2[i][j]," ");
        }
        callout("print","\n");
    }
    return;
}