#!/bin/bash

make re
sleep 1
clear
echo -e "\033[0;32mSTARTING TESTS\n"
sleep 1
echo -e "ERROR HANDLING\n"
echo -e "\nTest 1:"
echo -e "\nPassing a letter as argument!\n\033[0m"
sleep 3
./philo 5 800 a 200
sleep 1
echo -e "\033[0;32m\nTest 2:"
echo -e "\nPassing a negative number as argument!\n\033[0m"
sleep 3
./philo 5 800 -300 200
sleep 1
echo -e "\033[0;32m\nTest 3:"
echo -e "\nPassing no argument!\n\033[0m"
sleep 3
./philo
sleep 1
echo -e "\033[0;32m\nTest 4:"
echo -e "\nPassing 6 arguments!\n\033[0m"
sleep 3
./philo 5 800 200 200 6 100 
sleep 1
echo -e "\033[0;32m\nTest 5:"
echo -e "\nPassing 2 arguments!\n\033[0m"
sleep 3
./philo 5 800
sleep 1
echo -e "\033[0;32m\n\nError Tests completed!\n\033[0m"
sleep 1
clear
echo -e "\033[0;32m\nTest 1:"
echo -e "1 Philosopher"
echo -e "Time to die 800ms"
echo -e "Time to eat 200ms"
echo -e "Time to sleep 200ms\n"
echo -e "\nPhilosopher should not eat, and should die!\n\033[0m"
sleep 3
./philo 1 800 200 200
sleep 1
echo -e "\033[0;32m\nTest 2:"
echo -e "5 Philosophers"
echo -e "Time to die 800ms"
echo -e "Time to eat 200ms"
echo -e "Time to sleep 200ms\n"
echo -e "\nNo Philosopher should die! Testing for 15 sec!\n\033[0m"
sleep 3
./philo 5 800 200 200 &
PID=$!
sleep 15
kill $PID
sleep 1
echo -e "\033[0;32m\nTest 3:"
echo -e "5 Philosophers"
echo -e "Time to die 800ms"
echo -e "Time to eat 200ms"
echo -e "Time to sleep 200ms"
echo -e "Number of meals 7\n"
echo -e "\nAll Philosopher should eat at least 7 meals!\n\033[0m"
sleep 3
./philo 5 800 200 200 7
sleep 1
echo -e "\033[0;32m\nTest 4:"
echo -e "4 Philosophers"
echo -e "Time to die 410ms"
echo -e "Time to eat 200ms"
echo -e "Time to sleep 200ms\n"
echo -e "\nNo Philosopher should die! Testing for 15 sec!\n\033[0m"
sleep 3
./philo 4 410 200 200 &
PID=$!
sleep 15
kill $PID
sleep 1
echo -e "\033[0;32m\nTest 5:"
echo -e "4 Philosophers"
echo -e "Time to die 310ms"
echo -e "Time to eat 200ms"
echo -e "Time to sleep 100ms\n"
echo -e "\nOne Philosopher should die!\n\033[0m"
sleep 3
./philo 4 310 200 100
sleep 1
echo -e "\033[0;32m\nTest 6:"
echo -e "2 Philosophers"
echo -e "Time to die 800ms"
echo -e "Time to eat 200ms"
echo -e "Time to sleep 200ms\n\033[0m"
echo -e "\nNo Philosopher should die! Testing for 15 sec\n\033[0m"
sleep 3
./philo 2 800 200 200 &
PID=$!
sleep 15
kill $PID
sleep  1
echo -e "\033[0;32m\n\nFinished Successfully!\n\033[0m"
