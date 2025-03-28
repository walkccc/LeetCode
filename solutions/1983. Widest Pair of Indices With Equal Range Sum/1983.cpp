class Solution {
 public:
  int widestPairOfIndices(vector<int>& nums1, vector<int>& nums2) {
    int ans = 0;
    int prefix = 0;
    unordered_map<int, int> prefixToIndex{{0, -1}};

    for (int i = 0; i < nums1.size(); ++i) {
      prefix += nums1[i] - nums2[i];
      if (const auto it = prefixToIndex.find(prefix);
          it != prefixToIndex.cend())
        ans = max(ans, i - it->second);
      else
        prefixToIndex[prefix] = i;
    }

    return ans;
  }
};
