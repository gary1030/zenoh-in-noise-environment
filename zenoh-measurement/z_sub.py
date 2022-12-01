#
# Copyright (c) 2022 ZettaScale Technology
#
# This program and the accompanying materials are made available under the
# terms of the Eclipse Public License 2.0 which is available at
# http://www.eclipse.org/legal/epl-2.0, or the Apache License, Version 2.0
# which is available at https://www.apache.org/licenses/LICENSE-2.0.
#
# SPDX-License-Identifier: EPL-2.0 OR Apache-2.0
#
# Contributors:
#   ZettaScale Zenoh Team, <zenoh@zettascale.tech>
#

import sys
import time
from datetime import datetime
import argparse
import json
import zenoh
from zenoh import Reliability, Sample

# --- Command line argument parsing --- --- --- --- --- ---
parser = argparse.ArgumentParser(
    prog='z_sub',
    description='zenoh sub example')
parser.add_argument('--mode', '-m', dest='mode',
                    choices=['peer', 'client'],
                    type=str,
                    help='The zenoh session mode.')
parser.add_argument('--connect', '-e', dest='connect',
                    metavar='ENDPOINT',
                    action='append',
                    type=str,
                    help='Endpoints to connect to.')
parser.add_argument('--listen', '-l', dest='listen',
                    metavar='ENDPOINT',
                    action='append',
                    type=str,
                    help='Endpoints to listen on.')
parser.add_argument('--key', '-k', dest='key',
                    default='demo/example/**',
                    type=str,
                    help='The key expression to subscribe to.')
parser.add_argument('--config', '-c', dest='config',
                    metavar='FILE',
                    type=str,
                    help='A configuration file.')
parser.add_argument('--result', '-r', dest='result',
                    metavar='FILE',
                    type=str,
                    help='A file to write the subscription result to.')

result_filepath = "received-data/run1.json"
args = parser.parse_args()
conf = zenoh.Config.from_file(
    args.config) if args.config is not None else zenoh.Config()
if args.mode is not None:
    conf.insert_json5(zenoh.config.MODE_KEY, json.dumps(args.mode))
if args.connect is not None:
    conf.insert_json5(zenoh.config.CONNECT_KEY, json.dumps(args.connect))
if args.listen is not None:
    conf.insert_json5(zenoh.config.LISTEN_KEY, json.dumps(args.listen))
if args.result is not None:
    result_filepath = args.result

key = args.key

# define a list to store the received packet id and recieve time
received_packet_list = []

# Zenoh code  --- --- --- --- --- --- --- --- --- --- ---



# initiate logging
zenoh.init_logger()

print("Opening session...")
session = zenoh.open(conf)

print("Declaring Subscriber on '{}'...".format(key))


def listener(sample: Sample):
    received_time = int(time.time() * 1000)
    received_str = sample.payload.decode('utf-8')
    comma_index = received_str.find(",")
    received_packet_id = received_str[:comma_index]
    received_packet_list.append({"packet_id": received_packet_id, "received_time": received_time})
    print(f"received packet id: {received_packet_id}")

# WARNING, you MUST store the return value in order for the subscription to work!!
# This is because if you don't, the reference counter will reach 0 and the subscription
# will be immediately undeclared.

print("The subscribe is ready to receive data! You can press any key to stop the subscription")
start_time = int(time.time() * 1000)
sub = session.declare_subscriber(key, listener, reliability=Reliability.RELIABLE())


is_end = input()
print("Ending subscription...")

# Cleanup: note that even if you forget it, cleanup will happen automatically when 
# the reference counter reaches 0

sub.undeclare()
session.close()

# write the start time and received packet list to a json file
data = {"start_time": start_time, "received_packet_list": received_packet_list}
with open(result_filepath, 'w') as f:
    json.dump(data, f)

print("Successfully write the received packet list to a json file")
print("Bye!")
