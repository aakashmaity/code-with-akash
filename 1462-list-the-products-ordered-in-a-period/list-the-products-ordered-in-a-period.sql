# Write your MySQL query statement below
select product_name,SUM(unit) as unit
from Products p
right join Orders o
on o.product_id = p.product_id 
where order_date >= '2020-02-01' and order_date <= '2020-02-29'
group by o.product_id
having sum(unit) >=100