//-------------ANDRADE GUEVARA RONNI ESTEBAN--------------------
//Estimados estudiantes, inicialice la matriz de tipo int y 
// lo siguiente, envie por mensaje serial el resultado de cada ítem. 
// 1. Encuentre el promedio de cada fila.
// 2. Encuentre el promedio de cada columna. 
// 3. Encuentre el número más alto de cada fila 
// 4. Ecnuentre el número más bajo de cada columna 
// 5. Encuentre el número más alto de toda la matriz. 
//6. Encuentre el número más bajo de toda la matriz. 
// Se debe subir un solo programa en la actividad creada con métodos de cada ítem.
int x;//variable para almacenar datode la matiz
float y;//variable para almacenar promedio tipo float 
int i = 0;//para contar pas posiciones del for
int j = 0;
int mayor = 0;
int menor = 0;
int  men, may = 0;

int datos [10][4] = {//matriz asignada
  {3, 5, -6, 7},
  {3, 8, 6, 17},
  {2, -4, 4, 27},
  {2, 4, 8, 10},
  {2, 4, -2, 5},
  {4, 5, 6, 7},
  {5, -8, 6, -7},
  {1, 5, 16, 8},
  {0, 5, 12, 7},
  {44, 5, 16, 7}
};
void setup() {
  Serial.begin(9600);//inicializar el serial
}

void loop() {
  masalto();//metodo para encontrar el numero mas alto de la matriz 
  menormatriz();//metodo para encontrar el numero menor de la matriz 


  promfilas();//metodo para encontrar el numero mas alto de las filas

  promcolumnas();//metodo para encontrar el numero menor de las columnas 

}
void promcolumnas() {
  for (; j < 4; j++) {//contador de las columnas
    for (; i < 10; i++) {//contador de las filas
      x = datos[i][j];//x es donde se guarda el dato de la posicion i j
      Serial.println(x);//imprmir el dato para verificar
      y += x;//sumar el numero con el numero siguiente y guardalo en esa variable
      if (datos[i][j] < menor ) {//condicion para ver si es menor el numero
        menor = datos[i][j];//si es menor guardar en la variable menor 
      }
    }

    Serial.print(" el promedio columna es :  ");
    Serial.println(y / 10);//como son 10 filas /10 y se saca el promedio y se imprime
    delay(2000);// tiempo de espera
    Serial.print("El menor columna es:  ");
    Serial.println(menor);// se imprime el numero menor de cada columna
    delay(2000);
    i = 0;//para que pueda seguir el proximo numero del for
    y = 0;//el promedio vuelve a 0
    menor = 0;
  }
  j = 0;
}
void promfilas() {
  for (; i < 10; i++) {
    for (; j < 4; j++) {
      x = datos [i][j];
      Serial.print(x);
      Serial.print(" ");
      y = y + x;
      if (datos[i][j] > mayor) {//si es mayor a 0 el dato tomado entra el if
        mayor = datos[i][j];//se guarda el dato
      }

    }
    Serial.println(" ");
    Serial.print(" el promedio fila es:   ");
    Serial.println(y / 4);
    delay(2000);
    Serial.print("El mayor fila es:  ");
    Serial.println(mayor);
    delay(2000);
    j = 0;
    y = 0;
    mayor = 0;
  }
  i = 0;
}
void masalto() {
  for (; i < 10; i++) {
    for (; j < 4; j++) {
      if (datos[i][j] > may) {
        may = datos[i][j];//se guarda el dato pero no se lo encera para que al proximo for siga con el numero mayor
      }

    }
    Serial.print("EL + DE LA FILA ES:    ");
    Serial.println(may);
    delay(2000);
    j = 0;
  }
  Serial.print("EL  MAYOR DE LA MATRIZ ES:   ");
  Serial.println(may);
  delay(2000);
  i = 0;
  may = 0;
}
void menormatriz() {
  for (; i < 10; i++) {
    for (; j < 4; j++) {
      if (datos[i][j] < men) {
        men = datos[i][j];
      }

    }
    Serial.print("EL -DE LA FILA ES:    ");
    Serial.println(men);
    delay(2000);
    j = 0;
  }
  Serial.print("EL  MENOR DE LA MATRIZ ES:   ");
  Serial.println(men);
  delay(2000);
  i = 0;
  men = 0;//para que en una segunda vez de todos los metodos no se quede el ultimo dato 
}


