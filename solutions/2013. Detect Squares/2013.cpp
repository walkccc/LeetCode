class DetectSquares {
 public:
  void add(vector<int> point) {
    ++pointCount[hash(point[0], point[1])];
  }

  int count(vector<int> point) {
    const int x1 = point[0];
    const int y1 = point[1];
    int ans = 0;

    for (const auto& [hashed, count] : pointCount) {
      const int x3 = hashed >> 10;
      const int y3 = hashed & 1023;
      if (x1 != x3 && abs(x1 - x3) == abs(y1 - y3)) {
        const int p = hash(x1, y3);
        const int q = hash(x3, y1);
        if (pointCount.count(p) && pointCount.count(q))
          ans += count * pointCount[p] * pointCount[q];
      }
    }

    return ans;
  }

 private:
  unordered_map<int, int> pointCount;

  int hash(int i, int j) {
    return i << 10 | j;
  }
};
