class Solution {
  public long[] getDistances(int[] arr) {
    final int n = arr.length;
    long[] ans = new long[n];
    long[] prefix = new long[n];
    long[] suffix = new long[n];
    Map<Integer, List<Integer>> numToIndices = new HashMap<>();

    for (int i = 0; i < n; ++i) {
      numToIndices.putIfAbsent(arr[i], new ArrayList<>());
      numToIndices.get(arr[i]).add(i);
    }

    for (List<Integer> indices : numToIndices.values()) {
      for (int i = 1; i < indices.size(); ++i) {
        final int currIndex = indices.get(i);
        final int prevIndex = indices.get(i - 1);
        prefix[currIndex] += prefix[prevIndex] + i * (currIndex - prevIndex);
      }
      for (int i = indices.size() - 2; i >= 0; --i) {
        final int currIndex = indices.get(i);
        final int prevIndex = indices.get(i + 1);
        suffix[currIndex] += suffix[prevIndex] + (indices.size() - i - 1) * (prevIndex - currIndex);
      }
    }

    for (int i = 0; i < n; ++i)
      ans[i] = prefix[i] + suffix[i];

    return ans;
  }
}
