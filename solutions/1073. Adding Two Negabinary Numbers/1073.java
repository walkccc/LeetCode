class Solution {
  public int[] addNegabinary(int[] arr1, int[] arr2) {
    Deque<Integer> ans = new ArrayDeque<>();
    int carry = 0;
    int i = arr1.length - 1;
    int j = arr2.length - 1;

    while (carry != 0 || i >= 0 || j >= 0) {
      if (i >= 0)
        carry += arr1[i--];
      if (j >= 0)
        carry += arr2[j--];
      ans.addFirst(carry & 1);
      carry = -(carry >> 1);
    }

    while (ans.size() > 1 && ans.getFirst() == 0)
      ans.pollFirst();

    return ans.stream().mapToInt(Integer::intValue).toArray();
  }
}
