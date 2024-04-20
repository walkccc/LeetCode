class PhoneDirectory {
 public:
  PhoneDirectory(int maxNumbers) : next(maxNumbers) {
    for (int i = 0; i < maxNumbers - 1; ++i)
      next[i] = i + 1;
    next.back() = 0;
  }

  int get() {
    if (next[number] == -1)
      return -1;
    const int ans = number;
    number = next[number];
    next[ans] = -1;  // Mark as used.
    return ans;
  }

  bool check(int number) {
    return next[number] != -1;
  }

  void release(int number) {
    if (next[number] != -1)
      return;
    next[number] = this->number;
    this->number = number;
  }

 private:
  int number = 0;    // the current possible available number
  vector<int> next;  // the next available numbers
};
