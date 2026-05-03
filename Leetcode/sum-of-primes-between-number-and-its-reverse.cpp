class Solution {
public:
    int isPrime(int num) {
        if(num==1) return false;
        if(num==2) return true;
        if(num%2 == 0) return false;
        for(int i = 3; i*i <= num; i++) {
            if(num%i == 0) return false;
        }
        return true;
    }
    int reverse(int n) {
        int r = 0;
        while(n>0) {
            r = r*10 + n%10;
            n /= 10;
        }
        return r;
    }
    int sumOfPrimesInRange(int n) {
        int sum = 0;
        int rev = reverse(n);
        for(int i = min(n, rev); i <= max(n, rev); i++) {
            if(isPrime(i)) sum += i;
        }
        return sum;
    }
};
