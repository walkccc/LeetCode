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

    sort(begin(filtered), end(filtered), [](const auto& a, const auto& b) {
      return a[1] == b[1] ? a[0] > b[0] : a[1] > b[1];
    });

    for (vector<int>& f : filtered) ans.push_back(f[0]);

    return ans;
  }
};
