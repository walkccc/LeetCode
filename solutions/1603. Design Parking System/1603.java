class ParkingSystem {
  public ParkingSystem(int big, int medium, int small) {
    count = new int[] {big, medium, small};
  }

  public boolean addCar(int carType) {
    return count[carType - 1]-- > 0;
  }

  private int[] count;
}
