#include"datos_entrenamiento.h"
#include"datos_test.h"
int fila, col = 0;
int cont = 1;
int n = 0;
float distan ;
float dismenor = 10000;
int fp = 10;
int m[0] ;
void setup() {
  Serial.begin(9600);
  Serial.println("===============================================");
  Serial.println("===                   KKN                   ===");
  Serial.println("===============================================");
  delay(500);

}

void loop() {
  distancia();
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
void distancia() {
  for (; cont < 2; cont++) {
    for (; fila < 120; fila++) {//CONTADOR DE COLUMNAS


      distan = sqrt(pow((matriz[fila][0] - prueba[fp][0]), 2) +
                    pow((matriz[fila][1] - prueba[fp][1]), 2 ) +
                    pow((matriz[fila][2] - prueba[fp][2]), 2 ) +
                    pow((matriz[fila][3] - prueba[fp][3]), 2));
      fp++;
      if (distan < dismenor) {
        dismenor = distan;
        n = matriz[fila][4];
      }
    }
    if (fp == 12) {
      fp = 0;
    }
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





