class Solution {
  public int minSumOfLengths(int[] arr, int target) {
    int ans = Integer.MAX_VALUE;
    int leftLength = Integer.MAX_VALUE;
    int prefix = 0;
    Map<Integer, Integer> prefixToIndex = new HashMap<>();
    prefixToIndex.put(0, -1);

    for (int i = 0; i < arr.length; ++i) {
      prefix += arr[i];
      prefixToIndex.put(prefix, i);
    }

    prefix = 0;

    for (int i = 0; i < arr.length; ++i) {
      prefix += arr[i];
      if (prefixToIndex.containsKey(prefix - target))
        leftLength = Math.min(leftLength, i - prefixToIndex.get(prefix - target));
      if (leftLength < Integer.MAX_VALUE)
        if (prefixToIndex.containsKey(prefix + target))
          ans = Math.min(ans, leftLength + prefixToIndex.get(prefix + target) - i);
    }

    return ans == Integer.MAX_VALUE ? -1 : ans;
  }
}
