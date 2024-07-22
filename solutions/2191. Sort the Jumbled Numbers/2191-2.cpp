class Solution {
 public:
  vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
    vector<int> ans;
    map<int, vector<int>> mappedToOriginalNums;

    for (const int num : nums)
      mappedToOriginalNums[getMapped(num, mapping)].push_back(num);

    for (const auto& [_, originalNums] : mappedToOriginalNums)
      ans.insert(ans.end(), originalNums.begin(), originalNums.end());

    return ans;
  }

 private:
  int getMapped(int num, const vector<int>& mapping) {
    string mapped;
    for (const char c : to_string(num))
      mapped += to_string(mapping[c - '0']);
    return stoi(mapped);
  }
};
