/*

  The circuit:
 * LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * LCD R/W pin to ground
 * LCD VSS pin to ground
 * LCD VCC pin to 5V
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)

 */

// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  lcd.noCursor();
  Serial.begin(9600);
  // Print a message to the LCD.
  pinMode(8, INPUT);
  // lcd.print("hello, world!");
}
int xo[10] = {10,15,20,25,30,39,45,49,52,60};
int xv[10] = {10,15,20,25,30,39,45,49,52,60};

int yo[10] = {1,1,0,1,0,1,1,0,0,1};
int x=0,y=0;
int highScore=0;
int lastButtonState = 0;  
bool gameOn=true,isNeg=false;
int buttonState=0;
void loop() {
      lcd.setCursor(0, 0);
  lcd.print("Hello! Game will");
       lcd.setCursor(0, 1);

  lcd.print("start in 3s");
  delay(3000);

  while(gameOn){
    lcd.clear();
    buttonState = digitalRead(8);
    

    if (buttonState != lastButtonState) {
     if(buttonState==HIGH)
      if(y==0)
       y=1;
       else
       y=0;
    }
    // set the cursor to column 0, line 1
    // (note: line 1 is the second row, since counting begins with 0):

    // print the number of seconds since reset:
    lcd.setCursor(x, y);
    lcd.print("|");
    lastButtonState=buttonState;
   
       for(int i=0;i<10;i++){
         if(x==xo[i] && y==yo[i]){
          gameOn=false;
              lcd.clear();
           break;
         }
         if(xo[i]==0)
           highScore+=1;
         
	     

         if(xo[i]>=0){
        	lcd.setCursor(xo[i], yo[i]);
        	lcd.print("-");
        
         }
         if(xo[i]<0)
           isNeg=true;
         else
           isNeg=false;
               xo[i]=xo[i]-1;
              
         	 Serial.println(xo[i]);
     }
    if(xo[9]<0)
     for(int j=0;j<1;j++)
      xo[j]=xv[j];
    delay(200);
    }
   
  lcd.setCursor(0, 0);
      lcd.print("Game Over");
   lcd.setCursor(0, 1);
  
      lcd.print("Score - ");
  lcd.print(highScore);
 	exit(0);
  
   
}
 