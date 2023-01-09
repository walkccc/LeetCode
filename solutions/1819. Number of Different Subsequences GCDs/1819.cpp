class Solution {
 public:
  int countDifferentSubsequenceGCDs(vector<int>& nums) {
    const int maxNum = *max_element(begin(nums), end(nums));
    int ans = 0;
    // factor[i] := gcd of nums having factor i
    vector<int> factor(maxNum + 1);

    for (const int num : nums)
      for (int i = 1; i * i <= num; ++i)
        if (num % i == 0) {
          const int j = num / i;
          factor[i] = __gcd(factor[i], num);
          factor[j] = __gcd(factor[j], num);
        }

    for (int i = 1; i <= maxNum; ++i)
      if (factor[i] == i)
        ++ans;

    return ans;
  }
};
