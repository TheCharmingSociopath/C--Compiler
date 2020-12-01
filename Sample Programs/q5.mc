void combUntil(int n, int arr, int r, int index, int data, int i)  
{  
    int j;
    if(index==r)  
    {  
        for (j = 0; j < r; j = j+1)  
        {
            callout("print",data[j]);  
        }
        callout("print", "\n");
        return;  
    }  
    if(i>=n)  
    {
        return;
    }  
    data[index] = arr[i];  
    callout("combUntil",n,arr[n],r,index + 1,data[r],i + 1);  
    callout("combUntil",n,arr[n],r,index,data[r],i+1);  
}  
void printComb(int n,int arr, int r)  
{   
    int data[r];  
    callout("combUntil", n, arr[n], r, 0,data[r], 0);  
}  
void main()  
{  
    int i;
    int n;
    int arr[n];
    callout("print", "n = ");
    n = callout("read", n);
    for(i=0;i< n;i=i+1)
    {
        arr[i] = i;
    }
    callout("printComb",n,arr[n],0);  
    return ;  
}  