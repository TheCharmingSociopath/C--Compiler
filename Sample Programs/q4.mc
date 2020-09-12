//Enumerate all the Pythagorean triplets (x; y; z) where x; y; z are integers and x²+y² = z² and z<=100000000. Output the count at the end.


void main()
{
    int i, z = 100000000, total = 0, a, b, c = 0, m = 2;
    while(c < z)
    {
        for(i=1; i<m; i += 1)
        {
            a = m*m-i*i;
            b = 2*m*i;
            c = m*m+i*i;
            if(c > z)
            {
                break;
            }
            total += 1;
        }
        m += 1;
    }
    callout("print", "int", total);
    return;
}
