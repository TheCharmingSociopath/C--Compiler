//Write a program for insertion sort.


void main()
{
    int i, j, n, arr[n];
    callout("print", "Enter n: ");
    callout("read", "int", n);
    for(i=0; i<n; i = i+1)
    {
        callout("read", "int", arr[i]);
    }
    int k;
    for(i=1; i<n; i = i+1)
    {
        k = arr[i];
        j = i-1;
        while(j >= 0 && arr[j] > k)
        {
            arr[j+1] = arr[j];
            j = j-1;
        }
        arr[j+1]=key;
    }
    for(i=0; i<n; i = i+1)
    {
        callout("print", "int", arr[i], " ");
    }
    callout("print", "\n");
    return;
}