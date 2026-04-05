class Solution {
  public int kIncreasing(int[] arr, int k) {
    int ans = 0;

    for (int i = 0; i < k; ++i) {
      List<Integer> arr = new ArrayList<>();
      for (int j = i; j < arr.length; j += k)
        arr.add(arr[j]);
      ans += numReplaced(arr);
    }

    return ans;
  }

  private int numReplaced(List<Integer> arr) {
    List<Integer> tails = new ArrayList<>();
    for (final int a : arr)
      if (tails.isEmpty() || tails.get(tails.size() - 1) <= a)
        tails.add(a);
      else
        tails.set(firstGreater(tails, a), a);
    return arr.size() - tails.size();
  }

  private int firstGreater(List<Integer> arr, int target) {
    final int i = Collections.binarySearch(arr, target + 1);
    return i < 0 ? -i - 1 : i;
  }
}
