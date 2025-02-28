class Solution {
  public long makeSubKSumEqual(int[] arr, int k) {
    // If the sum of each subarray of length k is equal, then `arr` must have a
    // repeated pattern of size k. e.g. arr = [1, 2, 3, ...] and k = 3, to have
    // sum([1, 2, 3)] == sum([2, 3, x]), x must be 1. Therefore, arr[i] ==
    // arr[(i + k) % n] for every i.
    final int n = arr.length;
    long ans = 0;
    boolean[] seen = new boolean[n];

    for (int i = 0; i < n; ++i) {
      List<Integer> groups = new ArrayList<>();
      int j = i;
      while (!seen[j]) {
        groups.add(arr[j]);
        seen[j] = true;
        j = (j + k) % n;
      }
      Collections.sort(groups);
      for (final int num : groups)
        ans += Math.abs(num - groups.get(groups.size() / 2));
    }

    return ans;
  }
}
