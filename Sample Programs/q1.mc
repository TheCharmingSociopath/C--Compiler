// Write a program which computes g(N,k) = ∑iᴷ, 1<=i<=N where N and k are given as inputs.

void main()
 {
    int N, K, i, j;
    callout("print", "Enter N: ");
    callout("read", "int");
    callout("print", "Enter K: ");
    callout("read", "int");
    int sum = 0;
    for(i = 1; i <= N; i = i + 1)
    {
        int temp = 1;
        for(j = 1; j <= K; i = i+1){
            temp = temp * i;
        }
        sum = sum + temp;
    }
    callout("print", "int", sum);
    return;
 }
