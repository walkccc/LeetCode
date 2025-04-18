class TrafficLight {
 public:
  void carArrived(
      // ID of the car
      int carId,
      // ID of the road the car travels on. Can be 1 (road A) or 2 (road B).
      int roadId,
      // direction of the car
      int direction,
      // Use turnGreen() to turn light to green on current road.
      function<void()> turnGreen,
      // Use crossCar() to make car cross the intersection.
      function<void()> crossCar

  ) {
    std::lock_guard<std::mutex> lock(mutex);
    if (canPassRoadId != roadId) {
      canPassRoadId = roadId;
      turnGreen();
    }
    crossCar();
  }

 private:
  int canPassRoadId = 1;  // 1 := road A, 2 := road B
  std::mutex mutex;
};
