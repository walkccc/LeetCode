struct Item {
  int val;
  int indexInMap;
  Item(int val, int indexInMap) : val(val), indexInMap(indexInMap) {}
};

class RandomizedCollection {
 public:
  /** Inserts a value to the collection. Returns true if the collection did not
   * already contain the specified element. */
  bool insert(int val) {
    valToIndices[val].push_back(items.size());
    items.emplace_back(val, valToIndices[val].size() - 1);
    return valToIndices[val].size() == 1;
  }

  /** Removes a value from the collection. Returns true if the collection
   * contained the specified element. */
  bool remove(int val) {
    if (!valToIndices.count(val))
      return false;

    const int index = valToIndices[val].back();
    valToIndices[items.back().val][items.back().indexInMap] = index;
    valToIndices[val].pop_back();
    if (valToIndices[val].empty())
      valToIndices.erase(val);
    items[index] = items.back();
    items.pop_back();
    return true;
  }

  /** Get a random element from the collection. */
  int getRandom() {
    const int index = rand() % items.size();
    return items[index].val;
  }

 private:
  unordered_map<int, vector<int>> valToIndices;
  vector<Item> items;
};
