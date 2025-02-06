class Solution {
 public:
  int maximumTripletValue(vector<int>& nums) {
    const int n = nums.size();
    int ans = 0;
    vector<int> rightMax(n);  // rightMax[i] := max(nums[i + 1..n))
    set<int> leftSortedSet{nums[0]};

    for (int i = n - 2; i >= 0; --i)
      rightMax[i] = max(nums[i + 1], rightMax[i + 1]);

    for (int j = 1; j < n - 1; ++j) {
      if (const auto it = leftSortedSet.lower_bound(nums[j]);
          it != leftSortedSet.begin() && rightMax[j] > nums[j])
        ans = max(ans, *prev(it) - nums[j] + rightMax[j]);

      leftSortedSet.insert(nums[j]);
    }

    return ans;
  }
};
