class Solution {
  public int kIncreasing(int[] arr, int k) {
    int ans = 0;

    for (int i = 0; i < k; ++i) {
      List<Integer> A = new ArrayList<>();
      for (int j = i; j < arr.length; j += k)
        A.add(arr[j]);
      ans += numReplaced(A);
    }

    return ans;
  }

  private int numReplaced(List<Integer> A) {
    List<Integer> tail = new ArrayList<>();
    for (final int a : A)
      if (tail.isEmpty() || tail.get(tail.size() - 1) <= a)
        tail.add(a);
      else
        tail.set(firstGreater(tail, a), a);
    return A.size() - tail.size();
  }

  private int firstGreater(List<Integer> tail, int target) {
    int l = 0;
    int r = tail.size();
    while (l < r) {
      final int m = (l + r) / 2;
      if (tail.get(m) > target)
        r = m;
      else
        l = m + 1;
    }
    return l;
  }
}
