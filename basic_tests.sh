#!/bin/bash

make re
sleep 1
clear
echo "STARTING TESTS\n"
sleep 1
echo "\033[0m\nTest 1:"
echo "1 Philosopher"
echo "Time to die 800ms"
echo "Time to eat 200ms"
echo "Time to sleep 200ms\n\033[0;32m"
./philo 1 800 200 200
sleep 1
echo "\033[0m\nTest 2:"
echo "5 Philosophers"
echo "Time to die 800ms"
echo "Time to eat 200ms"
echo "Time to sleep 200ms\n\033[0;32m"
while ./philo 5 800 200 200; do sleep 10; done
sleep 1
echo "\033[0m\nTest 3:"
echo "5 Philosophers"
echo "Time to die 800ms"
echo "Time to eat 200ms"
echo "Time to sleep 200ms"
echo "Number of meals 7\n\033[0;32m"
./philo 5 800 200 200 7
sleep 1
echo "\033[0m\nTest 4:"
echo "4 Philosophers"
echo "Time to die 410ms"
echo "Time to eat 200ms"
echo "Time to sleep 200ms\n\033[0;32m"
while ./philo 4 410 200 200; do sleep 10; done
sleep 1
echo "\033[0m\nTest 5:"
echo "4 Philosophers"
echo "Time to die 310ms"
echo "Time to eat 200ms"
echo "Time to sleep 100ms\n\033[0;32m"
./philo 4 310 200 100
sleep 1
echo "\033[0m\nTest 6:"
echo "2 Philosophers"
echo "Time to die 800ms"
echo "Time to eat 200ms"
echo "Time to sleep 200ms\n\033[0;32m"
while ./philo 2 800 200 200; do sleep 10; done
sleep  1
echo "\033[0m\n\nFinished Successfully!\n"