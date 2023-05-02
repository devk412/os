echo enter the factorial
read a
f=1
i=1
while [ $i -le $a ]
do
	f=$((f * i))
	i=$((i + 1))
done
echo the factorial is $f
