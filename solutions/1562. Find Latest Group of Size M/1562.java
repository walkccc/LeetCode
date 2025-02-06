class Solution {
  public int findLatestStep(int[] arr, int m) {
    if (arr.length == m)
      return arr.length;

    int ans = -1;
    int step = 0;
    // sizes[i] := the size of the group starting from i or ending in i
    // (1-indexed)
    int[] sizes = new int[arr.length + 2];

    for (final int i : arr) {
      ++step;
      // In the previous step, there exists a group with a size of m.
      if (sizes[i - 1] == m || sizes[i + 1] == m)
        ans = step - 1;
      final int head = i - sizes[i - 1];
      final int tail = i + sizes[i + 1];
      sizes[head] = tail - head + 1;
      sizes[tail] = tail - head + 1;
    }

    return ans;
  }
}
