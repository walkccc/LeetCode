class Solution {
 public:
  vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
    vector<int> ans(nums.size());
    // [[(num, index)]], where the difference between in each pair in each
    // `[(num, index)]` group <= `limit`
    vector<vector<pair<int, int>>> numAndIndexesGroups;

    for (const pair<int, int>& numAndIndex : getNumAndIndexes(nums))
      if (numAndIndexesGroups.empty() ||
          numAndIndex.first - numAndIndexesGroups.back().back().first > limit) {
        // Start a new group.
        numAndIndexesGroups.push_back({numAndIndex});
      } else {
        // Append to the existing group.
        numAndIndexesGroups.back().push_back(numAndIndex);
      }

    for (const vector<pair<int, int>>& numAndIndexesGroup :
         numAndIndexesGroups) {
      vector<int> sortedNums;
      vector<int> sortedIndices;
      for (const auto& [num, index] : numAndIndexesGroup) {
        sortedNums.push_back(num);
        sortedIndices.push_back(index);
      }
      ranges::sort(sortedIndices);
      for (int i = 0; i < sortedNums.size(); ++i)
        ans[sortedIndices[i]] = sortedNums[i];
    }

    return ans;
  }

 private:
  vector<pair<int, int>> getNumAndIndexes(const vector<int>& nums) {
    vector<pair<int, int>> numAndIndexes;
    for (int i = 0; i < nums.size(); ++i)
      numAndIndexes.emplace_back(nums[i], i);
    ranges::sort(numAndIndexes);
    return numAndIndexes;
  }
};
