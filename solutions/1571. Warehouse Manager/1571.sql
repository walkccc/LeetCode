SELECT
  Warehouse.name AS warehouse_name,
  SUM(
    Warehouse.units * Products.width * Products.length * Products.height
  ) AS volume
FROM Warehouse
INNER JOIN Products
  USING (product_id)
GROUP BY 1;
