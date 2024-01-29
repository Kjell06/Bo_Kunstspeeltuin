#define RED_LED 6
#define BLUE_LED 5
#define GREEN_LED 9
#define TOUCH_SENSOR_PIN 2

int brightness = 255;

int gBright = 0;
int rBright = 0;
int bBright = 0;

int fadeSpeed = 10;

void setup() {
  pinMode(GREEN_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);
  pinMode(BLUE_LED, OUTPUT);
  pinMode(TOUCH_SENSOR_PIN, INPUT);

  TurnOn();
  delay(5000);
  TurnOff();
}

void TurnOn() {
  for (int i = 0; i < 256; i++) {
    analogWrite(RED_LED, rBright);
    analogWrite(BLUE_LED, bBright);
    analogWrite(GREEN_LED, gBright);
    rBright += 1;
    bBright += 1;
    gBright += 1;
    delay(fadeSpeed);
  }
}

void TurnOff() {
  for (int i = 0; i < 256; i++) {
    analogWrite(GREEN_LED, brightness);
    analogWrite(RED_LED, brightness);
    analogWrite(BLUE_LED, brightness);

    brightness -= 1;

    delay(fadeSpeed);
  }
}

void loop() {
  if (digitalRead(TOUCH_SENSOR_PIN) == HIGH) {
    changeColor();
    delay(1000);
  }
}

void changeColor() {
  int red = random(256);
  int green = random(256);
  int blue = random(256);

  analogWrite(RED_LED, red);
  analogWrite(GREEN_LED, green);
  analogWrite(BLUE_LED, blue);
}