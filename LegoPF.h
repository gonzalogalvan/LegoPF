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


/*

   Usage:
      LegoPF lego();
	  
	  lego.addMotor(8,9,10);
	  
	  lego.enable(0);
	  lego.fullForward(0);
	  lego.disable(0);
     


*/

#ifndef LegoPF_H
#define LegoPF_H

#if ARDUINO >= 100
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif

class LegoPF {
	
   private:
	
	typedef struct
	 {
		 int enablePin;
		 int pinA;
		 int pinB;
	 }  motorType;
 
	motorType motors[8];
	
  public:
 
    void addMotor(int id, int enablePin, int pinA, int pinB);

	void enable(int id);
	void disable(int id);
	void stop(int id);
	void fullForward(int id);
	void fullBackward(int id);
    void forward(int id, int percent);
	void backward(int id, int percent);
	
	void center(int id);
	void fullLeft(int id);
	void fullRight(int id);
	void left(int id, int percent);
	void right(int id, int percent);
	
};


#endif  //LegoPF_H
