zsh teardown.sh
zsh setup.sh
# start streaming server
python3 z_pub.py -c config/server.json5 --iter 120 --result "./sent-data/sent.json" &

# start streaming client
python3 z_sub.py -c config/client.json5 --result "./received-data/received.json" &

# start simulation
inet  -u Cmdenv -f omnetpp.ini

# kill child processes
# trap 'kill $(jobs -pr)' SIGINT SIGTERM EXIT
pkill python3
bash teardown.sh
