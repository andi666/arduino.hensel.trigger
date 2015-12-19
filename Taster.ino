/**************************************************************
Taster abfragen , mit Entprellung

... ist HIGH, beia Auloesung wird er LOW
***************************************************************/ 
void taster() {
    int reading = digitalRead(buttonPin);  
    if (reading != lastButtonState) {
        lastDebounceTime = millis(); // reset the debouncing timer
    }
    if ((millis() - lastDebounceTime) > debounceDelay) {
        if (reading != buttonState) { // if the button state has changed:
            buttonState = reading;
            if (buttonState == LOW) {
              
                signalausloesen(); // *** fire!
                lcd.setCursor(0,3);
                
                lcd.print("Aktion!");
                //Serial.println();
                Serial.println(">Aktion!");
                Serial.println(code);
                LCD_aktion = millis();
            }
        }
    }
    lastButtonState = reading;

}

