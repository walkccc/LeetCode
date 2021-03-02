class Solution {
  public int[] xorQueries(int[] arr, int[][] queries) {
    int[] ans = new int[queries.length];
    int[] xors = new int[arr.length + 1];

    for (int i = 0; i < arr.length; ++i)
      xors[i + 1] ^= xors[i] ^ arr[i];

    int i = 0;
    for (int[] query : queries)
      ans[i++] = xors[query[0]] ^ xors[query[1] + 1];

    return ans;
  }
}
