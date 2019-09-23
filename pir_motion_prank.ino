int oldValue = 0;
#define relayPin D4
#define pirPin D2

void setup() {
  // put your setup code here, to run once:
  pinMode(pirPin, INPUT_PULLUP);
  pinMode(relayPin, OUTPUT);
  digitalWrite(relayPin,HIGH);
  Serial.begin(115200);

}

void loop() {
  int value = digitalRead(pirPin);
  if (value != oldValue) {
    Serial.println("New Value: " + String(value));
    oldValue = value;
    if (value == 1) {
      Serial.println("########## MOTION DETECTED ##########");
      //Activate Relay. If you use other than D4, reverse the value.
      digitalWrite(relayPin,LOW);
    }else{
      //Deactivate Reay
      digitalWrite(relayPin,HIGH);
    }
  }
  
  delay(2000);
}
