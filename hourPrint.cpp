#include <BitbloqLiquidCrystal.h>
#include <Servo.h>
#include <BitbloqButtonPad.h>
#include <Wire.h>
#include <BitbloqRTC.h>

LiquidCrystal lcd(0);
const int led = 7;
Servo servo;
ButtonPad botonera(A3);
const int boton = 3;
RTC_DS1307 reloj_tiempo_real;



void setup() {
    lcd.begin(16, 2);
    lcd.clear();
    pinMode(led, OUTPUT);
    servo.attach(11);
    pinMode(boton, INPUT);

}

void loop() {
    lcd.setBacklight(HIGH);
    lcd.print("Hola");
    char text = botonera.read();
    if (text == "test") {
        lcd.print("test");
    } else if (text == "hora") {
        lcd.setBacklight(LOW);
        lcd.clear();
        lcd.print("Ejemplo");
        reloj_tiempo_real.adjust(DateTime(__DATE__, __TIME__));
        String hora = reloj_tiempo_real.getDate();
        hora = "";
        lcd.setCursor(2, 0);
        lcd.print("$hora");
    }
}