class Solution {
 public:
  // Similar to 1526. Minimum Number of Increments on Subarrays to Form a Target
  // Array
  long long minimumOperations(vector<int>& nums, vector<int>& target) {
    long ans = abs(nums[0] - target[0]);

    for (int i = 1; i < nums.size(); ++i) {
      const int currDiff = target[i] - nums[i];
      const int prevDiff = target[i - 1] - nums[i - 1];
      if (currDiff >= 0 && prevDiff >= 0)
        ans += max(0, currDiff - prevDiff);
      else if (currDiff <= 0 && prevDiff <= 0)
        ans += max(0, abs(currDiff) - abs(prevDiff));
      else
        ans += abs(currDiff);
    }

    return ans;
  }
};
