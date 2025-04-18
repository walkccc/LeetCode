class FirstUnique {
 public:
  FirstUnique(vector<int>& nums) {
    for (const int num : nums)
      add(num);
  }

  int showFirstUnique() {
    return unique.empty() ? -1 : unique.front();
  }

  void add(int value) {
    const auto it = valueToIterator.find(value);
    if (it == valueToIterator.cend()) {
      unique.push_back(value);
      valueToIterator[value] = prev(unique.end());
    } else if (it->second != unique.end()) {
      // We have added this value before, and this is the second time we're
      // adding it. So, erase the value from `unique` and mark it as erased.
      unique.erase(it->second);
      valueToIterator[value] = unique.end();
    }
  }

 private:
  list<int> unique;
  unordered_map<int, list<int>::iterator> valueToIterator;
};
