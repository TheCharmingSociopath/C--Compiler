// Write a program which computes g(N,k) = ∑iᴷ, 1<=i<=N where N and k are given as inputs.

void main()
 {
    int N;
    int K;
    int i;
    int j;
    callout("print", "Enter N: ");
    callout("read", "int", N);
    callout("print", "Enter K: ");
    callout("read", "int", K);
    int sum = 0;
    for(i = 1; i <= N; i = i + 1)
    {
        int temp = 1;
        for(j = 1; j <= K; i = i+1){
        temp = temp * i;
        }
        sum = sum + temp;
    }
    callout("print", sum);
   return;
 }
