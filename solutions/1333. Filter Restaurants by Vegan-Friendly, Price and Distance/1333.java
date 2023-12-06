class Solution {
  public List<Integer> filterRestaurants(int[][] restaurants, int veganFriendly, int maxPrice,
                                         int maxDistance) {
    return Arrays.stream(restaurants)
        .filter(r -> r[2] >= veganFriendly && r[3] <= maxPrice && r[4] <= maxDistance)
        .sorted((a, b) -> a[1] == b[1] ? b[0] - a[0] : b[1] - a[1])
        .map(i -> i[0])
        .collect(Collectors.toList());
  }
}
