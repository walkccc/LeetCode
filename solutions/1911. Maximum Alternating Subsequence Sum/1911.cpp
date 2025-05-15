class Solution {
 public:
  long long maxAlternatingSum(vector<int>& nums) {
    long even = 0;  // the maximum alternating sum ending in an even index
    long odd = 0;   // the maximum alternating sum ending in an odd index

    for (const int num : nums) {
      even = max(even, odd + num);
      odd = even - num;
    }

    return even;
  }
};
