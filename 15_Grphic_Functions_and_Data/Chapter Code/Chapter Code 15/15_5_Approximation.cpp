int factorial(int n){
    int r = 1;
    while(n>r){
        r*=n;
        n--;
    }
    return r;
}

double term(double x, int n) {
    return pow(x,n)/factorial(n);
}


double expe(double x, int) // sum of n terms for x 
{
    double sum = 0;
    for(int i =0; i<n;++i) 
        sum+=term(x,i);
    return sum;
}
