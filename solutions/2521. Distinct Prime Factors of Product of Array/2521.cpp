class Solution {
 public:
  int distinctPrimeFactors(vector<int>& nums) {
    unordered_set<int> primes;

    for (const int num : nums)
      addPrimeFactors(primes, num);

    return primes.size();
  }

 private:
  void addPrimeFactors(unordered_set<int>& primes, int num) {
    for (int divisor = 2; divisor <= num; ++divisor)
      if (num % divisor == 0) {
        primes.insert(divisor);
        while (num % divisor == 0)
          num /= divisor;
      }
  }
};
