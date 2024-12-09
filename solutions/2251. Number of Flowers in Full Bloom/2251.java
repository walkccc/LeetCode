class Solution {
  public int[] fullBloomFlowers(int[][] flowers, int[] persons) {
    int[] ans = new int[persons.length];
    List<Integer> starts = new ArrayList<>();
    List<Integer> ends = new ArrayList<>();

    for (int[] flower : flowers) {
      starts.add(flower[0]);
      ends.add(flower[1]);
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
