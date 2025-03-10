SELECT
  Customers.customer_id,
  Customers.name
FROM Customers
INNER JOIN Orders
  USING (customer_id)
INNER JOIN Product
  USING (product_id)
GROUP BY 1
HAVING
  SUM(
    IF(
      DATE_FORMAT(Orders.order_date, '%Y-%m') = '2020-06',
      Orders.quantity * price,
      0
    )
  ) >= 100
  AND SUM(
    IF(
      DATE_FORMAT(Orders.order_date, '%Y-%m') = '2020-07',
      Orders.quantity * price,
      0
    )
  ) >= 100;
