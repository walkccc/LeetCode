class Solution {
 public:
  bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
    vector<int> line(nums.size() + 1);
    int decrement = 0;

    for (const vector<int>& query : queries) {
      const int l = query[0];
      const int r = query[1];
      ++line[l];
      --line[r + 1];
    }

    for (int i = 0; i < nums.size(); ++i) {
      decrement += line[i];
      if (decrement < nums[i])
        return false;
    }

    return true;
  }
};
