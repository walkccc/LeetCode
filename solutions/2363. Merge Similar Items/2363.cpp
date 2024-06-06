class Solution {
 public:
  vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1,
                                        vector<vector<int>>& items2) {
    constexpr int kMax = 1000;
    vector<vector<int>> ans;
    vector<int> count(kMax + 1);

    for (const vector<int>& item : items1)
      count[item[0]] += item[1];

    for (const vector<int>& item : items2)
      count[item[0]] += item[1];

    for (int i = 1; i <= kMax; ++i)
      if (count[i])
        ans.push_back({i, count[i]});

    return ans;
  }
};
