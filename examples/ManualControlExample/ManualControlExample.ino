#include "ERG.h"

void setup() {
    Serial.begin(9600);

    controlLine(700); // Желаемая линия 700
    manualControl(1.5); // Вручную устанавливаем коэффициент усиления 1.5
}

void loop() {
    float sensorValue = analogRead(A0);
    int controlSignal = outputERG(sensorValue);

    Serial.print("Sensor: ");
    Serial.print(sensorValue);
    Serial.print(" | Manual Control Output: ");
    Serial.println(controlSignal);

    delay(100);
}
