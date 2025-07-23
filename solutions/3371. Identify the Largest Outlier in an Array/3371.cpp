class Solution {
 public:
  int getLargestOutlier(vector<int>& nums) {
    const int sum = accumulate(nums.begin(), nums.end(), 0);
    int ans = INT_MIN;
    unordered_map<int, int> count;

    for (const int num : nums)
      ++count[num];

    for (const int num : nums) {
      const int withoutNum = sum - num;
      if (withoutNum % 2 == 0) {
        const int specialSum = withoutNum / 2;  // the sum of special numbers
        if (count[specialSum] > (num == specialSum ? 1 : 0))
          ans = max(ans, num);
      }
    }

    return ans;
  }
};
