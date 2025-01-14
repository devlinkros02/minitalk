#!/bin/bash
clear

make

sleep 2
# Start the server in the background
./server &
SERVER_PID=$!

# Wait for the server to fully start (optional: sleep for setup)
sleep 1

echo -e "\n"

# Run the client with a message and the server's PID
./client $SERVER_PID "This is the first test" 
echo -e "\n"
sleep 2

./client $SERVER_PID "This is the second test. The next test will be the content of text.txt"
echo -e "\n"
sleep 2

./client $SERVER_PID "$(cat test.txt)"
echo -e "\n"
sleep 2

sleep 10
# Optionally kill the server if no longer needed
kill $SERVER_PID

