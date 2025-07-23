class Solution {
  public List<List<Integer>> minimumAbsDifference(int[] arr) {
    List<List<Integer>> ans = new ArrayList<>();
    int mn = Integer.MAX_VALUE;

    Arrays.sort(arr);

    for (int i = 1; i < arr.length; ++i) {
      final int diff = arr[i] - arr[i - 1];
      if (diff < mn) {
        mn = diff;
        ans.clear();
      }
      if (diff == mn)
        ans.add(Arrays.asList(arr[i - 1], arr[i]));
    }

    return ans;
  }
}
