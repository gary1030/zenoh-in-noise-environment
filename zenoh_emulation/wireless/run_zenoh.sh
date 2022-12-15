zsh teardown.sh
zsh setup.sh

# start streaming server
python3 z_pub.py -c ./config/server.json5 --iter 250 &

# start streaming client
python3 z_sub.py -c ./config/client.json5 &

# start simulation
inet -u Cmdenv -f omnetpp.ini

# kill child processes
# trap 'kill $(jobs -pr)' SIGINT SIGTERM EXIT
pkill python3
zsh teardown.sh
