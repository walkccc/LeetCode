class Solution {
 public:
  vector<int> relocateMarbles(vector<int>& nums, vector<int>& moveFrom,
                              vector<int>& moveTo) {
    set<int> numsSet{nums.begin(), nums.end()};

    for (int i = 0; i < moveFrom.size(); ++i) {
      numsSet.erase(numsSet.find(moveFrom[i]));
      numsSet.insert(moveTo[i]);
    }

    return {numsSet.begin(), numsSet.end()};
  }
};
