void blink(int count, int highLength = 250, int lowLength = 250) {
  
  pinMode(LED_BUILTIN, OUTPUT);
  for (int i = 0; i < count; i++) {
    digitalWrite(LED_BUILTIN, HIGH);
    delay(highLength);
    digitalWrite(LED_BUILTIN, LOW);
    delay(lowLength);
  }
  delay(1000);
}

