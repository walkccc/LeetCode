class Solution {
  public List<Integer> pancakeSort(int[] A) {
    List<Integer> ans = new ArrayList<>();

    for (int target = A.length; target >= 1; --target) {
      int index = find(A, target);
      reverse(A, 0, index);
      reverse(A, 0, target - 1);
      ans.add(index + 1);
      ans.add(target);
    }

    return ans;
  }

  private int find(int[] A, int target) {
    for (int i = 0; i < A.length; ++i)
      if (A[i] == target)
        return i;
    throw new IllegalArgumentException();
  }

  private void reverse(int[] A, int l, int r) {
    while (l < r)
      swap(A, l++, r--);
  }

  private void swap(int[] A, int l, int r) {
    int temp = A[l];
    A[l] = A[r];
    A[r] = temp;
  }
}
