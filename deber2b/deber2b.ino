#include <LiquidCrystal.h>//libreria
#include <Keypad.h>
LiquidCrystal lcd(13,12,11,10,9,8); //RS E d4 d5 d6 d7 
const byte columnas=4;
const byte filas=4;
char botones [filas][columnas]={{'1','4','7','x'},{'2','5','8','0'},{'3','6','9','='},{'+','-','*','/'}};
byte pines_f[filas] = {3, 2, 1, 0}; 
byte pines_c[columnas] = {7 ,6 ,5 ,4}; 
Keypad miTeclado = Keypad( makeKeymap(botones), pines_f, pines_c, filas, columnas);
boolean v_actual = false;
boolean v_siguiente = false;
boolean final = false;
String n1, n2, n3;
int c_total;
int movimiento;
char operacion;
float r1,r2,r3,r4;
float decimal;
int contador=0;
void setup() {
  lcd.begin(16,2);
  
  }

void loop() {
 char boton = miTeclado.getKey();
 int tam_n; 

//verificacion de los botones
 if (boton != NO_KEY && (boton=='1'||boton=='2'||boton=='3'||boton=='4'||boton=='5'||boton=='6'||boton=='7'||boton=='8'||boton=='9'||boton=='0'))
 {
   // variables que se necesita
   if (contador==1){
      lcd.clear();
      v_actual=false;
      final=false;
      n1="";
      n2="";
      c_total=0;
      operacion=' ';
      contador=0;                  
   }
   if (v_actual != true){
    n1=n1+boton;
    tam_n=n1.length();
    movimiento=tam_n;
    lcd.setCursor(1, 0);
    lcd.print(n1);
    }else{
      n2=n2+boton;
      tam_n=n2.length();
      lcd.setCursor(movimiento+2, 0);
      lcd.print(n2);
      final = true;
      }
      } else if ((boton == '+' || boton == '-' || boton == '*' || boton == '/') && v_actual== false && boton!= NO_KEY)
{
 if (v_actual == false){
    v_actual = true;
    operacion = boton;
    lcd.setCursor(movimiento+1,0);
    lcd.print(operacion);
   }
 } else if (final == true && boton != NO_KEY && boton == '=')
 {
  //aqui se selecciona la operacion que se desea
   switch (operacion) {
    case '+':
      //suma
      c_total = n1.toInt() + n2.toInt();
      break;
    case '-':
      //resta
      c_total = n1.toInt() - n2.toInt();
      break;
    case '*':
      //multiplicacion
      c_total = n1.toInt() * n2.toInt();
      break;
    case '/':
      //division
      if(n2.toInt()==0){
          c_total = 'E'; // se divide para 0 con el fin de ver si tiene o no decimales
             }else{
              c_total = (n1.toInt()) / (n2.toInt());
              r1=n1.toInt();
              r2=n2.toInt();
              decimal= r1/r2;
              }
      break;
    default: 
      
    break;
  }
 n3=String(c_total);
 lcd.clear();
 lcd.setCursor(15,0);
 lcd.autoscroll();
 // posibles errores que nos puede dar
 if(c_total=='E'){
  lcd.print("Error");
  } else if(n3.length()>4){
  lcd.print("*falta espacio*");
  }else{
      if (operacion == '/') {lcd.print(decimal,2);} 
          else {lcd.print(c_total);}; 
                contador=1;
                                                        }
lcd.noAutoscroll();
//se aplaste este voton y se reinicia el sistema para un nuevo calculo
} else if (boton == 'X' && boton != NO_KEY){
  lcd.clear();
  v_actual=false;
  final=false;
  n1="";
  n2="";
  c_total= 0;
  operacion=' ';
      }
}
