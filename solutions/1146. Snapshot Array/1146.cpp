class SnapshotArray {
 public:
  SnapshotArray(int length) {
    map = vector<std::map<int, int>>(length);
    for (int i = 0; i < length; ++i) map[i][0] = 0;
  }

  void set(int index, int val) { map[index][snap_id] = val; }

  int snap() { return snap_id++; }

  int get(int index, int snap_id) {
    auto it = map[index].upper_bound(snap_id);
    return prev(it)->second;
  }

 private:
  vector<std::map<int, int>> map;
  int snap_id = 0;
};