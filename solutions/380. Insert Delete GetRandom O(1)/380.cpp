class RandomizedSet {
 public:
  bool insert(int val) {
    if (valToIndex.contains(val))
      return false;
    valToIndex[val] = vals.size();
    vals.push_back(val);
    return true;
  }

  bool remove(int val) {
    if (!valToIndex.contains(val))
      return false;
    const int index = valToIndex[val];
    // The order of the following two lines is important when vals.size() == 1.
    valToIndex[vals.back()] = index;
    valToIndex.erase(val);
    vals[index] = vals.back();
    vals.pop_back();
    return true;
  }

  int getRandom() {
    const int index = rand() % vals.size();
    return vals[index];
  }

 private:
  unordered_map<int, int> valToIndex;  // {val: index in vals}
  vector<int> vals;
};
