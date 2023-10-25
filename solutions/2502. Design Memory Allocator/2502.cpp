class Allocator {
 public:
  Allocator(int n) : memory(n), mIDToIndices(1001) {}

  int allocate(int size, int mID) {
    int consecutiveFree = 0;
    for (int i = 0; i < memory.size(); ++i) {
      consecutiveFree = memory[i] == 0 ? consecutiveFree + 1 : 0;
      if (consecutiveFree == size) {
        for (int j = i - consecutiveFree + 1; j <= i; ++j) {
          memory[j] = mID;
          mIDToIndices[mID].push_back(j);
        }
        return i - consecutiveFree + 1;
      }
    }
    return -1;
  }

  int free(int mID) {
    vector<int>& indices = mIDToIndices[mID];
    const int freedUnits = indices.size();
    for (const int index : indices)
      memory[index] = 0;
    indices.clear();
    return freedUnits;
  }

 private:
  vector<int> memory;
  vector<vector<int>> mIDToIndices;
};
