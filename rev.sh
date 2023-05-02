echo enter the number to be reversed
read n
sum=0
temp=$n
while [ $n -gt 0 ]
do
	r=$((n%10))
	sum=$((((sum*10))+r))
	n=$((n/10))
done
echo the reverse of the number will be $sum
