#include"datos_entrenamiento.h"
#include"datos_test.h"
int fila, col = 0;
int cont = 1;
int c = 0;
int n = 0;
float distan ;
float dismenor = 10000;
int fp = 15;
int res[100] ;
int pos[100] ;


void setup() {
  Serial.begin(9600);
  Serial.println("===============================================");
  Serial.println("===                   KKN                   ===");
  Serial.println("===============================================");
  delay(500);

}

void loop() {
  distancia(5);
  leer();
}
void leer() {
  for (; fila < 120; fila++) {//CONTADOR DE FILAS
    for (; col < 5; col++) {//CONTADOR DE COLUMNAS
      Serial.print(matriz[fila][col]);
      Serial.print(',');
      delay(25);
    }
    col = 0;
    Serial.println(' ');
  }
}
void distancia(int k) {
  for (; cont < 2; cont++) {
    for (; fila < 120; fila++) {//CONTADOR DE COLUMNAS


      distan = sqrt(pow((matriz[fila][0] - prueba[fp][0]), 2) +
                    pow((matriz[fila][1] - prueba[fp][1]), 2 ) +
                    pow((matriz[fila][2] - prueba[fp][2]), 2 ) +
                    pow((matriz[fila][3] - prueba[fp][3]), 2));
        if (distan < 1) {
        c++;
        dismenor = distan;
        n = matriz[fila][4];
        Serial.print(c);
        Serial.print("  ");
        Serial.println(distan);
        if (c == 5) {
          Serial.print("  ");
          Serial.print(n);
          Serial.print("  ");
          c = 0;
        }
      }

    }
    //    if (fp == 21) {
    //      fp = 0;
    //    }
    if (n == 1) {
      Serial.print("El grupo es: 1 = iris_setosa");

    }
    if (n == 2) {
      Serial.print("El grupo es: 2=iris_versicolor");

    }
    if (n == 3) {
      Serial.print("El grupo es: 3=iris_virginica");

    }
  }
}



