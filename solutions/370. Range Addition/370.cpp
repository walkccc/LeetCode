class Solution {
 public:
  vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
    vector<int> ans;
    vector<int> line(length);
    int prefix = 0;

    for (const vector<int>& update : updates) {
      const int start = update[0];
      const int end = update[1];
      const int inc = update[2];
      line[start] += inc;
      if (end + 1 < length)
        line[end + 1] -= inc;
    }

    for (const int diff : line) {
      prefix += diff;
      ans.push_back(prefix);
    }

    return ans;
  }
};
