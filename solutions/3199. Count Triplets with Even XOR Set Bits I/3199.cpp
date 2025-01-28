class Solution {
 public:
  int tripletCount(vector<int>& a, vector<int>& b, vector<int>& c) {
    const auto [evenA, oddA] = getEvenOddBitCount(a);
    const auto [evenB, oddB] = getEvenOddBitCount(b);
    const auto [evenC, oddC] = getEvenOddBitCount(c);
    return evenA * oddB * oddC + oddA * evenB * oddC + oddA * oddB * evenC +
           evenA * evenB * evenC;
  }

 private:
  // Returns the count of numbers in the `nums` arrays that have even number of
  // ones and odd number of ones in their binary representation.
  pair<int, int> getEvenOddBitCount(const vector<int>& nums) {
    int even = 0;
    int odd = 0;
    for (const unsigned num : nums)
      if (popcount(num) % 2 == 0)
        ++even;
      else
        ++odd;
    return {even, odd};
  }
};
