class NumberContainers {
 public:
  void change(int index, int number) {
    const auto it = indexToNumber.find(index);
    if (it != indexToNumber.cend()) {
      const int originalNumber = it->second;
      auto& indices = numberToIndices[originalNumber];
      indices.erase(index);
      if (indices.empty())
        numberToIndices.erase(originalNumber);
    }
    numberToIndices[number].insert(index);
  }

  int find(int number) {
    const auto it = numberToIndices.find(number);
    if (it == numberToIndices.cend())
      return -1;
    const auto& indices = it->second;
    return *indices.begin();
  }

 private:
  unordered_map<int, int> indexToNumber;
  unordered_map<int, set<int>> numberToIndices;
};
