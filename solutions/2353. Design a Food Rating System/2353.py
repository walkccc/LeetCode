from sortedcontainers import SortedSet


class FoodRatings:
  def __init__(self, foods: list[str], cuisines: list[str], ratings: list[int]):
    self.cuisineToRatingAndFoods = collections.defaultdict(
        lambda: SortedSet(key=lambda x: (-x[0], x[1])))
    self.foodToCuisine = {}
    self.foodToRating = {}

    for food, cuisine, rating in zip(foods, cuisines, ratings):
      self.cuisineToRatingAndFoods[cuisine].add((rating, food))
      self.foodToCuisine[food] = cuisine
      self.foodToRating[food] = rating

  def changeRating(self, food: str, newRating: int) -> None:
    cuisine = self.foodToCuisine[food]
    oldRating = self.foodToRating[food]
    ratingAndFoods = self.cuisineToRatingAndFoods[cuisine]
    ratingAndFoods.remove((oldRating, food))
    ratingAndFoods.add((newRating, food))
    self.foodToRating[food] = newRating

  def highestRated(self, cuisine: str) -> str:
    return self.cuisineToRatingAndFoods[cuisine][0][1]
