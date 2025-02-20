struct Item {
  int val;
  int indexInMap;
};

class RandomizedCollection {
 public:
  bool insert(int val) {
    valToIndices[val].push_back(items.size());
    items.emplace_back(val, valToIndices[val].size() - 1);
    return valToIndices[val].size() == 1;
  }

  bool remove(int val) {
    if (!valToIndices.contains(val))
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

  int getRandom() {
    const int index = rand() % items.size();
    return items[index].val;
  }

 private:
  unordered_map<int, vector<int>> valToIndices;
  vector<Item> items;
};
