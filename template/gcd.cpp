// a is the larger number, b is the smaller number
int gcd(int a, int b){
    if(b==0)    return a;
    return gcd(b, a%b);
}