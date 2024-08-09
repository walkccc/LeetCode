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

  private int firstGreater(List<Integer> A, int target) {
    final int i = Collections.binarySearch(A, target + 1);
    return i < 0 ? -i - 1 : i;
  }
}
