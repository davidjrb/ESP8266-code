// Define the GPIO pins for the relays
const int relayPin1 = 5; // Relay 1 connected to GPIO5 (D1)
const int relayPin2 = 4; // Relay 2 connected to GPIO4 (D2)

void setup() {
  // Initialize the relay pins as outputs
  pinMode(relayPin1, OUTPUT);
  pinMode(relayPin2, OUTPUT);

  // Start with both relays deactivated (open)
  digitalWrite(relayPin1, HIGH);
  digitalWrite(relayPin2, HIGH);
}

void loop() {
  // Activate relay 1 (close)
  digitalWrite(relayPin1, LOW);
  // Deactivate relay 2 (open)
  digitalWrite(relayPin2, HIGH);
  // Wait for 10 seconds
  delay(10000);

  // Deactivate relay 1 (open)
  digitalWrite(relayPin1, HIGH);
  // Activate relay 2 (close)
  digitalWrite(relayPin2, LOW);
  // Wait for 10 seconds
  delay(10000);
}
