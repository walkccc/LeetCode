class TwoSum {
 public:
  void add(int number) {
    ++count[number];
  }

  bool find(int value) {
    for (const auto& [key, freq] : count) {
      const int remain = value - key;
      if (key == remain && freq > 1)
        return true;
      if (key != remain && count.count(remain))
        return true;
    }

    return false;
  }

 private:
  unordered_map<int, int> count;
};
