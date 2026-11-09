const int echo_pin = 11;
const int trigger_pin = 12;
const unsigned long timeout = 30000; // 5 m of range
const unsigned long loop_time = 100; // in milliseconds

unsigned long lastReading = 0;

void setup() {
  pinMode(echo_pin, INPUT);
  pinMode(trigger_pin, OUTPUT);
  Serial.begin(115200);
  Serial.println("time, distance");
}

void loop() {
  int now = millis();
  if(now-lastReading >= loop_time) {
  digitalWrite(trigger_pin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigger_pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger_pin, LOW);

  float duration = pulseIn(echo_pin, HIGH, timeout);

  Serial.print(now);
  Serial.print(',');
  if(duration == 0)
  {
    Serial.println("NaN");
  }
  else
  {
    float distance = (duration * 0.034)/2;
    Serial.println(distance); 
  }
  }
}
