# Definition for a street.
# class Street:
#   def openDoor(self):
#     pass
#   def closeDoor(self):
#     pass
#   def isDoorOpen(self):
#     pass
#   def moveRight(self):
#     pass
#   def moveLeft(self):
#     pass

class Solution:
  def houseCount(self, street: Optional['Street'], k: int) -> int:
    for _ in range(k):
      if street.isDoorOpen():
        street.closeDoor()
      street.moveRight()

    for ans in range(k + 1):
      if street.isDoorOpen():
        return ans
      street.openDoor()
      street.moveRight()
