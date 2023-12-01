class Solution {
  public List<Integer> arraysIntersection(int[] arr1, int[] arr2, int[] arr3) {
    List<Integer> ans = new ArrayList<>();
    int i = 0;
    int j = 0;
    int k = 0;

    while (i < arr1.length && j < arr2.length && k < arr3.length) {
      final int min = Math.min(arr1[i], Math.min(arr2[j], arr3[k]));
      if (arr1[i] == min && arr2[j] == min && arr3[k] == min) {
        ans.add(min);
        ++i;
        ++j;
        ++k;
      } else if (arr1[i] == min) {
        ++i;
      } else if (arr2[j] == min) {
        ++j;
      } else {
        ++k;
      }
    }

    return ans;
  }
}
