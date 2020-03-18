echo "Enter number : "
read n
n1=$n
n2=$n
count=0
sum=0
while [ $n -gt 0 ]
do
    n=$((n/10))
    count=$((count+1))
done
while [ $n1 -gt 0 ]
do 
    k=$((n1%10))
    n1=$((n1/10))
    u=$((k**count))
    sum=$((sum+u))
done
if [ $n2 -eq $sum ]
then
    echo "Its an Armstrong Number!"
else
    echo "Not an Armstrong Number!"
fi