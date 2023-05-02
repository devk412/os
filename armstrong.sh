echo enter the number
read num

sum=0
temp=$num

while [ $num -gt 0 ]
do
	r=$((num%10))
	sum=$((sum+r*r*r))
	num=$((num/10))
done
if [ $temp -eq $sum ]
then
	echo its an armstrong number
else
	echo its not an armstrong number
fi
