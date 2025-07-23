class Solution {
  public List<Integer> filterRestaurants(int[][] restaurants, int veganFriendly, int maxPrice,
                                         int maxDistance) {
    return Arrays.stream(restaurants)
        .filter(r -> r[2] >= veganFriendly && r[3] <= maxPrice && r[4] <= maxDistance)
        .sorted(Comparator.comparingInt((int[] r) -> - r[1]).thenComparingInt((int[] r) -> - r[0]))
        .map(r -> r[0])
        .collect(Collectors.toList());
  }
}
