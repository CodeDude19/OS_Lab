echo "Enter number to reverse : "
read n
r=0
while [ $n -ne 0 ]
do
    r=$((r*10))
    r=$((r+(n%10)))
    n=$((n/10))
done
echo $r