class Solution {
  public List<Integer> pancakeSort(int[] arr) {
    List<Integer> ans = new ArrayList<>();

    for (int target = arr.length; target >= 1; --target) {
      int index = find(arr, target);
      reverse(arr, 0, index);
      reverse(arr, 0, target - 1);
      ans.add(index + 1);
      ans.add(target);
    }

    return ans;
  }

  private int find(int[] arr, int target) {
    for (int i = 0; i < arr.length; ++i)
      if (arr[i] == target)
        return i;
    throw new IllegalArgumentException();
  }

  private void reverse(int[] arr, int l, int r) {
    while (l < r)
      swap(arr, l++, r--);
  }

  private void swap(int[] arr, int l, int r) {
    int temp = arr[l];
    arr[l] = arr[r];
    arr[r] = temp;
  }
}
