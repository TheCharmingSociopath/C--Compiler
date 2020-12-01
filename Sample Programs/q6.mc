void main()
{
    int i;
    int j;
    int n;
    callout("print", "n = ");
    int arr[n];
    int k;
    for(i = 1;i< n;i+=1)
    {
        k = arr[i];
        j = i-1;
        while(j >= 0 && arr[j] > k)
        {
            arr[j+1] = arr[j];
            j -= 1;
        }
        arr[j+1]=k;
    }
    for(i=0;i< n;i+=1)
    {
        callout("print",arr[i]);
    }
    callout("print","\n");
    return;
}