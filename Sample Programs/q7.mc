//Write a sorting program using Radix sort.

void countSort(int n,int arr,int j){
    int count[n];
    int out[n];
    int i;
    for(i=0;i< 10;i=i+1){
        count[i] = 0;
    }
    for(i=0;i< n;i=i+1){
        count[(arr[i]/j)%10] = count[(arr[i]/j)%10] + 1;
    }
    for(i=1;i< 10;i=i+1){
        count[i] = count[i] + count[i-1];
    }
    for(i=n-1;i>=0;i=i-1){
        out[count[(arr[i]/j)%10]-1] = arr[i];
        count[(arr[i]/j)%10] = count[(arr[i]/j)%10] - 1;
    }
    for(i=0;i< n;i = i + 1){
        arr[i]=out[i];
    }
}
void radixSort(int n,int arr){
    int mx = arr[0];
    int i;
    for(i=0;i< n;i = i + 1){
        if(arr[i] > mx){
            mx = arr[i];
        }
    }
    int j;
    for(j=1;mx/j>0;j = j * 10){
        callout("countSort",n,arr[n],j);
    }
}
void main(){
    int i;
    int j;
    int n;
    n = callout("read", n);
    int arr[n];
    for(i=0;i< n;i = i + 1){
        arr[i] = callout("read",arr[i]);
    }
    callout("radixSort",n,arr[n]);
    for(i=0;i< n;i = i + 1){
        callout("print",arr[i]);
    }
    callout("print","\n");
    return;
}
