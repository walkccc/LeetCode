class ParkingSystem:
  def __init__(self, big: int, medium: int, small: int):
    self.count = [big, medium, small]

  def addCar(self, carType: int) -> bool:
    self.count[carType - 1] -= 1
    return self.count[carType - 1] >= 0
