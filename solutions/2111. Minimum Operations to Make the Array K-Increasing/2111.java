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
    List<Integer> tails = new ArrayList<>();
    for (final int a : A)
      if (tails.isEmpty() || tails.get(tails.size() - 1) <= a)
        tails.add(a);
      else
        tails.set(firstGreater(tails, a), a);
    return A.size() - tails.size();
  }

  private int firstGreater(List<Integer> A, int target) {
    final int i = Collections.binarySearch(A, target + 1);
    return i < 0 ? -i - 1 : i;
  }
}
