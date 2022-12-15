package inet.showcases.emulation.ethernet;

import inet.networklayer.configurator.ipv4.Ipv4NetworkConfigurator;
import inet.physicallayer.wireless.ieee80211.packetlevel.Ieee80211ScalarRadioMedium;
import inet.node.ethernet.Eth100M;
import inet.node.ethernet.EthernetSwitch;
import inet.node.inet.Router;
import inet.node.inet.StandardHost;
import inet.visualizer.common.IntegratedVisualizer;
import inet.node.inet.AdhocHost;
import inet.node.wireless.AccessPoint;
import inet.node.inet.WirelessHost;


network ZenohShowcase
{
    parameters:
        @display("bgb=1000,400");
    submodules:
        configurator: Ipv4NetworkConfigurator {
            parameters:
                @display("p=100,100;is=s");
        }
        visualizer: IntegratedVisualizer {
            parameters:
                @display("p=100,200;is=s");
        }
        switch1: EthernetSwitch {
            parameters:
                @display("p=300,300");
        }
        // switch2: AccessPoint {
	switch2: EthernetSwitch {
            parameters:
                @display("p=700,300");
        }
        router: Router {
            parameters:
                @display("p=500,300");
        }
        host1: StandardHost {
            parameters:
                @display("p=100,300");
        }
        // host2: WirelessHost {
	host2: StandardHost {
            parameters:
                @display("p=900,300");
        }
        radioMedium: Ieee80211ScalarRadioMedium {
            @display("p=400,100");
        }
        
    connections:
        host1.ethg++ <--> Eth100M <--> switch1.ethg++;
        switch1.ethg++ <--> Eth100M <--> router.ethg++;
        router.ethg++ <--> Eth100M <--> switch2.ethg++;
        switch2.ethg++ <--> Eth100M <--> host2.ethg++;
}
