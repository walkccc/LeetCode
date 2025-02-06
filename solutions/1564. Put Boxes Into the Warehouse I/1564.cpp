class Solution {
 public:
  int maxBoxesInWarehouse(vector<int>& boxes, vector<int>& warehouse) {
    vector<int> realWarehouse{warehouse[0]};

    for (int i = 1; i < warehouse.size(); ++i)
      realWarehouse.push_back(min(realWarehouse.back(), warehouse[i]));

    ranges::sort(boxes);
    int i = 0;  // boxes' index
    for (int j = realWarehouse.size() - 1; j >= 0; j--)
      if (i < boxes.size() && boxes[i] <= realWarehouse[j])
        ++i;

    return i;
  }
};
