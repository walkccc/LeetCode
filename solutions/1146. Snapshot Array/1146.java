class SnapshotArray {
  public SnapshotArray(int length) {
    snaps = new TreeMap[length];
    for (int i = 0; i < length; ++i) {
      snaps[i] = new TreeMap<>();
      snaps[i].put(0, 0);
    }
  }

  public void set(int index, int val) {
    snaps[index].put(snap_id, val);
  }

  public int snap() {
    return snap_id++;
  }

  public int get(int index, int snap_id) {
    return snaps[index].floorEntry(snap_id).getValue();
  }

  private TreeMap<Integer, Integer>[] snaps;
  private int snap_id = 0;
}
