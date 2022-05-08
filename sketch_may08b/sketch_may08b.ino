#define N_ELEMS(x)  (sizeof(x) / sizeof((x)[0]))

const int LEFT_BTN = 2;
const int RIGHT_BTN = 3;

int leftBtnVal = 0;
int rightBtnVal = 0;

int currentNumber = 0;

int leds[7] = {5, 6, 7, 8, 9, 10, 11};

byte numbers[10] = {
  B01111110, // 0
  B00010010, // 1
  B10111100, // 2
  B10111010, // 3
  B11010010, // 4
  B11101010, // 5
  B11101110, // 6
  B00110010, // 7
  B11111110, // 8
  B11111010  // 9
};

void setup() {
  pinMode(LEFT_BTN, INPUT);
  pinMode(RIGHT_BTN, INPUT);
    
  for (int i = 0; i < N_ELEMS(leds); i++) {
    pinMode(leds[i], OUTPUT);
  }
}

int debounce(int last, int ident) {
  int current = digitalRead(ident);
  if (current != last) {
    delay(5);
    current = digitalRead(ident);
  }
  return current;
}

void drawNumber(int number) {
  for (int i = 0; i < N_ELEMS(leds); i++) {
    if (bitRead(numbers[number], N_ELEMS(leds) - i) == HIGH) {
      digitalWrite(leds[i], HIGH);
    } else {
      digitalWrite(leds[i], LOW);
    }
  }
}

void loop() {

//  for (int i = 0; i < N_ELEMS(leds); i++) {
//    digitalWrite(leds[i], HIGH);
//    delay(1000);
//    digitalWrite(leds[i], LOW);
//  }

//  int leftBtnValRead = debounce(leftBtnVal, LEFT_BTN);
//  int rightBtnValRead = debounce(rightBtnVal, RIGHT_BTN);
  
  int leftBtnValRead = digitalRead(LEFT_BTN);
  int rightBtnValRead = digitalRead(RIGHT_BTN);

  if (leftBtnValRead == HIGH && currentNumber - 1 >= 0) {
    currentNumber--;
    leftBtnVal = leftBtnValRead;
  }
  if (rightBtnValRead == HIGH && currentNumber + 1 < N_ELEMS(numbers)) {
    currentNumber++;
    rightBtnVal = rightBtnValRead;
  }
  
  drawNumber(currentNumber);
  
  delay(100);
}
