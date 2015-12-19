void signalausloesen(){
    
    if (art == 0) { // *** blitz
      fire_init();
      fire_code();
    }
    if (art == 1) { // *** power up/down
      fire_init();
      fire_init();
      fire_code();
      fire_init();
      fire_code();
      fire_init();
      fire_code();
      fire_init();
    }
    digitalWrite(TxPin, LOW );
    
}

void fire_code(){ // *** code absenden
  
    anazhl = strlen(code);  
    n = 0;
    while (n < anazhl){
 
        if ( code[n] == 49 ) {
          digitalWrite(TxPin, HIGH );
          delayMicroseconds(11);  // 10
        } else {
          digitalWrite(TxPin, LOW );  
          delayMicroseconds(12); // *** LOW ist etwas laenger als HIGH
        }
         
        n++;
    }
     
}

void fire_init(){ // *** init absenden
  
    char* init ="11111111"; // *** 8x Initbit (ist immer gleich)
    anazhl = strlen(init);  
    n = 0;
    while (n < anazhl){
        digitalWrite(TxPin, HIGH );
        delayMicroseconds(11);  // 10
        n++;
    }
}
    
 

