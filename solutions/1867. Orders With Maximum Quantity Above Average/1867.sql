WITH
  GroupedOrders AS (
    SELECT
      order_id,
      MAX(quantity) AS max_quantity,
      MAX(AVG(quantity)) OVER() AS max_avg_quantity
    FROM OrdersDetails
    GROUP BY 1
  )
SELECT order_id
FROM GroupedOrders
WHERE max_quantity > max_avg_quantity;
