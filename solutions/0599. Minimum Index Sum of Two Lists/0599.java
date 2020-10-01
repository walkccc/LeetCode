class Solution {
  public String[] findRestaurant(String[] list1, String[] list2) {
    List<String> ans = new LinkedList<>();
    Map<String, Integer> restaurantToIndex = new HashMap<>();
    int minSum = Integer.MAX_VALUE;

    for (int i = 0; i < list1.length; ++i)
      restaurantToIndex.put(list1[i], i);

    for (int i = 0; i < list2.length; ++i) {
      if (restaurantToIndex.containsKey(list2[i])) {
        int sum = restaurantToIndex.get(list2[i]) + i;
        if (sum < minSum)
          ans.clear();
        if (sum <= minSum) {
          ans.add(list2[i]);
          minSum = sum;
        }
      }
    }

    return ans.toArray(new String[0]);
  }
}