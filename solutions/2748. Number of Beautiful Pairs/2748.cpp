class Solution {
 public:
  int countBeautifulPairs(vector<int>& nums) {
    int ans = 0;

    for (int i = 0; i < nums.size(); ++i)
      for (int j = i + 1; j < nums.size(); ++j)
        if (__gcd(firstDigit(nums[i]), lastDigit(nums[j])) == 1)
          ++ans;

    return ans;
  }

 private:
  int firstDigit(int num) {
    return to_string(num)[0] - '0';
  }

  int lastDigit(int num) {
    return num % 10;
  }
};
