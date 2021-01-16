
#ifndef RELAY_H
	#define RELAY_H

	#include <Arduino.h>


	class relayClass
	{
	public:
		relayClass(int pin);
		~relayClass();

	    void 	open();
	    void 	close();

	    void 	setStatus(boolean value);
	    void 	setPullup(boolean value);

	    boolean	getStatus();

	private:
	    boolean 	_pullup = true;
	    int 		_pin;
	    boolean		_status;	
	};


	class relayManagement
	{
	private:
		int _pos = 0;
	public:
		relayManagement();
		~relayManagement(){};

		void create 	(int value, int & result);

		void setPullup 	(boolean value);
		void setPullup 	(int pos, boolean value);

		relayClass * relay(int pos);
	};

#endif // RELAY_H