
#include <ADRIOT_relay.h>

relayManagement relay_managment;
int 			relayId;

void setup()
{
	relay_managment.create 		(D1, relayId);
	relay_managment.setPullup 	(relayId, true);
}

void loop()
{
	relay_managment.relay(relayId)->open();
	delay(3000);
	relay_managment.relay(relayId)->close();
}