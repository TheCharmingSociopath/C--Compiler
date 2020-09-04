//Write a program to compute the product of two input matrices.

void main()
{
    int i, j, k, n;
    callout("print", "Enter n: ");
    n = callout("read", "int");
    int m;
    callout("print", "Enter m: ");
    m = callout("read", "int");
    int p;
    callout("print", "Enter p: ");
    p = callout("read", "int");
    int mat1[n][m];
    for(i=0;i<n;i+=1)
    {
        for(j=0;j<m;j+=1)
        {
            mat1[i][j] = callout("read","int");
        }
    }
    int mat2[m][p];
    for(i=0;i<m;i+=1)
    {
        for(j=0;j<p;j+=1)
        {
            mat2[i][j] = callout("read","int");
        }
    }
    int out[n][p];
    int sum;
    for(i=0;i<n;i+=1)
    {
        for(j=0;j<p;j+=1)
        {
            sum=0;
            for (k=0;k<m;k+=1) 
            {
                sum = sum + mat1[i][k]*mat2[k][j];
            }
            out[i][j] = sum;
            sum = 0;
        }
    }
    for(i=0;i<n;i+=1)
    {
        for(j=0;j<p;j+=1)
        {
            callout("print","int",out[i][j]," ");
        }
        callout("print","\n");
    }
    return;
}