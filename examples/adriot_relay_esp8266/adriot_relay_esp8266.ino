
#include <ADRIOT_relay.h>

relayManagment relay_managment;
int 			relayId;
int 			relay2Id;

void setup()
{
	relay_managment.create 		(2, relayId);
	relay_managment.create 		(16, relay2Id);
	// relay_managment.setPullup 	(relayId, true);
	relay_managment.relay(relayId)->close();
	relay_managment.relay(relay2Id)->close();

}

void loop()
{
	// relay_managment.relay(relayId)->open();
	// relay_managment.relay(relay2Id)->close();
	// delay(1000);
	// relay_managment.relay(relayId)->close();
	// relay_managment.relay(relay2Id)->open();
	// delay(1000);


}