SELECT
  Product.product_id,
  Product.product_name
FROM Product
INNER JOIN Sales
  USING (product_id)
GROUP BY 1, 2
HAVING SUM(
    Sales.sale_date < '2019-01-01'
    OR Sales.sale_date > '2019-03-31'
  ) = 0;
