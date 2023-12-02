class Solution {
 public:
  long long fixedRatio(string s, int num1, int num2) {
    // Let x := the number of 0s and y := the number of 1s in the subarray.
    // We want x : y = num1 : num2, so our goal is to find number of subarrays
    // with x * num2 - y * num1 = 0. To achieve this, we can use a prefix count
    // map to record the count of the running x * num2 - y * num1. If the
    // running x * num2 - y * num1 = prefix, then add count[prefix] to the
    // `ans`.
    long long ans = 0;
    long long prefix = 0;
    unordered_map<long long, int> prefixCount{{0, 1}};

    for (const char c : s) {
      if (c == '0')
        prefix += num2;
      else  // c == '1'
        prefix -= num1;
      ans += prefixCount[prefix];
      ++prefixCount[prefix];
    }

    return ans;
  }
};
