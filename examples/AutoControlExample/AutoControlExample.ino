#include "ERG.h"

void setup() {
    Serial.begin(9600);

    controlLine(600); // Желаемая линия 600
    autoControl("ON", "OFF", 5); // Включаем автоматический режим без инерции с шагом 5
}

void loop() {
    float sensorValue = analogRead(A0);
    int controlSignal = outputERG(sensorValue);

    Serial.print("Sensor: ");
    Serial.print(sensorValue);
    Serial.print(" | Auto Control Output: ");
    Serial.println(controlSignal);

    delay(100);
}
