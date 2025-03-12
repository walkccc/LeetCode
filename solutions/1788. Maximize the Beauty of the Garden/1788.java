class Solution {
  public int maximumBeauty(int[] flowers) {
    int ans = Integer.MIN_VALUE;
    int prefix = 0;
    Map<Integer, Integer> flowerToPrefix = new HashMap<>();

    for (final int flower : flowers) {
      if (flowerToPrefix.containsKey(flower))
        ans = Math.max(ans, prefix - flowerToPrefix.get(flower) + flower * 2);
      prefix += Math.max(0, flower);
      flowerToPrefix.putIfAbsent(flower, prefix);
    }

    return ans;
  }
}
