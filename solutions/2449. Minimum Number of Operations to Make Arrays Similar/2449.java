class Solution {
  public long makeSimilar(int[] nums, int[] target) {
    long ans = 0;
    // A[0] := even nums, A[1] := odd nums
    List<Integer>[] A = new List[] {new ArrayList<>(), new ArrayList<>()};
    // B[0] := even target, B[1] := odd nums
    List<Integer>[] B = new List[] {new ArrayList<>(), new ArrayList<>()};

    for (final int num : nums)
      A[num % 2].add(num);

    for (final int num : target)
      B[num % 2].add(num);

    Collections.sort(A[0]);
    Collections.sort(A[1]);
    Collections.sort(B[0]);
    Collections.sort(B[1]);

    for (int i = 0; i < 2; ++i)
      for (int j = 0; j < A[i].size(); ++j)
        ans += Math.abs(A[i].get(j) - B[i].get(j)) / 2;

    return ans / 2;
  }
}
