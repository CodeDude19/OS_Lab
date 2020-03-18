echo "Enter number to check for palindrome : "
read n
n1=$n
r=0
while [ $n -ne 0 ]
do
    r=$((r*10))
    r=$((r+(n%10)))
    n=$((n/10))
done
if [ $n1 -eq $r ]
then
    echo "Palindrome"
else
    echo "Not a Palindrome"
fi