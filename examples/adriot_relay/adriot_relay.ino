
#include <adriiot_relay.h>

relayManagment relay_managment;
int 			relayId;
int 			relay2Id;

void setup()
{
	relay_managment.create 		(2, relayId);
	relay_managment.create 		(16, relay2Id);
	// relay_managment.setPullup 	(relayId, true);
	relay_managment.module(relayId)->close();
	relay_managment.module(relay2Id)->close();

}

void loop()
{

}