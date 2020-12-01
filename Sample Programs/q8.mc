//Write merge sort program.

void merge(int n,int arr,int l,int mid,int r)
{
    int i;
    int j;
    int k;
    int n1 = mid-1+1;
    int n2 = r-mid;
    int left[n1];
    int right[n2];
    for(i=0;i< n1; i = i + 1)
    {
        left[i] = arr[l+i];
    }
    for(j=0;j< n2;j = j + 1)
    {
        right[j] = arr[mid+1+j];
    }
    i=0;
    j=0;
    k=l;
    while(i< n1 && j< n2)
    {
        if(left[i]<=right[j])
        {
            arr[k] = left[i];
            i = i + 1;
        }
        else
        {
            arr[k] = right[j];
            j = j + 1;
        }
        k = k + 1;
    }
    while(i< n1)
    {
        arr[k] = left[i];
        i = i + 1;
        k = k + 1;
    }
    while(j< n2)
    {
        arr[k]=right[j];
        j = j + 1;
        k = k + 1;
    }
}
void mergeSort(int n,int arr,int l,int r)
{
    if(l < r)
    {
        int mid = (l+r)/2;
        callout("mergeSort",n,arr[n],l,mid);
        callout("mergeSort",n,arr[n],mid+1,r);
        callout("merge",n,arr[n],l,mid,r);
    }
    return;
}    
void main()
{
    int i;
    int n;
    callout("print", "n = ");
    n = callout("read", n);
    int arr[n];
    for(i=0;i< n;i = i + 1)
    {
        arr[i] = callout("read",arr[i]);
    }
    callout("mergeSort",n,arr[n],0,n-1);
    for(i=0;i< n;i = i + 1)
    {
        callout("print",arr[i]);
    }
    callout("print","\n");
    return;
}
