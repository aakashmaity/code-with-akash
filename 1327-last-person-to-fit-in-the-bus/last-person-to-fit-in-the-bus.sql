# Write your MySQL query statement below
select q1.person_name
from Queue q1
where 1000 >= (select sum(q2.weight) from Queue q2 where q1.turn >= q2.turn)
order by q1.turn DESC LIMIT 1