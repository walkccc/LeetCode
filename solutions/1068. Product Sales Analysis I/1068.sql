SELECT
  Product.product_name,
  Sales.year,
  Sales.price
FROM Sales
INNER JOIN Product
  USING (product_id);
