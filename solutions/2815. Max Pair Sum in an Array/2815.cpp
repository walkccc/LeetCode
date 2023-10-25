class Solution {
 public:
  int maxSum(vector<int>& nums) {
    int ans = 0;
    // maxNum[i] := max num we met so far with max digit i
    vector<int> maxNum(10);

    for (const int num : nums) {
      const int d = getMaxDigit(num);
      if (maxNum[d] > 0)
        ans = max(ans, num + maxNum[d]);
      maxNum[d] = max(maxNum[d], num);
    }

    return ans == 0 ? -1 : ans;
  }

 private:
  int getMaxDigit(int num) {
    int maxDigit = 0;
    while (num > 0) {
      maxDigit = max(maxDigit, num % 10);
      num /= 10;
    }
    return maxDigit;
  }
};
