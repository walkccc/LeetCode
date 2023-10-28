# Definition for a street.
# class Street:
#   def closeDoor(self):
#     pass
#   def isDoorOpen(self):
#     pass
#   def moveRight(self):
#     pass
class Solution:
  def houseCount(self, street: Optional['Street'], k: int) -> int:
    ans = 0

    # Go to the first open door.
    while not street.isDoorOpen():
      street.moveRight()

    street.moveRight()

    for count in range(k):
      # Each time we encounter an open door, there's a possibility that it's the
      # first open door we intentionally left open.
      if street.isDoorOpen():
        ans = count + 1
        street.closeDoor()
      street.moveRight()

    return ans
