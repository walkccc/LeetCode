class Solution {
  public Solution(double radius, double x_center, double y_center) {
    this.radius = radius;
    this.x_center = x_center;
    this.y_center = y_center;
  }

  public double[] randPoint() {
    final double length = Math.sqrt(Math.random()) * radius;
    final double degree = Math.random() * 2 * Math.PI;
    final double x = x_center + length * Math.cos(degree);
    final double y = y_center + length * Math.sin(degree);
    return new double[] {x, y};
  }

  private double radius;
  private double x_center;
  private double y_center;
}
