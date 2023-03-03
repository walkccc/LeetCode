class Solution {
 public:
  vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
    vector<int> ans;
    vector<int> prices;
    vector<int> maxBeautySoFar(items.size() + 1);

    sort(begin(items), end(items));

    for (const vector<int>& item : items)
      prices.push_back(item[0]);

    for (int i = 0; i < items.size(); ++i)
      maxBeautySoFar[i + 1] = max(maxBeautySoFar[i], items[i][1]);

    for (const int query : queries) {
      const int i =
          upper_bound(begin(prices), end(prices), query) - begin(prices);
      ans.push_back(maxBeautySoFar[i]);
    }

    return ans;
  }
};
