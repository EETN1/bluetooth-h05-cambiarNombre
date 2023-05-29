#include <SoftwareSerial.h>
//#######IMPORTANTE#########
// CONEXION
//PIN EN DEL BLUETOOTH AL PIN 9 DEL ARDUINO
//PIN VCC DEL BLUETOOTH AL PIN 8 DEL ARDUINO
//PIN GND DEL BLUETOOTH AL PIN GND DEL ARDUINO
//PIN RX DEL BLUETOOTH AL PIN 11 DEL ARDUINO
//PIN TX DEL BLUETOOTH AL PIN 10 DEL ARDUINO
//AL TERMINAR DE CONFIGURARLO DESCONECTAR EL EN, CONECTAR NORMALMENTE EL GND Y EL VCC.

SoftwareSerial BT1(10, 11); // RX | TX
void setup()
{ pinMode(8, OUTPUT);        // Al poner en HIGH forzaremos el modo AT
  pinMode(9, OUTPUT);        // cuando se alimente de aqui
  digitalWrite(9, HIGH);
  delay (500) ;              // Espera antes de encender el modulo
  Serial.begin(9600);
  Serial.println("Levantando el modulo HC-05");
  digitalWrite (8, HIGH);    //Enciende el modulo
  Serial.println("IMPORTANTE - Tener en cuenta seleccionar Ambos NL & CR ");
  Serial.println("9600 baudios para la consola");
  Serial.println("Esperando comandos AT:");
  
//UTILIZAR SEGUN CORRESPONDA
  BT1.begin(38400); 
  //BT1.begin(9600);
}

void loop()
{ if (BT1.available())
    Serial.write(BT1.read());
  if (Serial.available())
    BT1.write(Serial.read());
}

/**
Lista de comandos AT comunes para comunicarte con un módulo Bluetooth HC-05 en Arduino:
Ver el nombre del dispositivo:
AT+NAME?

Configurar el nombre del dispositivo:
AT+NAME=<nombre_dispositivo>

Configurar el código PIN:
ATLista de comandos AT comunes para comunicarte con un módulo Bluetooth HC-05 en Arduino:
Ver el nombre del dispositivo:
AT+NAME?

Configurar el nombre del dispositivo:
AT+NAME=<nombre_dispositivo>

Configurar el código PIN:
AT+PIN=<código_PIN>

Configurar el modo de funcionamiento:
AT+ROLE=<modo>

---->Para configurar el módulo HC-05 en modo esclavo, envía el siguiente comando:
  AT+ROLE=0

---->Para configurar el módulo HC-05 en modo maestro, envía el siguiente comando:
AT+ROLE=1


Establecer la velocidad de transmisión:
AT+UART=<velocidad>,<bits_datos>,<paridad>,<bits_parada>

<velocidad> es la velocidad en baudios.
<bits_datos> representa la cantidad de bits de datos (generalmente 8).
<paridad> define la paridad, puede ser 0 (ninguna), 1 (par) o 2 (impar).
<bits_parada> indica la cantidad de bits de parada (generalmente 1).

Configurar el modo de emparejamiento:
AT+PAIR=<modo>,<timeout>

<modo> puede ser 0 (no emparejar) o 1 (emparejamiento automático).
<timeout> es el tiempo de espera en segundos para emparejar (0 significa sin límite).
Configurar el modo de conexión:
AT+CMODE=<modo>

<modo> puede ser 0 (conexión única) o 1 (conexión múltiple).
Obtener la dirección Bluetooth del dispositivo:
AT+ADDR

Obtener la versión del firmware:
AT+VERSION

Restaurar la configuración de fábrica:
AT+ORGL+PIN=<código_PIN>

Configurar el modo de funcionamiento:
AT+ROLE=<modo>

---->Para configurar el módulo HC-05 en modo esclavo, envía el siguiente comando:
  AT+ROLE=0

---->Para configurar el módulo HC-05 en modo maestro, envía el siguiente comando:
AT+ROLE=1


Establecer la velocidad de transmisión:
AT+UART=<velocidad>,<bits_datos>,<paridad>,<bits_parada>

<velocidad> es la velocidad en baudios.
<bits_datos> representa la cantidad de bits de datos (generalmente 8).
<paridad> define la paridad, puede ser 0 (ninguna), 1 (par) o 2 (impar).
<bits_parada> indica la cantidad de bits de parada (generalmente 1).

Configurar el modo de emparejamiento:
AT+PAIR=<modo>,<timeout>

<modo> puede ser 0 (no emparejar) o 1 (emparejamiento automático).
<timeout> es el tiempo de espera en segundos para emparejar (0 significa sin límite).
Configurar el modo de conexión:
AT+CMODE=<modo>

<modo> puede ser 0 (conexión única) o 1 (conexión múltiple).
Obtener la dirección Bluetooth del dispositivo:
AT+ADDR

Obtener la versión del firmware:
AT+VERSION

Restaurar la configuración de fábrica:
AT+ORGL
*/
