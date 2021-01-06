//RGB Switching lights for the other room. Nano V3 - 12V INPUT - Switching MOSFETs Ground using tindie.com/stores/DrAzzy 4 Channel Mosfet Driver
//LEDs Color Yellow and White not possible
#include <Bounce2.h>

#define buttonPin  5
#define Blue       4
#define Red        3
#define Green      2

int counter = 0;

Bounce bounce = Bounce();

void setup() {

  Serial.begin(9600);
  pinMode(Blue, OUTPUT);
  pinMode(Red, OUTPUT);
  pinMode(Green, OUTPUT);
  bounce.attach(buttonPin, INPUT_PULLUP);

}

void loop() {
  bounce.update();

  if (bounce.fell()) {
    counter++;
  }

  whichColor();

}

void whichColor () {
  switch (counter) {

    //Off - If for some unknown reason LED or MOSFETS are still on
    case 0:
      for (int i = 0; i < 5; i++) {
        digitalWrite(i, LOW);
      }
      break;

    //Blue
    case 1:
      digitalWrite(Blue, HIGH);
      break;

    //Red
    case 2:
      digitalWrite(Red, HIGH);
      digitalWrite(Blue, LOW);
      break;

    //Green
    case 3:
      digitalWrite(Red, LOW);
      digitalWrite(Green, HIGH);
      break;

    //Violet
    case 4:
      digitalWrite(Red, HIGH);
      digitalWrite(Green, LOW);
      digitalWrite(Blue, HIGH);
      break;

    //Off
    case 5:
      for (int i = 0; i < 5; i++) {
        digitalWrite(i, LOW);
      }
      counter = 0;
      break;
  }

}
