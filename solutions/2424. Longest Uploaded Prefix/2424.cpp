class LUPrefix {
 public:
  LUPrefix(int n) {}

  void upload(int video) {
    seen.insert(video);
    while (seen.contains(longestPrefix + 1))
      ++longestPrefix;
  }

  int longest() {
    return longestPrefix;
  }

 private:
  unordered_set<int> seen;
  int longestPrefix = 0;
};
