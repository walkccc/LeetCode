class Solution {
 public:
  int maxBoxesInWarehouse(vector<int>& boxes, vector<int>& warehouse) {
    int l = 0;
    int r = warehouse.size() - 1;

    sort(boxes.rbegin(), boxes.rend());

    for (const int box : boxes) {
      if (l > r)
        return warehouse.size();
      if (box <= warehouse[l])
        ++l;
      else if (box <= warehouse[r])
        --r;
    }

    return l + (warehouse.size() - r - 1);
  }
};
