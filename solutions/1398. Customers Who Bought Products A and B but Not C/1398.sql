SELECT
  customer_id,
  customer_name
FROM Customers
INNER JOIN Orders
  USING (customer_id)
GROUP BY 1
HAVING
  SUM(Orders.product_name = 'A') > 0
  AND SUM(Orders.product_name = 'B') > 0
  AND SUM(Orders.product_name = 'C') = 0;
