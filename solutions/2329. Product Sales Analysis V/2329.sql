SELECT
  Sales.user_id,
  SUM(Sales.quantity * Product.price) AS spending
FROM Sales
INNER JOIN Product
  USING (product_id)
GROUP BY user_id
ORDER BY spending DESC;
