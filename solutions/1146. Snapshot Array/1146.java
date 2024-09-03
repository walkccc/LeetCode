class SnapshotArray {
  public SnapshotArray(int length) {
    snaps = new List[length];
    for (int i = 0; i < length; ++i) {
      snaps[i] = new ArrayList<>();
      snaps[i].add(new int[] {0, 0});
    }
  }

  public void set(int index, int val) {
    int[] snap = snaps[index].get(snaps[index].size() - 1);
    if (snap[0] == snap_id)
      snap[1] = val;
    else
      snaps[index].add(new int[] {snap_id, val});
  }

  public int snap() {
    return snap_id++;
  }

  public int get(int index, int snap_id) {
    int i = Collections.binarySearch(snaps[index], new int[] {snap_id, 0},
                                     (a, b) -> Integer.compare(a[0], b[0]));
    if (i < 0)
      i = -i - 2;
    return snaps[index].get(i)[1];
  }

  private List<int[]>[] snaps;
  private int snap_id = 0;
}
