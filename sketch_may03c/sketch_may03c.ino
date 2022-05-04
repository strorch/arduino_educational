
const int RED = 8;
const int YELLOW = 9;
const int GREEN = 10;

void setup() {
  // put your setup code here, to run once:
  pinMode(RED, OUTPUT);
  pinMode(YELLOW, OUTPUT);
  pinMode(GREEN, OUTPUT);
}

void loop() {
  digitalWrite(GREEN, LOW);
  digitalWrite(YELLOW, LOW);
  digitalWrite(RED, LOW);
  
  digitalWrite(YELLOW, HIGH);
  delay(1000);

  digitalWrite(YELLOW, LOW);
  digitalWrite(RED, HIGH);
  delay(1000);
  
  digitalWrite(YELLOW, HIGH);
  delay(1000);
  
  digitalWrite(YELLOW, LOW);
  digitalWrite(RED, LOW);
  digitalWrite(GREEN, HIGH);
  delay(1000);
}
