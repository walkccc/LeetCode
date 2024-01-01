/**
 * Definition for a street.
 * class Street {
 *  public:
 *   Street(vector<int> doors);
 *   void closeDoor();
 *   bool isDoorOpen();
 *   void moveRight();
 * };
 */
class Solution {
 public:
  int houseCount(Street* street, int k) {
    int ans = 0;

    // Go to the first open door.
    while (!street->isDoorOpen())
      street->moveRight();

    street->moveRight();

    for (int count = 1; count <= k; ++count) {
      // Each time we encounter an open door, there's a possibility that it's
      // the first open door we intentionally left open.
      if (street->isDoorOpen()) {
        ans = count;
        street->closeDoor();
      }
      street->moveRight();
    }

    return ans;
  }
};
