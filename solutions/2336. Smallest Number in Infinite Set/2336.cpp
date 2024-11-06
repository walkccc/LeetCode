class SmallestInfiniteSet {
 public:
  int popSmallest() {
    if (added.empty())
      return curr++;
    const int mn = *added.begin();
    added.erase(added.begin());
    return mn;
  }

  void addBack(int num) {
    if (num < curr)
      added.insert(num);
  }

 private:
  int curr = 1;
  set<int> added;
};
