/*
  Library Lego PF. 
  
  For PF motors M,L y XL, if yoy want control speed, you must used PWM ouputs in pinA and pinB. 
  For servo motor, PWM outputs for pinA and pinB.
  
  Copyright (c) 2015, Gonzalo Galván Alonso

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/


#if ARDUINO >= 100
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif

#include "LegoPF.h"

void LegoPF::addMotor(int id, int enablePin, int pinA, int pinB) {

	if(id>=0 && id <9) {
		motors[id] = (motorType) {enablePin, pinA, pinB};	
		pinMode(enablePin, OUTPUT);
		pinMode(pinA, OUTPUT);
		pinMode(pinB, OUTPUT);
		
	}
}
	
void LegoPF::enable(int id) {
	motorType motor = motors[id];
	digitalWrite(motor.enablePin, HIGH);
}

void LegoPF::disable(int id){
	motorType motor = motors[id];
	digitalWrite(motor.enablePin, LOW);
}

//L,M and XL MOTORS

void LegoPF::stop(int id){
	motorType motor = motors[id];
	digitalWrite(motor.pinA, LOW);
	digitalWrite(motor.pinB, LOW);
}

void LegoPF::fullForward(int id){
	motorType motor = motors[id];
	digitalWrite(motor.pinA, LOW);
	digitalWrite(motor.pinB, HIGH);
}

void LegoPF::fullBackward(int id){
	motorType motor = motors[id];
	digitalWrite(motor.pinA, HIGH);
	digitalWrite(motor.pinB, LOW);
}

//Motor: PWM 80-255
void LegoPF::forward(int id, int percent){
	motorType motor = motors[id];
	int value = 0;
	if(percent <=0)  {
		value= 0;
	} else if(percent>=100) {
		value = 255;
	} else {
		value = 80+percent*1.75;
	}
	
	digitalWrite(motor.pinA, LOW);
	analogWrite(motor.pinB, value);
}

void LegoPF::backward(int id, int percent){
	motorType motor = motors[id];
	int value = 0;
	if(percent <=0)  {
		value= 0;
	} else if(percent>=100) {
		value = 255;
	} else {
		value = 80+percent*1.75;
	}
	
	analogWrite(motor.pinA, value);
	digitalWrite(motor.pinB, LOW);
}

//SERVO MOTOR

void LegoPF::center(int id) {
	motorType motor = motors[id];
	analogWrite(motor.pinA, 0);
	analogWrite(motor.pinB, 0);
}

void LegoPF::fullLeft(int id) {
	motorType motor = motors[id];
	analogWrite(motor.pinA, 255);
	analogWrite(motor.pinB, 0);
}
void LegoPF::fullRight(int id) {
	motorType motor = motors[id];
	analogWrite(motor.pinA, 0);
	analogWrite(motor.pinB, 255);
}

//Motor: PWM 66-255
void LegoPF::left(int id, int percent){
	motorType motor = motors[id];
	int value = 0;
	if(percent <=0)  {
		value= 0;
	} else if(percent>=100) {
		value = 255;
	} else {
		value = 66+percent*1.89;
	}
	
	digitalWrite(motor.pinA, LOW);
	analogWrite(motor.pinB, value);
}

void LegoPF::right(int id, int percent){
	motorType motor = motors[id];
	int value = 0;
	if(percent <=0)  {
		value= 0;
	} else if(percent>=100) {
		value = 255;
	} else {
		value = 66+percent*1.89;
	}
	
	analogWrite(motor.pinA, value);
	digitalWrite(motor.pinB, LOW);
}

