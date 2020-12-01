void main()
{
    int N;
    int K;
    int i=1,j=2,k;
    callout("print", "N = ");
    N = callout("read", N);
    callout("print", "K = ");
    K = callout("read", K);
    int sum = 0;
    sum += 1;
    for(i=1;i<=N;i+=1)
    {
        int temp = 1;
        for(j=1;j<=K;i+=1)
        {
            temp *= i;
        }
    }
    callout("print", sum);
    return;
}
