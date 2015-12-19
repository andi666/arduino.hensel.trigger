/*******************************************************************
hensel blitzauslaoesung v0.2

ausloeser fuer hensel-blitzgeraete (Hensel 500 Expret Pro Plus)  
Flash Triger 433.9MHz

16-DEZ-2015 andreas langkath , info@langkath.de

only for fun , under MIT license

youtube: 	https://youtu.be/CqZ-lnsnEj4
code:			https://github.com/andi666/arduino.hensel.trigger


2do / wer lust hat:
kann z.b. an pin #6 noch eine kamera-anschluss anbinden.
dieser loest immer auf dem eingestellten kanals den blitz aus

die letzte kanal-einstellung in den flashspeicher ablegen
beim naechsten start wird die letzte einstellung geladen

kleines oled anstatt dem lcd anbinden

durch zufall habe ich scheinbar ein hidden feature gefunden:
pro kanal kann die halogen-lampe in drei stufen eingestellt werden.
das ist bei der originalen fb nicht implementiert.
hier ein paar daten. mehr weiss ich noch nicht:
TEST:
.11111 001001101010000011111
..11111 00100110101000001111
...11111 0010011010100000111
...111111 001001101010000011
logic-tester-diagram:      .. 11111111110010011010100000 11111111110010011010100000 11111111110010011010100000 11....
damit wurde es bei einem kanal ausgeloest.. 
*********************************************************************************************/
#include <Encoder.h>
#include <Wire.h>   
#include <LiquidCrystal_I2C.h> // *** i2c-LCD!! -> SCL = A5 , SDA = A4
 
LiquidCrystal_I2C lcd(0x3F, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);  // Set the LCD I2C address
//LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);  // Set the LCD I2C address

static int TxPin = 6; // *** Pin.D6 = Tx
 
Encoder knobRotary(2, 3); // *** CLK = D2 , DT = D3 

char* code ="10100110010100111";
int anazhl;
int n;
const int buttonPin = 4;  // *** SW = D4
int buttonState;             // the current reading from the input pin
int lastButtonState = HIGH;   // the previous reading from the input pin
long lastDebounceTime = 0;  // the last time the output pin was toggled
long debounceDelay = 20;    // the debounce time; increase if the output flickers
int art=0; // 0= flash , 1 = power

int pos;
int Menue = 13;
long newRotary;
long positionRotary  = -999;
char* ModusName;
char* ModusAktion;
unsigned long LCD_aktion;
unsigned long Millis; 
unsigned long LCD_PreviousMillis;
long LCD_interval = 500; // *** LCD aktualisierung in ms

int LED_pin = 13;  // *** LED HERZSCHLAG
int LED_status = LOW;  // *** used to set the LED
long LED_setZeit = 0;  // *** will store last time LED was updated
long LED_interval = 666;  // *** (1000) LED-HERZSCHALG-Intervall (milliseconds)
int alte_sekunde; 

byte Herz[8] = {
  B00000,
  B01010,
  B11111,
  B01110,
  B00100,
  B00000,
  B00000,
  B00000
};



void setup() {
 
   
   Serial.begin(57600); // *** 9600, 57600
   Serial.println();
   Serial.println(">start.");
   
   pinMode(LED_pin, OUTPUT); // *** für LED HERZSCHLAG
   lcd.begin(20,4);   // initialize the lcd for 20 chars 4 lines, turn on backlight (muss vor der Sonderzeichendefinierung stehen!)
   lcd.createChar(1,Herz); // *** eigene Sonder-Zeichen erstellen
   
   pinMode(buttonPin, INPUT);  // *** Taster aktivieren
   pinMode(TxPin, OUTPUT);  // *** Tx

   digitalWrite(TxPin, LOW );
    
   lcd.clear();
   //*** blink backlicht ****************************************
  for(int i = 0; i< 3; i++)  {
    lcd.backlight();
    delay(250);
    lcd.noBacklight();
    delay(250);
  }
  lcd.backlight(); 
 
 
  
}  
 
void loop() {
   
  LED_HERZSCHLAG();    
  taster();
  encoder(); 
  ModusAendern();
  LCD_Ausgabe() ;
  
  
}  

