#include <LiquidCrystal.h>
#include <TimerOne.h>   // libreria
LiquidCrystal lcd(13, 12, 11, 10, 9, 8); //RS E d4 d5 d6 d7
int led1 = 7;//leds declarados en los pines asignados
int led2 = 6;//leds declarados en los pines asignados
int led3 = 5;//leds declarados en los pines asignados
int led4 = 4;//leds declarados en los pines asignados
int on = 0;// variable para encender o apagar el sistema
int cont = 0;//variable para llevar el contador segundo a segundo
void setup() {
  lcd.begin(16, 2);//empezar el lcd
  attachInterrupt(0, encender, LOW); //interrupcion
  Timer1.initialize(1000000); //1 segundo del timer
  Timer1.attachInterrupt(contador); // metodo para usar el timer1
  pinMode(led1, OUTPUT);//leds declarados como salida
  pinMode(led2, OUTPUT);//leds declarados como salida
  pinMode(led3, OUTPUT);//leds declarados como salida
  pinMode(led4, OUTPUT);//leds declarados como salida

}

void loop() {
  if (cont == 20) {//condicion que si cont llega a 20 encendera led1 e imprimira en la lcd el led que esta encendido y se apagara
    digitalWrite(led1, HIGH);//led se enciende
    lcd.setCursor(0, 1);//posicion que se imprime el mensaje
    lcd.print("primer led on");
    delay(10000);//10 segundos y se apaga
    digitalWrite(led1, LOW);
    lcd.clear();
  }
  if (cont == 25) {//condicion que si cont llega a 20 encendera led1 e imprimira en la lcd el led que esta encendido y se apagara
    digitalWrite(led2, HIGH);//led se enciende
    lcd.setCursor(0, 1);//posicion que se imprime el mensaje
    lcd.print("segundo led on");
    delay(15000);//15 seg y se apaga
    digitalWrite(led2, LOW);
    lcd.clear();
  }
  if (cont == 30) {//condicion que si cont llega a 30 encendera led1 e imprimira en la lcd el led que esta encendido y se apagara
    digitalWrite(led3, HIGH);//led se enciende
    lcd.setCursor(0, 1);//posicion que se imprime el mensaje
    lcd.print("tercer led on");
    delay(5000);//5 seg y se apaga
    digitalWrite(led3, LOW);
    lcd.clear();

  }
  if (cont == 40) {//condicion que si cont llega a 40 encendera led1 e imprimira en la lcd el led que esta encendido y se apagara
    digitalWrite(led4, HIGH);//led se enciende
    lcd.setCursor(0, 1);//posicion que se imprime el mensaje
    lcd.print("cuarto led on");
    delay(5000);//5seg y se apaga
    digitalWrite(led4, LOW);
    lcd.clear();

  }
}
void contador() {
  if (on == 1) {
    cont++;//cont suma en uno
    lcd.setCursor(0, 0);
    lcd.print(cont);
  }
}

void encender() {
  on = 1 - on;//se regresa al valor inicial para on y off
  if (on == 1) {//para encender el sistema
    Serial.println("SISTEMA ON");
    Timer1.start();//empieza el timer 1
  }
  else {
    Serial.println("SISTEMA OFF");//imprime el sistema off
    cont = 0;//encera la variable cont para inicial nuevamente
    delay(300);
    Timer1.stop();//finaliza el timer1
    lcd.clear();//limpioa la lcd
  }
}


