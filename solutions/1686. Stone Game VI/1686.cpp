class Solution {
 public:
  int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
    const int n = aliceValues.size();
    vector<vector<int>> values;
    int a = 0;
    int b = 0;

    for (int i = 0; i < n; ++i)
      values.push_back({aliceValues[i], bobValues[i]});

    sort(begin(values), end(values), [](const auto& a, const auto& b) {
      return a[0] + a[1] > b[0] + b[1];
    });

    for (int i = 0; i < n; ++i)
      if (i % 2 == 0)
        a += values[i][0];
      else
        b += values[i][1];

    return a > b ? 1 : a < b ? -1 : 0;
  }
};
