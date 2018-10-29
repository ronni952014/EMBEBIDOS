#include <LiquidCrystal.h> // libreria
LiquidCrystal lcd(13, 12, 11, 10, 9, 8); //RS E d4 d5 d6 d7
String vocal;
int t;
int i = 0;
int j = 0;

void setup() {
  Serial.println("INGRESE DATO");
  Serial.begin(9600);
  lcd.begin(16, 2);

}

void loop() {
  if (Serial.available() > 0) { //solo funciona si existe dato srial
    vocal = Serial.readString(); //guarda el dato
    t = vocal.length();     //t guarda el tamaño de la palabra
    char vector[t + 1];       //crea vector con tamaño t+1
    vocal.toCharArray(vector, t + 1); //se encia el vector con el numero de t
    i = 0;

    for (; i < t + 1; i++) {
      lcd.setCursor(i, 0);
      lcd.print(vector[i]);
      delay(100);
    }

    for (i = 0; i < t + 1; i++) {
      lcd.setCursor(i, 0);
      lcd.print(' ');
      delay(100);
    }
    j = i;

    for (; j >= 0; j--) {
      lcd.setCursor(j, 0);
      lcd.print(vector[j]);
      delay(100);
    }

    for (; j >= 0; j--) {
      lcd.setCursor(j, 0);
      lcd.print(' ');
      delay(100);
    }
    lcd.clear();
  }
}
