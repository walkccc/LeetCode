class SnapshotArray {
 public:
  SnapshotArray(int length) {
    snaps = vector<map<int, int>>(length);
    for (map<int, int>& snap : snaps)
      snap[0] = 0;
  }

  void set(int index, int val) {
    snaps[index][snap_id] = val;
  }

  int snap() {
    return snap_id++;
  }

  int get(int index, int snap_id) {
    auto it = snaps[index].upper_bound(snap_id);
    return prev(it)->second;
  }

 private:
  vector<map<int, int>> snaps;
  int snap_id = 0;
};
