class TrafficLight {
  public void carArrived(
      // ID of the car
      int carId,
      // ID of the road the car travels on. Can be 1 (road A) or 2 (road B).
      int roadId,
      // direction of the car
      int direction,
      // Use turnGreen() to turn light to green on current road.
      Runnable turnGreen,
      // Use crossCar() to make car cross the intersection.
      Runnable crossCar) {
    synchronized (this) {
      if (canPassRoadId != roadId) {
        canPassRoadId = roadId;
        turnGreen.run();
      }
      crossCar.run();
    }
  }

  private int canPassRoadId = 1; // 1 := road A, 2 := road B
}
