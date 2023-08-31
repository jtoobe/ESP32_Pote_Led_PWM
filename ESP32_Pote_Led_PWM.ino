/* controlar la intensidad del led con un Pote usando PWM */

// Declaramos la intensidad del brillo
int BRILLO = 0;
// Pin de entrada del potenciometro
int pinPot=35;
// Pin de salida al led
int pinLed=32;
//Características del PWM
const int frecuencia = 1000;
const int canal = 0;
const int resolucion = 10;


void setup()
{
  Serial.begin(115200);
  //Inicializamos las características del pwm
  ledcSetup(canal, frecuencia, resolucion);
  // Definimos que el pin 2 sacara el voltaje
  ledcAttachPin(pinLed, OUTPUT);
  delay(1000);
}


void loop()
{
  //Obtenemos la señal del potenciometro
  BRILLO = analogRead(pinPot);
  
  //Mostramos la señal del potenciometro
  Serial.println(BRILLO);
  
  //desde 0 a 4095
  //Dividimos la señal en entre 16
  //BRILLO = (BRILLO / 16.2);

  // o usamos la funcin Map que es mas elegante
  BRILLO = map(BRILLO, 0,4095, 0,255);
  Serial.println(BRILLO);
  
  //Encendemos el led
  //ledcWrite(pinLed, BRILLO);
  analogWrite(pinLed, BRILLO);
  delay(1000);
}
