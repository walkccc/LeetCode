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
    pairs.push_back({key, value});
  }

  int get(int key) {
    const auto& pairs = lists[key % kSize];
    for (const auto& [k, v] : pairs)
      if (k == key)
        return v;
    return -1;
  }

  void remove(int key) {
    auto& pairs = lists[key % kSize];
    for (auto it = begin(pairs); it != end(pairs); ++it)
      if (it->first == key) {
        pairs.erase(it);
        return;
      }
  }

 private:
  const int kSize = 10000;
  vector<list<pair<int, int>>> lists;
};