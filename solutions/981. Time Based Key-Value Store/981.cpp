struct T {
  string value;
  int timestamp;
};

class TimeMap {
 public:
  void set(string key, string value, int timestamp) {
    map[key].emplace_back(value, timestamp);
  }

  string get(string key, int timestamp) {
    if (!map.contains(key))
      return "";

    const vector<T>& A = map[key];
    int l = 0;
    int r = A.size();

    while (l < r) {
      const int m = (l + r) / 2;
      if (A[m].timestamp > timestamp)
        r = m;
      else
        l = m + 1;
    }

    return l == 0 ? "" : A[l - 1].value;
  }

 private:
  unordered_map<string, vector<T>> map;
};
