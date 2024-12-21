SELECT Seller.seller_name
FROM Seller
LEFT JOIN Orders
  ON (
    Seller.seller_id = Orders.seller_id
    AND YEAR(Orders.sale_date) = 2020)
WHERE Orders.order_id IS NULL
ORDER BY 1;
