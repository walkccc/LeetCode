class Solution {
 public:
  long long maxSpending(vector<vector<int>>& values) {
    const int m = values.size();
    const int n = values[0].size();
    long long ans = 0;
    long long d = 1;
    vector<int> items;

    for (const vector<int>& shop : values)
      for (const int item : shop)
        items.push_back(item);

    ranges::sort(items);

    for (const int item : items)
      ans += item * d++;

    return ans;
  }
};
