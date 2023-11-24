class Solution {
 public:
  long long maxAlternatingSum(vector<int>& nums) {
    long even = 0;  // max alternating sum ending with a even index
    long odd = 0;   // max alternating sum ending with a odd index

    for (const int num : nums) {
      even = max(even, odd + num);
      odd = even - num;
    }

    return even;
  }
};
