//Write a program to compute the product of two input matrices.

void main()
{
    int i, j, k, n;
    callout("print", "Enter n: ");
    callout("read", "int", n);
    int m;
    callout("print", "Enter m: ");
    callout("read", "int", m);
    int p;
    callout("print", "Enter p: ");
    callout("read", "int", p);
    int mat1[n][m];
    for(i=0;i<n;i=i+1)
    {
        for(j=0;j<m;j=j+1)
        {
            callout("read","int", mat1[i][j]);
        }
    }
    int mat2[m][p];
    for(i=0;i<m;i=i+1)
    {
        for(j=0;j<p;j=j+1)
        {
            callout("read","int", mat2[i][j]);
        }
    }
    int out[n][p];
    int sum;
    for(i=0;i<n;i=i+1)
    {
        for(j=0;j<p;j=j+1)
        {
            sum=0;
            for (k=0;k<m;k=k+1) 
            {
                sum = sum + mat1[i][k]*mat2[k][j];
            }
            out[i][j] = sum;
            sum = 0;
        }
    }
    for(i=0;i<n;i=i+1)
    {
        for(j=0;j<p;j=j+1)
        {
            callout("print","int",out[i][j]," ");
        }
        callout("print","\n");
    }
    return;
}