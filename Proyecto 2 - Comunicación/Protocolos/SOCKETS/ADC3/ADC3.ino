const int pines[8] = {2, 3, 4, 5, 6, 7, 8, 9};
int i;

void setup() {
  // Initialize serial communication at 9600 baud
  Serial.begin(9600);
  for (i = 0; i <= 7; i++) {
    pinMode(pines[i], INPUT);
  }
}

void loop() {
  int valor = 0;
  for (i = 0; i <= 7; i++) {
    int valori = digitalRead(pines[i]);
    valor += valori;
    Serial.print(valori);
  }
  Serial.println();
  Serial.println(valor);

  int sensorValue = analogRead(A0);
  // Print out the value you read:
  Serial.println(sensorValue);
  delay(100); // Delay in between reads for stability
}
