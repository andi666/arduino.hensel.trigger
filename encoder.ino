void encoder() {

  // *** rotary encoder abfragen *************************************
  newRotary = knobRotary.read();  
  if (newRotary != positionRotary) {  
          // *** mindestens zwei rasterungen pro wertaenderung. bei den billigen
          // encodern werden sonst zu viele positionen uebersprungen.
          // wer es richtig machen will, nimmt einen encoder von ALPS
          
          if (newRotary > positionRotary) {
             // rechts
             pos++;
          }
          if (newRotary < positionRotary) {
             // links
             pos--;
          }
          positionRotary = newRotary;

          if( pos > 104) pos = 8;   // 128
          if( pos < 8) pos = 104;   // 128
          
          Menue = pos/7.5; // *** nicht durch 8! sondern 7.5 (unschaerfe)
          
          Serial.print("Menue [");
          Serial.print(Menue);
          Serial.println("]. ");
   }
}
