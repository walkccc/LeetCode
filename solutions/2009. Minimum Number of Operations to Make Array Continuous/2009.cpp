class Solution {
 public:
  int minOperations(vector<int>& nums) {
    const int n = nums.size();
    int ans = n;

    sort(begin(nums), end(nums));
    nums.erase(unique(begin(nums), end(nums)), end(nums));

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
    return upper_bound(begin(nums), end(nums), target) - begin(nums);
  }
};
