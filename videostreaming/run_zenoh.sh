# start streaming server
python3 z_pub.py -c server.json5 &

# start streaming client
python3 z_sub.py -c client.json5 &

# start simulation
inet -u Cmdenv -f omnetpp.ini

# kill child processes
# trap 'kill $(jobs -pr)' SIGINT SIGTERM EXIT
pkill python3
