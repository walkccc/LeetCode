class FoodRatings {
  public FoodRatings(String[] foods, String[] cuisines, int[] ratings) {
    for (int i = 0; i < foods.length; ++i) {
      cuisineToRatingAndFoods.putIfAbsent(
          cuisines[i],
          new TreeSet<>((a, b)
                            -> a.getKey().equals(b.getKey()) ? a.getValue().compareTo(b.getValue())
                                                             : b.getKey() - a.getKey()));
      cuisineToRatingAndFoods.get(cuisines[i]).add(new Pair<>(ratings[i], foods[i]));
      foodToCuisine.put(foods[i], cuisines[i]);
      foodToRating.put(foods[i], ratings[i]);
    }
  }

  public void changeRating(String food, int newRating) {
    final String cuisine = foodToCuisine.get(food);
    final int oldRating = foodToRating.get(food);
    TreeSet<Pair<Integer, String>> ratingAndFoods = cuisineToRatingAndFoods.get(cuisine);
    ratingAndFoods.remove(new Pair<>(oldRating, food));
    ratingAndFoods.add(new Pair<>(newRating, food));
    foodToRating.put(food, newRating);
  }

  public String highestRated(String cuisine) {
    return cuisineToRatingAndFoods.get(cuisine).first().getValue();
  }

  // {cuisine: {(rating, food)}}
  Map<String, TreeSet<Pair<Integer, String>>> cuisineToRatingAndFoods = new HashMap<>();
  Map<String, String> foodToCuisine = new HashMap<>();
  Map<String, Integer> foodToRating = new HashMap<>();
}
