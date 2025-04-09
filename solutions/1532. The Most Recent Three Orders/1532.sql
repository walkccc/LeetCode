WITH
  OrdersWithRowNumber AS (
    SELECT
      order_id,
      order_date,
      customer_id,
      ROW_NUMBER() OVER(
        PARTITION BY customer_id
        ORDER BY order_date DESC
      ) AS `row_number`
    FROM Orders
  )
SELECT
  Customers.name AS customer_name,
  Customers.customer_id,
  OrdersWithRowNumber.order_id,
  OrdersWithRowNumber.order_date
FROM OrdersWithRowNumber
INNER JOIN Customers
  USING (customer_id)
WHERE `row_number` <= 3
ORDER BY customer_name, customer_id, order_date DESC;
