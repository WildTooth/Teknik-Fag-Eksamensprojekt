#define YELLOW 5
#define GREEN 4
#define RED 2
#define BLUE 3

#define YES_INPUT 6

#define SPEED_FASTEST 250
#define SPEED_VERY_FAST 500
#define SPEED_FAST 750
#define SPEED_NORMAL 1000
#define SPEED_SLOW 1250
#define SPEED_SLOWER_THAN_SLOW 1500
#define SPEED_VERY_SLOW 1750
#define SPEED_SLOWEST 2000

int pinArray[] = {YELLOW,GREEN,RED,BLUE};

int count = 1;

template <typename T, size_t N>
int size(T (&array)[N]) {
  return N;
}

void setup() {
  Serial.begin(9600);
  for (int i = 0; i < size(pinArray); i++) {
    pinMode(pinArray[i], OUTPUT);
  }
  pinMode(YES_INPUT, INPUT);
}

void loop() {
  if (digitalRead(YES_INPUT) == HIGH) {
    doRound(SPEED_VERY_FAST, count++);
  }
}

int randomPin() {
  return random(0,size(pinArray));
}

void doRound(int speed, int sequenceLength) {
  for (int i = 0; i < sequenceLength; i++) {
    int pin = pinArray[randomPin()];
    digitalWrite(pin, HIGH);
    delay(speed);
    digitalWrite(pin, LOW);
    delay(SPEED_FASTEST);
  }
  delay(5000);
}

boolean endGame() {
  return false;
}
