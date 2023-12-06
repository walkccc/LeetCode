class Solution {
 public:
  vector<int> sortEvenOdd(vector<int>& nums) {
    const int n = nums.size();
    vector<int> ans(n);
    vector<int> evenCount(101);
    vector<int> oddCount(101);

    for (int i = 0; i < n; ++i)
      if (i & 1)
        ++oddCount[nums[i]];
      else
        ++evenCount[nums[i]];

    int ansIndex = 0;
    for (int i = 1; i < 101; ++i)
      while (evenCount[i]--) {
        ans[ansIndex] = i;
        ansIndex += 2;
      }

    ansIndex = 1;
    for (int i = 100; i > 0; --i)
      while (oddCount[i]--) {
        ans[ansIndex] = i;
        ansIndex += 2;
      }

    return ans;
  }
};
