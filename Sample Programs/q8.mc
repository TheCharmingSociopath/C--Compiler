//Write merge sort program.

void merge(int arr[],int l,int mid,int r)
{
    int i, j, k, n1 = m-1+1, n2 = r-m, left[n1], right[n2];
    for(i=0;i<n1;i+=1)
    {
        left[i] = arr[l+i];
    }
    for(j=0;j<n2;j+=1)
    {
        right[j] = arr[mid+1+j];
    }
    i=0;
    j=0;
    k=l;
    while(i<n1 && j<n2)
    {
        if(left[i]<=right[j])
        {
            arr[k] = left[i];
            i+=1;
        }
        else
        {
            arr[k] = right[j];
            j+=1;
        }
        k+=1;
    }
    while(i<n1)
    {
        arr[k] = left[i];
        i+=1;
        k+=1;
    }
    while(j<n2)
    {
        arr[k]=right[j];
        j+=1;
        k+=1;
    }
}
void mergeSort(int arr[],int l,int r)
{
    if(l < r)
    {
        int mid = (l+r)/2;
        callout("mergeSort","int",arr,l,"int",mid);
        callout("mergeSort","int",arr,mid+1,"int",r);
        callout("merge","int",arr,l,"int",mid,"int",r);
    }
    return;
}    

void main()
{
    int i, n, arr[n];
    callout("print", "Enter n: ");
    n = callout("read", "int");
    for(i=0;i<n;i+=1)
    {
        arr[i] = callout("read","int");
    }
    callout("mergeSort","int",arr,0,"int",n-1);
    for(i=0;i<n;i+=1)
    {
        callout("print","int",arr[i]," ");
    }
    callout("print","\n");
    return;
}
