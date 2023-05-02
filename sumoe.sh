echo enter n
read n
echo enter 1 for odd and 0 for even
read s
sum=0
i=1
if [ $s -eq 0 ]
then
	while [ $i -le $n ]
	do
		sum=$((sum+((2*i))))
		i=$((i+1))
	done
fi
if [ $s -eq 1 ]
then
	while [ $i -le $n ]
	do
		sum=$((sum+((2*i-1))))
		i=$((i+1))
	done
	
fi
if [ $s -eq 0 ]
then
	echo the sum of even numbers is $sum
fi
if [ $s -eq 1 ]
then
	echo the sum of odd numbers is $sum
fi
