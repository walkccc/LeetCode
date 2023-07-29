class Solution {
  public int shareCandies(int[] candies, int k) {
    int ans = 0;
    Map<Integer, Integer> count = new HashMap<>();

    for (final int candy : candies)
      count.merge(candy, 1, Integer::sum);

    int unique = count.size();

    for (int i = 0; i < candies.length; ++i) {
      if (count.merge(candies[i], -1, Integer::sum) == 0) {
        count.remove(candies[i]);
        --unique;
      }
      if (i >= k) {
        count.merge(candies[i - k], 1, Integer::sum);
        if (count.get(candies[i - k]) == 1)
          ++unique;
      }
      if (i >= k - 1)
        ans = Math.max(ans, unique);
    }

    return ans;
  }
}
