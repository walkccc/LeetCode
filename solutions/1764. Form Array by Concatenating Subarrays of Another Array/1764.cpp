class Solution {
 public:
  bool canChoose(vector<vector<int>>& groups, vector<int>& nums) {
    int i = 0;  // groups' index
    int j = 0;  // nums' index

    while (i < groups.size() && j < nums.size())
      if (isMatch(groups[i], nums, j)) {
        j += groups[i].size();
        ++i;
      } else {
        ++j;
      }

    return i == groups.size();
  }

 private:
  // Returns true if group == nums[j..j + |group|].
  bool isMatch(const vector<int>& group, const vector<int>& nums, int j) {
    if (j + group.size() > nums.size())
      return false;
    for (int i = 0; i < group.size(); ++i)
      if (group[i] != nums[j + i])
        return false;
    return true;
  }
};
