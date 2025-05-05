class Solution {
  public List<Integer> arraysIntersection(int[] arr1, int[] arr2, int[] arr3) {
    List<Integer> ans = new ArrayList<>();
    int i = 0;
    int j = 0;
    int k = 0;

    while (i < arr1.length && j < arr2.length && k < arr3.length) {
      final int mn = Math.min(arr1[i], Math.min(arr2[j], arr3[k]));
      if (arr1[i] == mn && arr2[j] == mn && arr3[k] == mn) {
        ans.add(mn);
        ++i;
        ++j;
        ++k;
      } else if (arr1[i] == mn) {
        ++i;
      } else if (arr2[j] == mn) {
        ++j;
      } else {
        ++k;
      }
    }

    return ans;
  }
}
