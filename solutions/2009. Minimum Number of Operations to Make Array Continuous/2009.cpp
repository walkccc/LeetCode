class Solution {
 public:
  int minOperations(vector<int>& nums) {
    const int n = nums.size();
    int ans = n;

    sort(nums.begin(), nums.end());
    nums.erase(unique(nums.begin(), nums.end()), nums.end());

    for (int i = 0; i < nums.size(); ++i) {
      const int start = nums[i];
      const int end = start + n - 1;
      const int index = firstGreater(nums, end);
      const int uniqueLength = index - i;
      ans = min(ans, n - uniqueLength);
    }

    return ans;
  }

 private:
  int firstGreater(const vector<int>& nums, int target) {
    return upper_bound(nums.begin(), nums.end(), target) - nums.begin();
  }
};
