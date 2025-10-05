#include "motor.h"
#define RAIN_SENSOR_PIN 25
#define MOTOR_PIN 13
int rain_state;
bool is_init = false;
int motor_pin_global;
// Motor function implementations
void motor_init(int pin) {
  motor_pin_global = pin;
  pinMode(pin, OUTPUT);
  digitalWrite(pin, LOW);
  Serial.println("Motor initialized");
  is_init = true;
}

void motor_open() {
  if (!is_init) return;
  digitalWrite(motor_pin_global, HIGH);
  Serial.println("Motor: OPEN");
}

void motor_close() {
  if (!is_init) return;
  digitalWrite(motor_pin_global, LOW);
  Serial.println("Motor: CLOSE");
}

void setup() {
  Serial.begin(115200);
  pinMode(RAIN_SENSOR_PIN, INPUT);
  motor_init(MOTOR_PIN);
  Serial.println("Rain Detection System Started");
}

void loop() {
  rain_state = digitalRead(RAIN_SENSOR_PIN);
  
  // Reverse the logic: rain detected (LOW) -> open motor, no rain (HIGH) -> close motor
  if (rain_state == LOW) {
    Serial.println("Rain detected! Opening cover...");
    motor_open();
  } else {
    Serial.println("No rain. Closing cover...");
    motor_close();
  }
  
  delay(1000);
}