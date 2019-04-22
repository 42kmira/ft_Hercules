#apt-get -qq install at -y

echo "touch boar.txt; echo \"Winter is coming\" >> boar.txt" | at 08:42 Dec 21
#echo "Task scheduled on Dec 21 08:42."

#echo "at -f <pathname>" | at 08:42 Dec 21 08:42
