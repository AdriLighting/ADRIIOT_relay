
#ifndef RELAY_H
	#define RELAY_H
	#include <Arduino.h>
	#include <ArduinoJson.h>

	class relayClass
	{
	public:
		relayClass(int pin);
		~relayClass();

	    void 	open();
	    void 	close();
	    void 	toggle();

	    void 	setStatus(boolean value);
	    void 	setPullup(boolean value);

	    void	getStatus(boolean & ret);

	    void 	json(JsonObject & root);
	    void 	domoticzJson(JsonObject & root);

	private:
	    boolean 	_pullup = true;
	    int 		_pin;
	    boolean		_status;	
	};


	class relayManagment
	{
	private:
		int _pos = 0;
	public:
		relayManagment();
		~relayManagment(){};

		void create 	(int value, int & result);

		void setPullup 	(boolean value);
		void setPullup 	(int pos, boolean value);

		relayClass * module(int pos);
	};

#endif // RELAY_H