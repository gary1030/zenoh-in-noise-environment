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
import argparse
import itertools
from datetime import datetime
import json
import zenoh
from zenoh import config

# --- Command line argument parsing --- --- --- --- --- ---
parser = argparse.ArgumentParser(
    prog='z_pub',
    description='zenoh pub example')
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
                    default='demo/example/test',
                    type=str,
                    help='The key expression to publish onto.')
parser.add_argument('--value', '-v', dest='value',
                    default='Pub from Python!',
                    type=str,
                    help='The value to publish.')
parser.add_argument("--iter", dest="iter", type=int,
                    help="How many puts to perform")
parser.add_argument('--config', '-c', dest='config',
                    metavar='FILE',
                    type=str,
                    help='A configuration file.')
parser.add_argument('--result', '-r', dest='result',
                    metavar='FILE',
                    type=str,
                    help="A file to write the published data to.")

result_filepath = "sent-data/run1.json"
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
value = args.value
sent_packet_info_list = []

# initiate logging
zenoh.init_logger()

print("Opening session...")
session = zenoh.open(conf)

print(f"Declaring Publisher on '{key}'...")
pub = session.declare_publisher(key)

paylod_with_1MB = "a" * 1024 * 8

time.sleep(5)

start_time = int(time.time() * 1000)

for idx in range(100):
    print(f"The sent packet id: {idx}")
    sent_time = int(time.time() * 1000000)
    sent_packet_info_list.append({"packet_id": -1, "sent_time": sent_time})
    pub.put(f"{idx},{paylod_with_1MB}")


for idx in itertools.count() if args.iter is None else range(args.iter):
    print(f"The sent packet id: {idx}")
    sent_time = int(time.time() * 1000000)
    sent_packet_info_list.append({"packet_id": idx, "sent_time": sent_time})
    pub.put(f"{idx},{paylod_with_1MB}")
    time.sleep(0.01)

time.sleep(10)

pub.undeclare()
session.close()
# convert packet info list to json and store to result_filepath
data = {"start_time": start_time, "sent_packet_list": sent_packet_info_list}
with open(result_filepath, "w+") as f:
    json.dump(data, f)


print("Successfully write the sent packet list to a json file")
print("Bye!")
