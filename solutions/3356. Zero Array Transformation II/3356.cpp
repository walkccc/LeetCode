class Solution {
 public:
  int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
    vector<int> line(nums.size() + 1);
    int decrement = 0;
    int k = 0;

    for (int i = 0; i < nums.size(); ++i) {
      while (decrement + line[i] < nums[i]) {
        if (k == queries.size())
          return -1;
        const int l = queries[k][0];
        const int r = queries[k][1];
        const int val = queries[k][2];
        ++k;
        if (r < i)
          continue;
        line[max(l, i)] += val;
        line[r + 1] -= val;
      }
      decrement += line[i];
    }

    return k;
  }
};
