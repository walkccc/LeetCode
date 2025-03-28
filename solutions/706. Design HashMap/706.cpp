class MyHashMap {
 public:
  MyHashMap() : lists(kSize) {}

  void put(int key, int value) {
    auto& pairs = lists[key % kSize];
    for (auto& [k, v] : pairs)
      if (k == key) {
        v = value;
        return;
      }
    pairs.emplace_back(key, value);
  }

  int get(int key) {
    const list<pair<int, int>>& pairs = lists[key % kSize];
    for (const auto& [k, v] : pairs)
      if (k == key)
        return v;
    return -1;
  }

  void remove(int key) {
    auto& pairs = lists[key % kSize];
    for (auto it = pairs.begin(); it != pairs.end(); ++it)
      if (it->first == key) {
        pairs.erase(it);
        return;
      }
  }

 private:
  static constexpr int kSize = 10000;
  // Each slot stores the (key, value) list.
  vector<list<pair<int, int>>> lists;
};
