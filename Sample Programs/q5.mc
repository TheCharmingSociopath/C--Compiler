//Write a program to print all combinations of {1,...,n} where n is given as an input.

void printComb(int arr[], int n, int r)  
{   
    int data[r];  
    callout("combUntil", "int", arr, "int", n, "int", r, 0, "int", data, 0);  
}  
void combUntil(int arr[], int n, int r, int index, int data[], int i)  
{  
    if(index==r)
    {  
        for (j = 0; j < r; j += 1)  
        {
            callout("print", "int", data[j], " ");  
        }
        callout("print", "\n");
        return;  
    }  
    if(i >= n)  
    {
        return;
    }  
    data[index] = arr[i];  
    callout("combUntil", "int", arr, "int", n, "int", r, "int", index + 1, "int", data, "int", i + 1);  
    callout("combUntil", "int", arr, "int", n, "int", r, "int", index, "int", data, "int", i+1);  
}  
void main()  
{  
    int i, n, arr[n];
    callout("print", "Enter n: ");
    n = callout("read", "int");
    for(i=0; i<n; i+=1)
    {
        arr[i] = i;
    }
    callout("printComb", "int", arr, "int", n, "int", r);  
    return ;  
} 
