# zenoh-on-inet-emulation


## Notice
1. `inet-4.4/src/inet/common/precompiled_debug.h.gch` file is too large to upload to github


## Troubleshooting
Q: mac is not connected to a module of type queueing::IPacketQueue
A: https://groups.google.com/g/omnetpp/c/7APj_-6Nmug?pli=1

Q: Cannot create TAP device: Device or resource busy -- in module (inet::ExtEthernetTapDevice)
A: revise omnetpp.ini
```
*.router.ipv4.natTable.config = xml("<config> \
                                        <entry type='prerouting' \
                                        packetFilter='has(Ipv4Header) &amp;&amp; Ipv4Header.destAddress.str() == \"192.168.2.99\"' \
                                        srcAddress='192.168.3.99' destAddress='192.168.3.20'/> \
                                     </config>")
```

Q: handlePacket(): Unknown protocol: protocolId = 12, protocolName = ethernetmac, servicePrimitive = INDICATION, pathStartGate = VideoStreamingNetwork.router.eth[0].mac.upperLayerOut, pathEndGate = VideoStreamingNetwork.router.li.in[3] -- in module (inet::MessageDispatcher) VideoStreamingNetwork.router.li (id=142), at t=5.074020485s, event #18
A: not fixed
