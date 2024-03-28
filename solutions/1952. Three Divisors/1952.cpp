class Solution {
 public:
  bool isThree(int n) {
    if (n == 1)
      return false;
    // The numbers with exactly three divisors are perfect squares of a prime
    // number.
    const int root = sqrt(n);
    return root * root == n && isPrime(root);
  }

 private:
  bool isPrime(int num) {
    for (int i = 2; i <= sqrt(num); ++i)
      if (num % i == 0)
        return false;
    return true;
  }
};
