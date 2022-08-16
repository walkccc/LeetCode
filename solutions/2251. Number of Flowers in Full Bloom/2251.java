class Solution {
  public int[] fullBloomFlowers(int[][] flowers, int[] persons) {
    int[] ans = new int[persons.length];
    List<Integer> starts = new ArrayList<>();
    List<Integer> ends = new ArrayList<>();

    for (int[] f : flowers) {
      starts.add(f[0]);
      ends.add(f[1]);
    }

    Collections.sort(starts);
    Collections.sort(ends);

    for (int i = 0; i < persons.length; ++i) {
      final int started = firstGreater(starts, persons[i]);
      final int ended = firstGreaterEqual(ends, persons[i]);
      ans[i] = started - ended;
    }

    return ans;
  }

  // find the first index l s.t A.get(l) > target
  // return A.size() if can't find
  private int firstGreater(List<Integer> A, int target) {
    int l = 0;
    int r = A.size();
    while (l < r) {
      final int m = (l + r) / 2;
      if (A.get(m) > target)
        r = m;
      else
        l = m + 1;
    }
    return l;
  }

  // find the first index l s.t A.get(l) >= target
  // return A.size() if can't find
  private int firstGreaterEqual(List<Integer> A, int target) {
    int l = 0;
    int r = A.size();
    while (l < r) {
      final int m = (l + r) / 2;
      if (A.get(m) >= target)
        r = m;
      else
        l = m + 1;
    }
    return l;
  }
}
