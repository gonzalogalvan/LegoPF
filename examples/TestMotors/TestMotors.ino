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


#include <LegoPF.h>

boolean run;
LegoPF lego;

void setup() {
 
  lego.addMotor(0,50,10,11);
  lego.addMotor(1,40,8,9);
  run = true;
  Serial.begin(9600); 
}

void loop() {

  if(run){

      Serial.println("enable");
      lego.enable(0);

      delay(5000);
      Serial.println("fullForward");
      lego.fullForward(0);

      delay(5000);
      Serial.println("stop");
      lego.stop(0);

      delay(5000);
      Serial.println("fullBackward");
      lego.fullBackward(0);
      
      delay(5000);
      Serial.println("stop");
      lego.stop(0);

      delay(5000);
      Serial.println("forward 50%");
      lego.forward(0,50);

      delay(5000);
      Serial.println("stop");
      lego.stop(0);

      delay(5000);
      Serial.println("backward 50%");
      lego.backward(0,50);
      
      delay(5000);
      Serial.println("disable");
      lego.disable(0);


      Serial.println("Servo enable");
      lego.enable(1);

      delay(5000);
      Serial.println("Servo fullLeft");
      lego.fullLeft(1);

      delay(5000);
      Serial.println("Servo stop");
      lego.stop(1);

      delay(5000);
      Serial.println("Servo fullRightkward");
      lego.fullRight(1);
      
      delay(5000);
      Serial.println("Servo stop");
      lego.stop(1);

      delay(5000);
      Serial.println("Servo left 50%");
      lego.left(1,50);

      delay(5000);
      Serial.println("Servo stop");
      lego.stop(1);

      delay(5000);
      Serial.println("Servo right 100%");
      lego.right(1,100);
      delay(5000);
      Serial.println("Servo right 75%");
      lego.right(1,75);
      delay(5000);
      Serial.println("Servo right 50%");
      lego.right(1,50);

      delay(5000);
      Serial.println("Servo right 25%");
      lego.right(1,25);

      delay(5000);
      Serial.println("Servo right 0%");
      lego.right(1,0);
      
      delay(5000);
      Serial.println("Servo disable");
      lego.disable(1);
      
  }
  run = false;
}
