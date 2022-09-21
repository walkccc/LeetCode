class SmallestInfiniteSet {
 public:
  int popSmallest() {
    if (added.empty())
      return curr++;
    const int min = *begin(added);
    added.erase(begin(added));
    return min;
  }

  void addBack(int num) {
    if (num < curr)
      added.insert(num);
  }

 private:
  int curr = 1;
  set<int> added;
};
