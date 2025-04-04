class Solution {
 public:
  int smallestValue(int n) {
    int primeSum = getPrimeSum(n);
    while (n != primeSum) {
      n = primeSum;
      primeSum = getPrimeSum(n);
    }
    return n;
  }

 private:
  int getPrimeSum(int n) {
    int primeSum = 0;
    for (int i = 2; i <= n; ++i)
      while (n % i == 0) {
        n /= i;
        primeSum += i;
      }
    return primeSum;
  }
};
