const int relayPin1 = 5; // GPIO5 (D1 on NodeMCU)
const int relayPin2 = 4; // GPIO4 (D2 on NodeMCU)
const int speedUpPin = 0; // GPIO0 (D3 on NodeMCU, adjust if different)
const int speedDownPin = 2; // GPIO2 (D4 on NodeMCU, adjust if different)
const int instantPin = 14; // GPIO14 (D5 on NodeMCU, adjust if different)
const int defaultPin = 12; // GPIO12 (D6 on NodeMCU, adjust if different)
const int activeLowPin = 13; // GPIO13 (D7 on NodeMCU, adjust if different)
const int activeHighPin = 15; // GPIO15 (D8 on NodeMCU, adjust if different)

int delayTime = 10000; // Initial delay time in milliseconds
bool instant = false;

void setup() {
  pinMode(relayPin1, OUTPUT);
  pinMode(relayPin2, OUTPUT);
  pinMode(speedUpPin, INPUT_PULLUP);
  pinMode(speedDownPin, INPUT_PULLUP);
  pinMode(instantPin, INPUT_PULLUP);
  pinMode(defaultPin, INPUT_PULLUP);
  pinMode(activeLowPin, OUTPUT);
  pinMode(activeHighPin, OUTPUT);
  
  digitalWrite(relayPin1, HIGH);
  digitalWrite(relayPin2, HIGH);
}

void loop() {
  if (!digitalRead(speedUpPin)) {
    delayTime += 1000; // Increase delay by 1 second
    while(!digitalRead(speedUpPin)); // Wait for button release
  }
  if (!digitalRead(speedDownPin)) {
    delayTime -= 1000; // Decrease delay by 1 second
    delayTime = max(0, delayTime); // Ensure delayTime doesn't go negative
    while(!digitalRead(speedDownPin)); // Wait for button release
  }
  if (!digitalRead(instantPin)) {
    instant = true;
    while(!digitalRead(instantPin)); // Wait for button release
  }
  if (!digitalRead(defaultPin)) {
    instant = false;
    delayTime = 10000; // Reset to default delay time
    while(!digitalRead(defaultPin)); // Wait for button release
  }

  digitalWrite(relayPin1, LOW);
  digitalWrite(relayPin2, HIGH);
  setIndicatorPins(LOW);
  if (!instant) delay(delayTime);
  
  digitalWrite(relayPin1, HIGH);
  digitalWrite(relayPin2, LOW);
  setIndicatorPins(LOW);
  if (!instant) delay(delayTime);
  else delay(1); // Minimal delay to ensure the loop continues smoothly
}

void setIndicatorPins(bool relayState) {
  digitalWrite(activeLowPin, relayState);
  digitalWrite(activeHighPin, !relayState);
  if (instant) {
    digitalWrite(activeLowPin, LOW); // Always LOW if in instant mode
    digitalWrite(activeHighPin, HIGH); // Always HIGH if in instant mode
  }
}
