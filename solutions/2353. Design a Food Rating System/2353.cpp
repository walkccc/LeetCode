class FoodRatings {
 public:
  FoodRatings(vector<string>& foods, vector<string>& cuisines,
              vector<int>& ratings) {
    for (int i = 0; i < foods.size(); ++i) {
      cuisineToRatingAndFoods[cuisines[i]].insert({-ratings[i], foods[i]});
      foodToCuisine[foods[i]] = cuisines[i];
      foodToRating[foods[i]] = ratings[i];
    }
  }

  void changeRating(string food, int newRating) {
    const string cuisine = foodToCuisine[food];
    const int oldRating = foodToRating[food];
    auto& ratingAndFoods = cuisineToRatingAndFoods[cuisine];
    ratingAndFoods.erase({-oldRating, food});
    ratingAndFoods.insert({-newRating, food});
    foodToRating[food] = newRating;
  }

  string highestRated(string cuisine) {
    return cuisineToRatingAndFoods[cuisine].begin()->second;
  }

 private:
  // {cuisine: {(-rating, food)}} stores negative rating for smarter comparison
  unordered_map<string, set<pair<int, string>>> cuisineToRatingAndFoods;
  unordered_map<string, string> foodToCuisine;
  unordered_map<string, int> foodToRating;
};
