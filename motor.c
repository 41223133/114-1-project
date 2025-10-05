#include <Arduino.h>
#include "motor.h"

static int motor_pin = -1;
static bool is_init = false;

void motor_init(int pin) {
    motor_pin = pin;
    ledcSetup(0, 50, 16);
    ledcAttachPin(motor_pin, 0);
    is_init = true;
}

void motor_open() {
    if (!is_init) return;
    int duty_us = 2500;
    ledcWrite(0, duty_us * 65535 / 20000);
}

void motor_close() {
    if (!is_init) return;
    int duty_us = 500;
    ledcWrite(0, duty_us * 65535 / 20000);
}