/*
  Button

  Turns on and off a light emitting diode(LED) connected to digital pin 13,
  when pressing a pushbutton attached to pin 2.

  The circuit:
  - LED attached from pin 13 to ground through 220 ohm resistor
  - pushbutton attached to pin 2 from +5V
  - 10K resistor attached to pin 2 from ground

  - Note: on most Arduinos there is already an LED on the board
    attached to pin 13.

  created 2005
  by DojoDave <http://www.0j0.org>
  modified 30 Aug 2011
  by Tom Igoe

  This example code is in the public domain.

  https://www.arduino.cc/en/Tutorial/BuiltInExamples/Button
*/

// constants won't change. They're used here to set pin numbers:
const int pines[8] = {2, 3, 4, 5, 6, 7 ,8, 9};     
int i;

void setup() {
  // inicializar pines de entrada digital
  Serial.begin(9600);
  for(i = 0; i<= 7; i++){
    pinMode(pines[i], INPUT);
  }
  // initialize the pushbutton pin as an input:
  // pinMode(buttonPin, INPUT);
}

void loop() {
  int valor = 0;
  for(i=0; i<=7; i++){
    int valori= digitalRead(pines[i]);
    valor += valori;
    Serial.print(valori);
  }
  Serial.println();
  Serial.println(valor);


  int sensorValue = analogRead(A0);
  // print out the value you read:
  Serial.println(sensorValue);
  delay(100);        // delay in between reads for stability

//  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
//  if (buttonState == HIGH) {
//    // turn LED on:
//    digitalWrite(ledPin, HIGH);
//  } else {
//    // turn LED off:
//    digitalWrite(ledPin, LOW);
//  }
}
