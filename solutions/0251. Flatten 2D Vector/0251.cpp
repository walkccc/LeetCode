class Vector2D {
 public:
  Vector2D(vector<vector<int>>& vec) {
    for (const vector<int>& A : vec)
      for (const int a : A)
        this->vec.push_back(a);
  }

  int next() {
    return vec[i++];
  }

  bool hasNext() {
    return i < vec.size();
  }

 private:
  vector<int> vec;
  int i = 0;
};
