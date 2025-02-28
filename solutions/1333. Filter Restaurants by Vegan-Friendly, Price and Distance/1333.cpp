class Solution {
 public:
  vector<int> filterRestaurants(vector<vector<int>>& restaurants,
                                int veganFriendly, int maxPrice,
                                int maxDistance) {
    vector<int> ans;
    vector<vector<int>> filtered;

    for (vector<int>& restaurant : restaurants)
      if (restaurant[2] >= veganFriendly && restaurant[3] <= maxPrice &&
          restaurant[4] <= maxDistance)
        filtered.push_back(restaurant);

    ranges::sort(filtered, [](const vector<int>& a, const vector<int>& b) {
      return a[1] == b[1] ? a[0] > b[0] : a[1] > b[1];
    });

    for (const vector<int>& f : filtered)
      ans.push_back(f[0]);

    return ans;
  }
};
