/* Copyright (c) 2013 BlackBerry.
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 * http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
 
#include <SoftwareSerial.h>   //Software Serial Port

int relays[] = { 8, 9, 10, 11 };

#define RxD    3
#define TxD    2

SoftwareSerial blueToothSerial(RxD,TxD);

void dumpBt() {
  delay(250);
  Serial.println("From BT:");
    while(blueToothSerial.available()) {
      Serial.write(blueToothSerial.read());
    }

  Serial.println("Done");
}

void setupBlueToothConnection()
{
    blueToothSerial.begin(38400);                           // Set BluetoothBee BaudRate to default baud rate 38400
    delay(1000);
    dumpBt();
    blueToothSerial.print("\r\n+STWMOD=0\r\n");             // set the bluetooth work in slave mode
    dumpBt();
    blueToothSerial.print("\r\n+STNA=SeeedBTSlave\r\n");    // set the bluetooth name as "SeeedBTSlave"
    dumpBt();
    blueToothSerial.print("\r\n+STOAUT=1\r\n");             // Permit Paired device to connect me
    dumpBt();
    blueToothSerial.print("\r\n+STAUTO=0\r\n");             // Auto-connection should be forbidden here
    dumpBt();
    
    delay(2000);                                            // This delay is required.
    blueToothSerial.print("\r\n+INQ=1\r\n");                // make the slave bluetooth inquirable
    Serial.println("The slave bluetooth is inquirable!");
    delay(2000);                                            // This delay is required.
    blueToothSerial.flush();
}

int incomingByte = 0; // for incoming serial data
int incomingByteCommand = 0; // for incoming serial data
int i=0;
char commandbuffer[100];


void setup()
{
  Serial.begin(9600);
  Serial.println("Hello from serial\n");
  
  setupBlueToothConnection();
  
  for (uint8_t i=0; i<4; ++i) {
    pinMode(relays[i],OUTPUT);
    digitalWrite(relays[i],LOW);
  }

  //for testing purposes
  for (uint8_t i=0; i<4; ++i) {
    digitalWrite(relays[i],HIGH);
    delay(1000);
    digitalWrite(relays[i],LOW);
  }
}

void bluetoothControl() {
  Serial.println("Starting interactive BT control");
  int c;
  while(true) {
    if (Serial.available() > 0) {
      c = Serial.read();
      if (c==27) {
        break;
      }
      if (c=='[') {
        blueToothSerial.write('\r');
        blueToothSerial.write('\n');
      } else {
        blueToothSerial.write(c);
      }
    }
    if (blueToothSerial.available()>0) {
      c = blueToothSerial.read();
      Serial.write(c);
    }
  }
  Serial.println("Finished session.");
}

void loop()
{
  if (Serial.available() > 0) {
    int c = Serial.read();
    if (c=='I') {
      Serial.println("Re-Initializing");
      setup();
    } else if (c=='B') {
      bluetoothControl();
    }
  }
  if (blueToothSerial.available() > 0) {
    // read the incoming byte:
    incomingByte = blueToothSerial.read();
    Serial.print("Read: ");
    Serial.write(incomingByte);
    Serial.println();
    
    if (incomingByte=='+') {
      Serial.println("Reading BT status");
      Serial.write(incomingByte);
      while(true) {
        while(!blueToothSerial.available()) {
        }
        int c = blueToothSerial.read();
        if (c==10) {
          Serial.println();
          Serial.println("End of Command");
          break;
        }
        if (c>=' ') {
          Serial.write(c);
        }
      }
    } else if (incomingByte == 'A') {
    //heartbeat code just to keep the BT connection running.
      blueToothSerial.print("H");
    } else if (incomingByte >= '1' && incomingByte <= '4') {
      int which = incomingByte-'1';
      while(!blueToothSerial.available())
      {
      }
      incomingByteCommand  = blueToothSerial.read();
      
      Serial.print("Responding to ");
      Serial.write(which+'1');
      Serial.write(incomingByteCommand);
      Serial.println();
      
      digitalWrite(relays[which],incomingByteCommand=='1');
    }
    else if(incomingByte == '0') //Lets kill all the lights
    {
      for (int i=0; i<4; ++i) {
        digitalWrite(relays[i],LOW);
      }
    }
    else if (incomingByte < ' ') {
      // do nothing.
    }
    else
    {
      // say what you got:
      Serial.print("Unhandled character: ");
      Serial.write(incomingByte);
      Serial.print(" ");
      Serial.print(incomingByte);
      Serial.println();
    }
  }
}


