#include "relay.h"

#define MAX_RELAY 10
relayClass 	* relayClassArray[MAX_RELAY];

relayManagement::relayManagement(){

}

void relayManagement::create(int value, int & result){
	relayClassArray[_pos] = new relayClass(value);
	_pos++;
}

void relayManagement::setPullup(boolean value){
	for (int i = 0; i < MAX_RELAY; ++i) {relayClassArray[i]->setPullup(value);}
}

void relayManagement::setPullup(int pos, boolean value){
	relayClassArray[pos]->setPullup(value);
}

relayClass * relayManagement::relay(int pos){
	return relayClassArray[pos];
}


relayClass::relayClass(int pin){
    _pin = pin;
    pinMode(_pin ,OUTPUT);
    close();
    
}

void relayClass::close(){
    setStatus(false);
    _status = false;
}

void relayClass::open(){
    setStatus(true);
    _status = true;
}

void relayClass::setStatus(boolean value){
	if (value) {
		if (_pullup) 	digitalWrite(_pin , LOW);
		else 			digitalWrite(_pin , HIGH);
	} else {
		if (_pullup) 	digitalWrite(_pin , HIGH);
		else 			digitalWrite(_pin , LOW);
	}

}
void relayClass::setPullup(boolean value){
	_pullup = value;
}

boolean relayClass::getStatus(){
    //Serial.println("status");
    //Serial.println(_status , BIN);
    return (boolean)_status;
}
