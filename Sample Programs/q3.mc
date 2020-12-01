bool checkPrime(int n) 
{
    int i; 
    if (n <= 1)
    {
        return false; 
    } 
    if(n == 2 || n == 3)
    {
        return true;
    }
    for (i = 2; i*i <= n; i=i+1) 
    {
        if (n % i == 0) 
        {
            return false; 
        }    
    }                        
    return true; 
} 

void main()
{
    int N;
    int i;
    callout("print", "N = ");
    N = callout("read", N);
    int sum = 0;
    for(i=2;i<=N;i=i+1)
    {
        bool x = callout("checkPrime",i);
        if(x == true)
        {
            sum = sum + i;
        }
    }
    callout("print", sum);
    return;
}
