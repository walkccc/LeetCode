class Solution {
 public:
  vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
    unordered_map<int, int> numToIndex;

    for (int i = 0; i < nums.size(); ++i)
      numToIndex[nums[i]] = i;

    for (const vector<int>& o : operations) {
      const int original = o[0];
      const int replaced = o[1];
      const int index = numToIndex[original];
      nums[index] = replaced;
      numToIndex.erase(original);
      numToIndex[replaced] = index;
    }

    return nums;
  }
};
