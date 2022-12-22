# Zenoh Application - How to Run

## Steps
* Prepare two machines, one for subscriber and one for publisher
* Clone the repository
* Open the terminal and type `pip install -r requirements.txt`
* On the publisher machine, run publisher program by typing `python z_pub.py -c config/publisher_config.json5`. In the config file, set connect endpoint to the subscriber machine's IP address, and the port should be 7447.
* On the subscriber machine, run subscriber porgram by typing `python z_sub.py -c config/subscriber_config.json5`. Also in the config file, set connect endpoint to the publisher machine's IP address, and the port should be 7447.
