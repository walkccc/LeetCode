class RandomizedSet {
 public:
  /** Inserts a value to the set. Returns true if the set did not already
   * contain the specified element. */
  bool insert(int val) {
    if (valToIndex.count(val))
      return false;

    valToIndex[val] = vals.size();
    vals.push_back(val);
    return true;
  }

  /** Removes a value from the set. Returns true if the set contained the
   * specified element. */
  bool remove(int val) {
    if (!valToIndex.count(val))
      return false;

    const int index = valToIndex[val];
    // following two lines order are important when vals.size() == 1
    valToIndex[vals.back()] = index;
    valToIndex.erase(val);
    vals[index] = vals.back();
    vals.pop_back();
    return true;
  }

  /** Get a random element from the set. */
  int getRandom() {
    const int index = rand() % vals.size();
    return vals[index];
  }

 private:
  unordered_map<int, int> valToIndex;  // {val: index in vals}
  vector<int> vals;
};
