class Solution {
 public:
  vector<int> cycleLengthQueries(int n, vector<vector<int>>& queries) {
    vector<int> ans;

    for (const vector<int>& query : queries) {
      ans.push_back(1);
      int a = query[0];
      int b = query[1];
      while (a != b) {
        if (a > b)
          a /= 2;
        else
          b /= 2;
        ++ans.back();
      }
    }

    return ans;
  }
};
