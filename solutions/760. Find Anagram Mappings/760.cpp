class Solution {
 public:
  vector<int> anagramMappings(vector<int>& nums1, vector<int>& nums2) {
    vector<int> ans;
    unordered_map<int, stack<int>> numToIndices;

    for (int i = 0; i < nums2.size(); ++i)
      numToIndices[nums2[i]].push(i);

    for (const int num : nums1)
      ans.push_back(numToIndices[num].top()), numToIndices[num].pop();

    return ans;
  }
};
