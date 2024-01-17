int relay = 26;
#define DO_PIN 13  // ESP32's pin GPIO13 connected to DO pin of the LDR module
#define DEBOUNCE_DELAY 1000

void setup() {
  Serial.begin(115200);
  pinMode(relay, OUTPUT);
  pinMode(DO_PIN, INPUT);
  digitalWrite(relay, HIGH); // Assuming relay is active LOW, set it HIGH initially
}

void loop() {
  static unsigned long lastDebounceTime = 0;
  int lightState = digitalRead(DO_PIN);

  if (millis() - lastDebounceTime > DEBOUNCE_DELAY) {
    if (lightState == LOW) {
      digitalWrite(relay, LOW); // Turn on the relay
      Serial.println("ON");
    } else {
      digitalWrite(relay, HIGH); // Turn off the relay
      Serial.println("OFF");
    }

    lastDebounceTime = millis();
  }

  delay(50); // Optional delay to prevent excessive loop execution
}
