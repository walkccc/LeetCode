class Solution {
 public:
  int findValidSplit(vector<int>& nums) {
    unordered_map<int, int> leftPrimeFactors;
    unordered_map<int, int> rightPrimeFactors;

    for (const int num : nums)
      for (const int primeFactor : getPrimeFactors(num))
        ++rightPrimeFactors[primeFactor];

    for (int i = 0; i < nums.size() - 1; ++i) {
      for (const int primeFactor : getPrimeFactors(nums[i])) {
        if (--rightPrimeFactors[primeFactor] == 0) {
          // rightPrimeFactors[primeFactor] == 0, so no need to track
          // leftPrimeFactors[primeFactor].
          rightPrimeFactors.erase(primeFactor);
          leftPrimeFactors.erase(primeFactor);
        } else {
          // Otherwise, need to track leftPrimeFactors[primeFactor].
          ++leftPrimeFactors[primeFactor];
        }
      }
      if (leftPrimeFactors.empty())
        return i;
    }

    return -1;
  }

 private:
  // Gets the prime factors under sqrt(10^6).
  vector<int> getPrimeFactors(int num) {
    vector<int> primeFactors;
    for (int divisor = 2; divisor <= min(1000, num); ++divisor)
      if (num % divisor == 0) {
        primeFactors.push_back(divisor);
        while (num % divisor == 0)
          num /= divisor;
      }
    // Handle the case that `num` contains a prime factor > 1000.
    if (num > 1)
      primeFactors.push_back(num);
    return primeFactors;
  }
};
