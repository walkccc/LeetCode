struct Item {
  int i;
  int j;
  int num;  // nums[i][j]
};

class Solution {
 public:
  vector<int> smallestRange(vector<vector<int>>& nums) {
    auto compare = [&](const Item& a, const Item& b) { return a.num > b.num; };
    priority_queue<Item, vector<Item>, decltype(compare)> pq(compare);
    int mini = INT_MAX;
    int maxi = INT_MIN;

    for (int i = 0; i < nums.size(); ++i) {
      const int num = nums[i][0];
      pq.push({i, 0, num});
      mini = min(mini, num);
      maxi = max(maxi, num);
    }

    int minRange = mini;
    int maxRange = maxi;

    while (pq.size() == nums.size()) {
      const auto [i, j, _] = pq.top();
      pq.pop();
      if (j + 1 < nums[i].size()) {
        pq.push({i, j + 1, nums[i][j + 1]});
        maxi = max(maxi, nums[i][j + 1]);
        mini = pq.top().num;
        if (maxi - mini < maxRange - minRange) {
          minRange = mini;
          maxRange = maxi;
        }
      }
    }

    return {minRange, maxRange};
  }
};
