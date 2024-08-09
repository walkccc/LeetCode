class Solution {
  public int oddEvenJumps(int[] arr) {
    final int n = arr.length;
    TreeMap<Integer, Integer> map = new TreeMap<>(); // {num: min index}
    // inc[i] := true if can reach arr[n - 1] from i using increasing jumps
    int[] inc = new int[n];
    // dec[i] := true if can reach arr[n - 1] from i using increasing jumps
    int[] dec = new int[n];

    map.put(arr[n - 1], n - 1);
    inc[n - 1] = 1;
    dec[n - 1] = 1;

    for (int i = n - 2; i >= 0; --i) {
      // the minimum value >= arr[i]
      Map.Entry<Integer, Integer> lo = map.ceilingEntry(arr[i]);
      // the maximum value <= arr[i]
      Map.Entry<Integer, Integer> hi = map.floorEntry(arr[i]);
      if (lo != null)
        inc[i] = dec[(int) lo.getValue()];
      if (hi != null)
        dec[i] = inc[(int) hi.getValue()];
      map.put(arr[i], i);
    }

    return Arrays.stream(inc).sum();
  }
}
