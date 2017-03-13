
//====sieve of Eratosthenes====

#define MAX 1000000
bool isprime[MAX];

void makePrime(){
    memset(isprime, 1, sizeof(isprime));
    isprime[0]=isprime[1]=false;
    for(int i = 2; i<=sqrt(MAX); ++i){
        if(isprime[i]){
            for(int j=i*i; j<MAX; j+=i){
                isprime[j]=false;
            }
        }
    }
}

//====6n+-1 Method====
#define MAX 1000000
vector<int> prime;

bool isPrime(int n){
    double sqrtN = sqrt(n);
    for(int i=0; prime[i]<=sqrtN; ++i){
        if(n%prime[i] == 0)
            return false;
    }
    return true;
}

void makePrime(){
    prime.push_back(2);
    prime.push_back(3);
    for(int i=5, gap=2; i<MAX; i+=gap, gap=6-gap){
        if(isPrime(i))
            prime.push_back(i);
    }
}