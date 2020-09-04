//Check if a given input number N is prime.

void main()
{
    int N, i;
    callout("print", "Enter N: ");
    N = callout("read", "int");
    if(N == 1)
    {
        callout("print", "NO");
        return;
    }
    if(N == 2 || N == 3)
    {
        callout("print", "YES");
        return;
    }
    for(i = 2; i*i <= N; i += 1)
    {
        if(N % i == 0)
        {
            callout("print", "NO");
            return;
        }
    }
    callout("print", "YES");
    return;
}
