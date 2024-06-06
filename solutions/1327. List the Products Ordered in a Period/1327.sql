SELECT
  Products.product_name,
  SUM(Orders.unit) AS unit
FROM Products
INNER JOIN Orders
  USING (product_id)
WHERE DATE_FORMAT(Orders.order_date, '%Y-%m') = '2020-02'
GROUP BY product_id
HAVING SUM(Orders.unit) >= 100;
