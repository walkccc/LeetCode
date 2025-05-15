SELECT
  ROUND(
    100 * AVG(order_date = customer_pref_delivery_date),
    2
  ) AS immediate_percentage
FROM Delivery;
