const int LED = 13;
const int BUTTON = 2;

int ledState = LOW;
int buttonState = LOW;

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(BUTTON, OUTPUT);
}

void loop() {
  int buttonValue = digitalRead(BUTTON);

  if (buttonValue == HIGH && buttonState == LOW) {
    ledState = !ledState;
    digitalWrite(LED, ledState);
  }
  buttonState = buttonValue;
}
