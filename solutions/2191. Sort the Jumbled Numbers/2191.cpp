class Solution {
 public:
  vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
    vector<int> ans;
    vector<tuple<int, int, int>> A;  // (mapped, index, num)

    for (int i = 0; i < nums.size(); ++i)
      A.emplace_back(getMapped(nums[i], mapping), i, nums[i]);

    ranges::sort(A);

    for (const auto& [_, i, num] : A)
      ans.push_back(num);

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
