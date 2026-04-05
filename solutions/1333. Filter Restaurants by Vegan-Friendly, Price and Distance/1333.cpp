class Solution {
 public:
  vector<int> filterRestaurants(vector<vector<int>>& restaurants,
                                int veganFriendly, int maxPrice,
                                int maxDistance) {
    vector<int> ans;
    vector<vector<int>> filteredRestaurants;

    for (const vector<int>& restaurant : restaurants)
      if (restaurant[2] >= veganFriendly && restaurant[3] <= maxPrice &&
          restaurant[4] <= maxDistance)
        filteredRestaurants.push_back(restaurant);

    ranges::sort(filteredRestaurants, ranges::less{},
                 [](const vector<int>& restaurant) {
      const int rating = restaurant[1];
      const int id = restaurant[0];
      return pair<int, int>{-rating, -id};
    });

    for (const vector<int>& restaurant : filteredRestaurants)
      ans.push_back(restaurant[0]);

    return ans;
  }
};
