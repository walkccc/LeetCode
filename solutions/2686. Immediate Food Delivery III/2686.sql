SELECT
  order_date,
  ROUND(
    AVG(order_date = customer_pref_delivery_date) * 100,
    2
  ) AS immediate_percentage
FROM Delivery
GROUP BY 1
ORDER BY 1;
