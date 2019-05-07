#include <OneWire.h>
#include <DallasTemperature.h>
#define ONE_WIRE_BUS 4


#include <Servo.h>

Servo servo;

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
int compteur = 0;
int pin = 21;
char auth[] = "b20ddc1e0efb4833b30ce8fd57fe5721";
char ssid[] = "Maman";
char pass[] = "tkt123456";
boolean test = 0;
const int trigPin = 2;
const int echoPin = 5;
int temps;
// defines variables
long duration;
int distance;
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

void setup() { 
  sensors.begin();
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  servo.attach(13);
  pinMode(pin, OUTPUT);
  pinMode(pin, HIGH);
  Serial.begin(115200);
  delay(10);
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, pass);
  int wifi_ctr = 0;
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);

    Serial.print(".");
  }
 Serial.println("WiFi connected"); 
  Blynk.begin("b20ddc1e0efb4833b30ce8fd57fe5721", ssid, pass);
}

void loop(){
    Blynk.run();
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
     digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distance= duration*0.034/2;
  if( distance > 20 ){
    if (test){
      compteur = compteur +1;
      test = false;
    }
  
  }
  else {
    test = true;
  }


  delay(50);
  Serial.print("Compteur: ");
Serial.println(compteur);
Serial.print("Distance: ");
Serial.println(distance);



Serial.println("Reading temperature...");
  sensors.requestTemperatures(); // Envoi de la demande de lecture

  Serial.print("Value is: ");
   // Récupération de l'objet 0 (vu qu'on n'en a qu'un)
temps = sensors.getTempCByIndex(0);
 Serial.println(temps); 
  delay(50); // Temporisation avant le prochain tour de boucle

  
}

  BLYNK_READ(V5) // Le Widget dans l'application LIT la broche virtuelle V5 avec une certaine fréquence
    {
     // Cette commande écrit le temps de disponibilité de l'Arduino en secondes à la broche Virtuelle V5
     Blynk.virtualWrite(5, compteur);
    }

 BLYNK_WRITE(V1)
{
   servo.write(param.asInt());
}


  BLYNK_READ(V3) // Le Widget dans l'application LIT la broche virtuelle V5 avec une certaine fréquence
    {
     // Cette commande écrit le temps de disponibilité de l'Arduino en secondes à la broche Virtuelle V5
     Blynk.virtualWrite(3, temps);
    }
