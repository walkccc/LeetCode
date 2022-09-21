class Solution {
  public int oddEvenJumps(int[] A) {
    final int n = A.length;
    TreeMap<Integer, Integer> map = new TreeMap<>(); // {num: min index}
    int[] inc = new int[n]; // inc[i] := can reach A[n - 1] from i w/ inc jump
    int[] dec = new int[n]; // dec[i] := can reach A[n - 1] from i w/ dec jump

    map.put(A[n - 1], n - 1);
    inc[n - 1] = 1;
    dec[n - 1] = 1;

    for (int i = n - 2; i >= 0; --i) {
      Map.Entry<Integer, Integer> lo = map.ceilingEntry(A[i]); // min val >= A[i]
      Map.Entry<Integer, Integer> hi = map.floorEntry(A[i]);   // max val <= A[i]
      if (lo != null)
        inc[i] = dec[(int) lo.getValue()];
      if (hi != null)
        dec[i] = inc[(int) hi.getValue()];
      map.put(A[i], i);
    }

    return Arrays.stream(inc).sum();
  }
}
