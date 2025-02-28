class Solution {
 public:
  int sumOfEncryptedInt(vector<int>& nums) {
    int ans = 0;

    for (const int num : nums) {
      int maxDigit = 0;
      int base = 0;
      for (int x = num; x > 0; x /= 10) {
        maxDigit = max(maxDigit, x % 10);
        base = base * 10 + 1;
      }
      ans += base * maxDigit;
    }

    return ans;
  }
};
