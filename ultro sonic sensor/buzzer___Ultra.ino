//HC SR04
int trigPin = 10;
int echoPin = 11;
int led = 13;
int buzzerPin = 12;
long duration, cm, inches;


void setup() {
 pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(led,     OUTPUT);
  digitalWrite(trigPin, LOW);
  

}

void loop() {
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);

  cm = (duration / 2) / 29.1;
  inches = (duration / 2) / 74;

  if (cm <= 30) {
    tone(buzzerPin, 100);
    tone(buzzerPin, 300);
    delay(50);
    tone(buzzerPin, 100);
    digitalWrite(led, HIGH);
    delay(100);
  }
  else {
    digitalWrite(led, LOW);
  }
}
