class Vector2D {
 public:
  Vector2D(vector<vector<int>>& v) {
    for (const auto& arr : v)
      for (const int a : arr)
        vec.push_back(a);
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
