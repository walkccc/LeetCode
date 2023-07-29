class MyHashMap {
 public:
  /** Initialize your data structure here. */
  MyHashMap() : lists(kSize) {}

  /** value will always be non-negative. */
  void put(int key, int value) {
    auto& pairs = lists[key % kSize];
    for (auto& [k, v] : pairs)
      if (k == key) {
        v = value;
        return;
      }
    pairs.emplace_back(key, value);
  }

  /** Returns the value to which the specified key is mapped, or -1 if this map
   * contains no mapping for the key */
  int get(int key) {
    const list<pair<int, int>>& pairs = lists[key % kSize];
    for (const auto& [k, v] : pairs)
      if (k == key)
        return v;
    return -1;
  }

  /** Removes the mapping of the specified value key if this map contains a
   * mapping for the key */
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
  vector<list<pair<int, int>>> lists;  // Each slot store (key, value) list
};
