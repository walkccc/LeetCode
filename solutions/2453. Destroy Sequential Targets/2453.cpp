class Solution {
 public:
  int destroyTargets(vector<int>& nums, int space) {
    int ans = INT_MAX;
    int maxCount = 0;
    unordered_map<int, int> count;

    for (const int num : nums)
      maxCount = max(maxCount, ++count[num % space]);

    for (const int num : nums)
      if (count[num % space] == maxCount)
        ans = min(ans, num);

    return ans;
  }
};
