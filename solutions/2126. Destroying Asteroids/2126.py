class Solution:
  def asteroidsDestroyed(self, mass: int, asteroids: List[int]) -> bool:
    for asteroid in sorted(asteroids):
      if mass >= asteroid:
        mass += asteroid
      else:
        return False
    return True
