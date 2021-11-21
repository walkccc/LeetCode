class Solution {
  public List<Integer> addToArrayForm(int[] A, int K) {
    List<Integer> ans = new LinkedList<>();

    for (int i = A.length - 1; i >= 0; --i) {
      ans.add(0, (A[i] + K) % 10);
      K = (A[i] + K) / 10;
    }

    while (K > 0) {
      ans.add(0, K % 10);
      K /= 10;
    }

    return ans;
  }
}
