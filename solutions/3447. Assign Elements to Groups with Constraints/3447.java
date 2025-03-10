class Solution {
  public int[] assignElements(int[] groups, int[] elements) {
    int[] ans = new int[groups.length];
    Map<Integer, Integer> elementToMinIndex = new HashMap<>();

    for (int i = 0; i < elements.length; ++i)
      elementToMinIndex.putIfAbsent(elements[i], i);

    for (int i = 0; i < groups.length; ++i)
      ans[i] = getMinIndex(groups[i], elementToMinIndex);

    return ans;
  }

  private int getMinIndex(int num, Map<Integer, Integer> elementToMinIndex) {
    int res = Integer.MAX_VALUE;
    for (int i = 1; i * i <= num; ++i) {
      if (num % i != 0)
        continue;
      if (elementToMinIndex.containsKey(i))
        res = Math.min(res, elementToMinIndex.get(i));
      if (num / i != i && elementToMinIndex.containsKey(num / i))
        res = Math.min(res, elementToMinIndex.get(num / i));
    }
    return res == Integer.MAX_VALUE ? -1 : res;
  }
}
