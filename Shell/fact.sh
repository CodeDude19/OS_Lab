echo "Enter a number : "
read number
facn=1
while [ $number -gt 1 ]
do
    facn=$((facn*number))
    number=$((number - 1))
done
echo $facn

