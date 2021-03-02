class TimeMap {
 public:
  void set(string key, string value, int timestamp) {
    map[key][timestamp] = value;
  }

  string get(string key, int timestamp) {
    auto it = map[key].upper_bound(timestamp);
    return it == begin(map[key]) ? "" : prev(it)->second;
  }

 private:
  unordered_map<string, std::map<int, string>> map;
};
