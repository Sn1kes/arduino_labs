#include <Arduino.h>

const int buttonPin = 2;
const int ledPin = 13;
const int debounce_period_ms = 150;
unsigned int state;
unsigned long last_time_ms;

void led_int()
{
	unsigned long time_ms = millis();
	if((time_ms - last_time_ms) <= debounce_period_ms) {
		return;
	}
	last_time_ms = time_ms;
	if(state == LOW) {
		digitalWrite(ledPin, LOW);
		state = HIGH;
	} else {
		digitalWrite(ledPin, HIGH);
		state = LOW;
	}
}

void setup()
{
	state = LOW;
	last_time_ms = millis();
	pinMode(buttonPin, INPUT);
	pinMode(ledPin, OUTPUT);
	attachInterrupt(digitalPinToInterrupt(buttonPin), led_int, RISING);
}

void loop()
{
}
