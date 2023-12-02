SELECT
  Invoices.invoice_id,
  Customers.customer_name,
  Invoices.price,
  COUNT(Contacts.user_id) AS contacts_cnt,
  COUNT(CustomerEmails.email) AS trusted_contacts_cnt
FROM Invoices
INNER JOIN Customers
  ON (Invoices.user_id = Customers.customer_id)
LEFT JOIN Contacts
  ON (Customers.customer_id = Contacts.user_id)
LEFT JOIN Customers AS CustomerEmails
  ON (Contacts.contact_email = CustomerEmails.email)
GROUP BY 1
ORDER BY 1;
