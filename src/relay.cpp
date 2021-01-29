#include "relay.h"
#include <adri_tools.h>

extern boolean aic_relay;

#define MAX_RELAY 10

relayClass 	* relayClassArray[MAX_RELAY];

relayManagment::relayManagment(){

}

void relayManagment::create(int value, int & result){
	relayClassArray[_pos] = new relayClass(value);
	result = _pos;
	_pos++;
}

void relayManagment::setPullup(boolean value){
	for (int i = 0; i < _pos; ++i) {relayClassArray[i]->setPullup(value);}
}

void relayManagment::setPullup(int pos, boolean value){
	relayClassArray[pos]->setPullup(value);
}

relayClass * relayManagment::module(int pos){
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

void relayClass::toggle(){
    _status = !_status;
    setStatus(_status);
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

void relayClass::getStatus(boolean & ret){
    //Serial.println("status");
    //Serial.println(_status , BIN);
    if (_pullup) {
    	if (digitalRead(_pin) == 0) ret = true;
    	else 						ret = false;
    } else {
    	if (digitalRead(_pin) == 0) ret = false;
    	else 						ret = true;    	
    }
}
void relayClass::json(JsonObject & root){
	boolean ret;
	getStatus(ret);
	root[F("v1")] = ret;
}
void relayClass::domoticzJson(JsonObject & root){
	boolean ret;
	getStatus(ret);
	
	if (ret) 	root[F("switchcmd")] = F("On");
	else 		root[F("switchcmd")] = F("Off");
}