class Solution {
 public:
  vector<int> smallestTrimmedNumbers(vector<string>& nums,
                                     vector<vector<int>>& queries) {
    vector<int> ans;
    for (const vector<int>& query : queries)
      ans.push_back(getKSmallestIndex(nums, query[0], query[1]));
    return ans;
  }

 private:
  int getKSmallestIndex(const vector<string>& nums, int k, int trim) {
    const int startIndex = nums[0].length() - trim;
    vector<pair<string, int>> trimmed;  // (num, index)

    for (int i = 0; i < nums.size(); ++i) {
      const string& num = nums[i];
      trimmed.push_back({num.substr(startIndex), i});
    }

    ranges::sort(trimmed);
    return trimmed[k - 1].second;
  }
};
