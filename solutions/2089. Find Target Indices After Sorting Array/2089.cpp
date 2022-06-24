class Solution {
 public:
  vector<int> targetIndices(vector<int>& nums, int target) {
    vector<int> ans;
    const int count = std::count(begin(nums), end(nums), target);
    int lessThan =
        count_if(begin(nums), end(nums), [&](int num) { return num < target; });

    for (int i = 0; i < count; ++i)
      ans.push_back(lessThan++);

    return ans;
  }
};
