class Vector2D {
 public:
  Vector2D(vector<vector<int>>& v) {
    i = begin(v);
    iEnd = end(v);
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
  // (*i)[j] := current pointed value
  vector<vector<int>>::iterator i, iEnd;
  int j = 0;

  void moveIterator() {
    while (i != iEnd && j == (*i).size())
      ++i, j = 0;
  }
};
