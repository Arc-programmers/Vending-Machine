// Motor connections to Arduino pins
const int ENA = 9;  // Enable Pin for Motor A
const int IN1 = 8;  // Input Pin 1 for Motor A
const int IN2 = 7;  // Input Pin 2 for Motor A

void setup() {
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    int speed_percent = Serial.parseInt();
    speed_percent = constrain(speed_percent, -100, 100); // Limit speed to -100 to 100

    if (speed_percent > 0) {
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      analogWrite(ENA, map(speed_percent, 0, 100, 0, 255));
    } else if (speed_percent < 0) {
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      analogWrite(ENA, map(-speed_percent, 0, 100, 0, 255));
    } else {
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, LOW);
      analogWrite(ENA, 0);
    }
  }
}
