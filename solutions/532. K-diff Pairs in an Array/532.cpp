class Solution {
 public:
  int findPairs(vector<int>& nums, int k) {
    int ans = 0;
    unordered_map<int, int> numToIndex;

    for (int i = 0; i < nums.size(); ++i)
      numToIndex[nums[i]] = i;

    for (int i = 0; i < nums.size(); ++i) {
      const int target = nums[i] + k;
      if (const auto it = numToIndex.find(target);
          it != numToIndex.cend() && it->second != i) {
        ++ans;
        numToIndex.erase(target);
      }
    }

    return ans;
  }
};
