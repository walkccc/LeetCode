SELECT
  Prices.product_id,
  IFNULL(
    ROUND(
      SUM(Prices.price * UnitsSold.units) / SUM(UnitsSold.units),
      2
    ),
    0
  ) AS average_price
FROM Prices
LEFT JOIN UnitsSold
  ON (
    Prices.product_id = UnitsSold.product_id
    AND UnitsSold.purchase_date BETWEEN Prices.start_date AND Prices.end_date)
GROUP BY 1;
