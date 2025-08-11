class Vector2D {
 public:
  Vector2D(vector<vector<int>>& vec) {
    for (const vector<int>& arr : vec)
      for (const int a : arr)
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
