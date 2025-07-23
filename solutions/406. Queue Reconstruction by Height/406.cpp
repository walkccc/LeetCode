class Solution {
 public:
  vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
    vector<vector<int>> ans;

    ranges::sort(people, ranges::less{}, [](const vector<int>& person) {
      const int h = person[0];
      const int k = person[1];
      return pair<int, int>{-h, k};
    });

    for (const vector<int>& person : people)
      ans.insert(ans.begin() + person[1], person);

    return ans;
  }
};
