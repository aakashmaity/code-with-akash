# Write your MySQL query statement below
select 
ROUND(SUM(case when order_date=customer_pref_delivery_date then 1 else 0 end) * 100 / count(distinct customer_id) , 2) as immediate_percentage
from Delivery where (customer_id, order_date) IN
    (SELECT customer_id, MIN(order_date) AS first_order_date
    FROM Delivery
    GROUP BY customer_id)