#define N_ELEMS(x)  (sizeof(x) / sizeof((x)[0]))

const int leds[] = {2, 3, 4, 5, 6, 7, 8};
const int ANLG_PIN=0;

const int MIN_LIGHT = 400;
const int MAX_LIGHT = 1000; 

const int PORT=9600;

int step;

void setup() {
  Serial.begin(PORT);
  for (int i = 0; i < N_ELEMS(leds); i++) {
    pinMode(i, OUTPUT);
  }
//    digitalWrite(7, HIGH);
//    digitalWrite(8, HIGH );

  step = (int) (MAX_LIGHT - MIN_LIGHT) / N_ELEMS(leds);
}

void loop() {
  int val = analogRead(ANLG_PIN);
  int ledValue;
  
  Serial.println(val);
  for (int i = 0; i < N_ELEMS(leds); i++) {
    if (val >= MIN_LIGHT + step * i) {
      ledValue = HIGH;
    } else {
      ledValue = LOW;
    }
    digitalWrite(leds[i], ledValue);
  }

  delay(500);
}
