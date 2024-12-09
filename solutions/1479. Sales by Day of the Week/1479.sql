SELECT
  Items.item_category AS Category,
  SUM(IF(WEEKDAY(Orders.order_date) = 0, Orders.quantity, 0)) AS Monday,
  SUM(IF(WEEKDAY(Orders.order_date) = 1, Orders.quantity, 0)) AS Tuesday,
  SUM(IF(WEEKDAY(Orders.order_date) = 2, Orders.quantity, 0)) AS Wednesday,
  SUM(IF(WEEKDAY(Orders.order_date) = 3, Orders.quantity, 0)) AS Thursday,
  SUM(IF(WEEKDAY(Orders.order_date) = 4, Orders.quantity, 0)) AS Friday,
  SUM(IF(WEEKDAY(Orders.order_date) = 5, Orders.quantity, 0)) AS Saturday,
  SUM(IF(WEEKDAY(Orders.order_date) = 6, Orders.quantity, 0)) AS Sunday
FROM Items
LEFT JOIN Orders
  USING (item_id)
GROUP BY 1
ORDER BY 1;
