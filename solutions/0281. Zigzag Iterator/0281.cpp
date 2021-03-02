class ZigzagIterator {
 public:
  ZigzagIterator(vector<int>& v1, vector<int>& v2) {
    if (!v1.empty())
      q.push({begin(v1), end(v1)});
    if (!v2.empty())
      q.push({begin(v2), end(v2)});
  }

  int next() {
    const auto [it, endIt] = q.front();
    q.pop();
    if (it + 1 != endIt)
      q.push({it + 1, endIt});
    return *it;
  }

  bool hasNext() {
    return !q.empty();
  }

 private:
  // {{ it, endIt }}
  queue<pair<vector<int>::iterator, vector<int>::iterator>> q;
};
