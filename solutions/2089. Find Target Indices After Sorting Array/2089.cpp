class Solution {
 public:
  vector<int> targetIndices(vector<int>& nums, int target) {
    vector<int> ans;
    const int count = ranges::count(nums, target);
    int lessThan =
        ranges::count_if(nums, [&](int num) { return num < target; });

    for (int i = 0; i < count; ++i)
      ans.push_back(lessThan++);

    return ans;
  }
};
