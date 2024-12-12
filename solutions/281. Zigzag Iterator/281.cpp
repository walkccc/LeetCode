class ZigzagIterator {
 public:
  ZigzagIterator(vector<int>& v1, vector<int>& v2) {
    if (!v1.empty())
      q.emplace(v1.begin(), v1.end());
    if (!v2.empty())
      q.emplace(v2.begin(), v2.end());
  }

  int next() {
    const auto [it, endIt] = q.front();
    q.pop();
    if (it + 1 != endIt)
      q.emplace(it + 1, endIt);
    return *it;
  }

  bool hasNext() {
    return !q.empty();
  }

 private:
  // {{ it, endIt }}
  queue<pair<vector<int>::iterator, vector<int>::iterator>> q;
};
