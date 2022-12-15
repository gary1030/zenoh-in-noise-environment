# Zenoh Emulation on INET

## System Requirements
- Operating System: Ubuntu 22.04
- CPU: Intel i7-106G7
- Memory: 16G

## Installation

First, install OMNET 6.0.1 ([Download](https://omnetpp.org/download/)) and INET 4.3.9 ([Download](https://github.com/inet-framework/inet/releases/tag/v4.3.9)).
Manually install INET by open a OMNET workspace and select `File/import/General/Existing project into workspace`, and select the INET you just downloaded.

Next, copy the  folde  `zenoh-emulation/ethernet` (or `wireless` if you want) to `{INET_ROOT}/showcases/emulation`

## How to Use

You can edit `run_zenoh.sh` to specify the result file name you want 
Edit `ZenohShowcaseNetwork.ned` to change network configuration
Edit `omnet.ini` to change runtime configurations

Execute `run_zenoh.sh` to start the emulation and test zenoh on the simulated network.
