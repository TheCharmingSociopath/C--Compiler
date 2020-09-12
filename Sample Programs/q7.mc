//Write a sorting program using Radix sort.

void countSort(int arr[], int n, int j){
    int out[n], i;
    for(i=0; i<10; i+=1){
        count[i] = 0;
    }
    for(i=0; i<n; i+=1){
        count[(arr[i]/j)%10]+=1;
    }
    for(i=1; i<10; i+=1){
        count[i] += count[i-1];
    }
    for(i=n-1; i>=0; i-=1){
        out[count[(arr[i]/j)%10]-1] = arr[i];
        count[(arr[i]/j)%10] -= 1;
    }
    for(i=0; i<n; i+=1){
        arr[i]=out[i];
    }
}
void radixSort(int n, int arr[]){
    int mx = arr[0], i;
    for(i=0; i<n; i+=1){
        if(arr[i] > mx){
            mx = arr[i];
        }
    }
    int j;
    for(j=1; mx/j>0; j*=10){
        callout("countSort","int",arr,"int",n,"int",j);
    }
}
void main(){
    int i, j, n;
    callout("print", "Enter n: ");
    n = callout("read", "int");
    int arr[n];
    for(i=0; i<n; i+=1){
        arr[i] = callout("read","int");
    }
    callout("radixSort","int",n,"int",arr);
    for(i=0; i<n; i+=1){
        callout("print","int",arr[i]," ");
    }
    callout("print","\n");
    return;
}
