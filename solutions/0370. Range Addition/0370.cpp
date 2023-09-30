class Solution {
 public:
  vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
    vector<int> ans(length);
    int prefix = 0;

    for (const vector<int>& update : updates) {
      const int startIndex = update[0];
      const int endIndex = update[1];
      const int inc = update[2];
      ans[startIndex] += inc;
      if (endIndex + 1 < length)
        ans[endIndex + 1] -= inc;
    }

    for (int i = 0; i < length; ++i) {
      prefix += ans[i];
      ans[i] = prefix;
    }

    return ans;
  }
};
