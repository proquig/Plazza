#!/bin/sh
echo "\033[1;4;31m--- Moulinette Plazza ---\033[0m"

make re

echo "\033[1;4;31m--- Plazza 5 ---\033[0m"
cat test/order.txt | ./plazza 5

