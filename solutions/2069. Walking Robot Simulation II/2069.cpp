class Robot {
 public:
  Robot(int width, int height) {
    pos.push_back({{0, 0}, "South"});
    for (int i = 1; i < width; ++i)
      pos.push_back({{i, 0}, "East"});
    for (int j = 1; j < height; ++j)
      pos.push_back({{width - 1, j}, "North"});
    for (int i = width - 2; i >= 0; --i)
      pos.push_back({{i, height - 1}, "West"});
    for (int j = height - 2; j > 0; --j)
      pos.push_back({{0, j}, "South"});
  }

  void step(int num) {
    isOrigin = false;
    i = (i + num) % pos.size();
  }

  vector<int> getPos() {
    return pos[i].first;
  }

  string getDir() {
    return isOrigin ? "East" : pos[i].second;
  }

 private:
  bool isOrigin = true;
  int i = 0;
  vector<pair<vector<int>, string>> pos;
};
