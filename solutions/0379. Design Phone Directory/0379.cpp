class PhoneDirectory {
 public:
  /** Initialize your data structure here
      @param maxNumbers - The maximum numbers that can be stored in the phone
     directory. */
  PhoneDirectory(int maxNumbers) : next(maxNumbers) {
    for (int i = 0; i < maxNumbers - 1; ++i)
      next[i] = i + 1;
    next.back() = 0;
  }

  /** Provide a number which is not assigned to anyone.
      @return - Return an available number. Return -1 if none is available. */
  int get() {
    if (next[number] == -1)
      return -1;

    const int ans = number;
    number = next[number];
    next[ans] = -1;  // mark as used
    return ans;
  }

  /** Check if a number is available or not. */
  bool check(int number) {
    return next[number] != -1;
  }

  /** Recycle or release a number. */
  void release(int number) {
    if (next[number] != -1)
      return;

    next[number] = this->number;
    this->number = number;
  }

 private:
  int number = 0;    // current possible available number
  vector<int> next;  // next available number
};
