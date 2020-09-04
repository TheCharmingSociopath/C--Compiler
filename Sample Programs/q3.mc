//Find the sum of all prime numbers strictly less than N where N is provided as an input.

void main()
{
    int N, i, sum = 0;
    bool isPrime[100000];
    for (int i = 0; i < 100000; ++i) {
        isPrime[i] = true;
    }
    callout("print", "Enter N: ");
    N = callout("read", "int");
    for(i=2; i<N; i+=1)
    {
        if (isPrime[i] == true) {
            for (int j = i+i; j <= N; j += i) {
                isPrime[j] = false;
            }
            sum += i;
        }
    }
    callout("print", "int", sum);
    return;
}
