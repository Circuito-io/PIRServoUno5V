#include "Global.h"

#define ServoFirstPosition	20
#define ServoSecondPosition	150

void setup() 
{
	Serial.begin(9600);
	
	servo.attach(SERVO_SIGNAL_PIN);
	servo.write(ServoFirstPosition);
	
	Serial.println("start");
}

void loop() 
{	
	if(pir.read())
	{
		Serial.println("PIR on");
		servo.write(ServoSecondPosition);
		delay(500);
		servo.write(ServoFirstPosition);
		delay(4000); //4 second is the minimum time required for stabilize spakrFun PIR signal after servo movement
	}
 
	delay(100);
}
