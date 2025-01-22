class Solution {
  public String[] findRestaurant(String[] list1, String[] list2) {
    List<String> ans = new LinkedList<>();
    Map<String, Integer> restaurantToIndex = new HashMap<>();
    int minSum = Integer.MAX_VALUE;

    for (int i = 0; i < list1.length; ++i)
      restaurantToIndex.put(list1[i], i);

    for (int i = 0; i < list2.length; ++i) {
      final String restaurant = list2[i];
      if (restaurantToIndex.containsKey(restaurant)) {
        final int sum = restaurantToIndex.get(restaurant) + i;
        if (sum < minSum) {
          minSum = sum;
          ans.clear();
          ans.add(restaurant);
        } else if (sum == minSum) {
          ans.add(restaurant);
        }
      }
    }

    return ans.toArray(new String[0]);
  }
}
