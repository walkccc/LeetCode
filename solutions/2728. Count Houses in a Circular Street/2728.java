/**
 * Definition for a street.
 * class Street {
 *   public Street(int[] doors);
 *   public void openDoor();
 *   public void closeDoor();
 *   public boolean isDoorOpen();
 *   public void moveRight();
 *   public void moveLeft();
 * }
 */

class Solution {
  public int houseCount(Street street, int k) {
    for (int i = 0; i < k; ++i) {
      if (street.isDoorOpen())
        street.closeDoor();
      street.moveRight();
    }

    for (int ans = 0;; ++ans) {
      if (street.isDoorOpen())
        return ans;
      street.openDoor();
      street.moveRight();
    }
  }
}
