
#define BLYNK_TEMPLATE_ID "TMPL6UlA1ajAM"
#define BLYNK_TEMPLATE_NAME "Posttest3"
#define BLYNK_AUTH_TOKEN "FKfkv-R6S197P05xRDSp6P5n8W44g5a5"

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <DHT.h>


char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "OjanPhone";  // type your wifi name
char pass[] = "auzan223";  // type your wifi password

#define LEDPINMERAH D4
#define LEDPINHIJAU D2
#define LEDPINKUNING D3
#define BUZZERPIN D1 //Kaki anoda dari LED terhubung ke pin D8 NodeMCU
#define DHTPIN D5
#define DHTTYPE DHT11

int kondisi = 0;
BlynkTimer timer;

DHT dht(DHTPIN, DHTTYPE);

BLYNK_WRITE(V1) { // V2 adalah pin LED yang sudah kita atur pada Blynk
  digitalWrite(LEDPINMERAH, param.asInt()); // Mengubah nilai LED dari Blynk
}



void setup(){
  Serial.begin(9600);
  // Mengatur pin LED
  pinMode(LEDPINMERAH, OUTPUT);
  pinMode(LEDPINHIJAU, OUTPUT);
  pinMode(LEDPINKUNING, OUTPUT);
  // Setup Blynk
  
  Blynk.begin(auth, ssid, pass, "blynk.cloud", 80);
  // Setup Sensor DHT 11
  dht.begin();
  timer.setInterval(2500L, sendSensor);
}

void loop(){
  Blynk.run();
  timer.run();

}

void sendSensor(){
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  // Mengecek kondisi apakah DHT bisa dibaca atau tidak
  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
  
  // Mengatur nilai suhu ke pin V0(Suhu) yang sudah diatur pada Blynk
  Blynk.virtualWrite(V3, t);
  // Menampilkan ke serial monitor
  // Event log
  Serial.print("Suhu : ");
  
  Serial.println(t);
  Serial.println(LEDPINMERAH);
  if(t < 30){
    digitalWrite(LEDPINHIJAU,HIGH);
    digitalWrite(LEDPINMERAH,LOW);
    digitalWrite(LEDPINKUNING,LOW);
  Blynk.virtualWrite(V0, LOW);
  Blynk.virtualWrite(V1,LOW);
  Blynk.virtualWrite(V2,HIGH);
  }else if(t > 36){
    digitalWrite(LEDPINMERAH,HIGH);
    digitalWrite(LEDPINHIJAU,LOW);
    digitalWrite(LEDPINKUNING,LOW);
    Blynk.virtualWrite(V0, HIGH);
    Blynk.virtualWrite(V1,LOW);
    Blynk.virtualWrite(V2,LOW);
    tone(BUZZERPIN,150);
  }else if(t > 30 && t < 36 ){
    digitalWrite(LEDPINKUNING,HIGH);
    digitalWrite(LEDPINMERAH,LOW);
    digitalWrite(LEDPINHIJAU,LOW);
    Blynk.virtualWrite(V0,LOW);
    Blynk.virtualWrite(V1,HIGH);
    Blynk.virtualWrite(V2,LOW);
    noTone(BUZZERPIN);                                                                                                            
  }
}

