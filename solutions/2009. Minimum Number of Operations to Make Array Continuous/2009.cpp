class Solution {
 public:
  int minOperations(vector<int>& nums) {
    const int n = nums.size();
    int ans = n;

    ranges::sort(nums);
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
  int firstGreater(const vector<int>& A, int target) {
    return ranges::upper_bound(A, target) - A.begin();
  }
};
