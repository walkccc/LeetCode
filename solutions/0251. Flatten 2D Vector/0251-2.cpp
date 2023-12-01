class Vector2D {
 public:
  Vector2D(vector<vector<int>>& v) {
    i = v.begin();
    iEnd = v.end();
  }

  int next() {
    moveIterator();
    return (*i)[j++];
  }

  bool hasNext() {
    moveIterator();
    return i != iEnd;
  }

 private:
  // (*i)[j] := the current pointed value
  vector<vector<int>>::iterator i, iEnd;
  int j = 0;

  void moveIterator() {
    while (i != iEnd && j == (*i).size())
      ++i, j = 0;
  }
};
