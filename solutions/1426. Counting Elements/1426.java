class Solution {
  public int countElements(int[] arr) {
    int ans = 0;
    Map<Integer, Integer> count = new HashMap<>();

    for (final int a : arr)
      count.merge(a, 1, Integer::sum);

    for (Map.Entry<Integer, Integer> entry : count.entrySet())
      if (count.containsKey(entry.getKey() + 1))
        ans += entry.getValue();

    return ans;
  }
}
