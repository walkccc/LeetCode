class Solution {
 public:
  vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
    vector<vector<int>> ans;

    ranges::sort(people, [](const vector<int>& a, const vector<int>& b) {
      return a[0] == b[0] ? a[1] < b[1] : a[0] > b[0];
    });

    for (const vector<int>& p : people)
      ans.insert(ans.begin() + p[1], p);

    return ans;
  }
};
