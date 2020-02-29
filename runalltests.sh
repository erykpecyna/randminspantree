echo "D = 0"
for ((k=128; k<=262144; k=k*2)); do
time ./randmst 0 "$k" 1 0
done

echo "D = 2"
for ((k=128; k<=262144; k=k*2)); do
time ./randmst 0 "$k" 1 2
done

echo "D = 3"
for ((k=128; k<=262144; k=k*2)); do
time ./randmst 0 "$k" 1 3
done

echo "D = 4"
for ((k=128; k<=262144; k=k*2)); do
time ./randmst 0 "$k" 1 4
done