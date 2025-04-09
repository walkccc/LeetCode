class TrafficLight:
  def __init__(self):
    self.canPassRoadId = 1  # 1 := road A, 2 := road B

  def carArrived(
      self,
      # ID of the car
      carId: int,
      # ID of the road the car travels on. Can be 1 (road A) or 2 (road B).
      roadId: int,
      # direction of the car
      direction: int,
      # Use turnGreen() to turn light to green on current road.
      turnGreen: Callable[[], None],
      # Use crossCar() to make car cross the intersection.
      crossCar: Callable[[], None]
  ) -> None:
    if roadId != self.canPassRoadId:
      self.canPassRoadId = roadId
      turnGreen()
    crossCar()
