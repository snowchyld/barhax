   // initialize the LED pins:
  int vodka = 2;
  int gin = 3;
  int tequila = 4;
  int rum = 5;
  int triplesec = 6;
  int sweetnsour = 7;
  int coke = 8;

  int pinCount = 7;
  int oneOunceLiquor = 3000; // 60ml/min=1oz/30sec=1oz/30000ms
  int oneOunceMixer = 1000;  // total guess at this point

  // make the recipes
  int longislandLiquor[] = {vodka, gin, tequila, rum, triplesec};
  int longislandMixer[] = {sweetnsour, coke};
  int rumncokeLiquor[] = {rum};
  int rumncokeMixer[] = {coke};


void setup() {
  // initialize serial communication:
  Serial.begin(9600); 

  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
}

void loop() {
  // read the sensor:
  if (Serial.available() > 0) {
    int inByte = Serial.read();
    // do something different depending on the character received.  
    // The switch statement expects single number values for each case;
    // in this exmaple, though, you're using single quotes to tell
    // the controller to get the ASCII value for the character.  For 
    // example 'a' = 97, 'b' = 98, and so forth:

    switch (inByte) {
    case 'a':    
      // LONG ISLAND ICED TEA
        // LIQUOR
          digitalWrite(vodka,HIGH);
          digitalWrite(gin,HIGH);
          digitalWrite(tequila,HIGH);
          digitalWrite(rum,HIGH);
          digitalWrite(triplesec,HIGH);
          delay(oneOunceLiquor);
          digitalWrite(vodka,LOW);
          digitalWrite(gin,LOW);
          digitalWrite(tequila,LOW);
          digitalWrite(rum,LOW);
          digitalWrite(triplesec,LOW);
        // MIXERS
          digitalWrite(sweetnsour,HIGH);
          digitalWrite(coke,HIGH);
          delay(oneOunceMixer);
          digitalWrite(sweetnsour,LOW);
          digitalWrite(coke,LOW);
      break;
    case 'b':  
      // RUM AND COKE  
        // LIQUOR
          for (int thisPin = 0; thisPin < pinCount; thisPin++) { 
          // turn the pin on:
          pinMode(rumncokeLiquor[thisPin],OUTPUT);
          digitalWrite(rumncokeLiquor[thisPin], HIGH);   
          }
          delay(oneOunceLiquor);                  
            // turn the pin off:
          for (int thisPin = 0; thisPin < pinCount; thisPin++) { 
            digitalWrite(rumncokeLiquor[thisPin], LOW);
          }
        // MIXER
          for (int thisPin = 0; thisPin < pinCount; thisPin++) { 
          // turn the pin on:
          pinMode(rumncokeMixer[thisPin],OUTPUT);
          digitalWrite(rumncokeMixer[thisPin], HIGH);   
          }
          delay(oneOunceMixer);                  
            // turn the pin off:
          for (int thisPin = 0; thisPin < pinCount; thisPin++) { 
            digitalWrite(rumncokeMixer[thisPin], LOW);
          }
      break;
    case 'c':    
      digitalWrite(4, HIGH);
      break;
    case 'd':    
      digitalWrite(5, HIGH);
      break;
    case 'e':    
      digitalWrite(6, HIGH);
      break;
    case 'f':    
      digitalWrite(7, HIGH);
      break;
    case 'g':    
      digitalWrite(8, HIGH);
      break;
    default:
      // turn all the LEDs off:
      for (int thisPin = 2; thisPin < 9; thisPin++) {
        digitalWrite(thisPin, LOW);
      }
    } 
  }
}
