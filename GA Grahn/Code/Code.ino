#include <FreqMeasure.h>
#include <FastLED.h>
#include <EasyButton.h>
#define LED_PIN     7
#define NUM_LEDS    120
CRGB leds[NUM_LEDS];
int knapppin = 2;
EasyButton knapp(knapppin, 20, false, false);
int knapptryck = 0;
uint8_t hue = 0;
int vartryckt;
const int restart = 9;
int d = 0;
int db_pin = A5;
int ljus = 0;

void setup() {
  digitalWrite(restart, HIGH);
  pinMode (restart, OUTPUT);
  pinMode (db_pin, INPUT);
  Serial.begin(57600);
  FreqMeasure.begin();
  knapp.begin();
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
}

double sum = 0;
int count = 0;


void wawe() {
  int tid = 0;
  if (FreqMeasure.available()) {
    sum = sum + FreqMeasure.read();
    count = count + 1;
    if (count >= 5) {
      float frequency = FreqMeasure.countToFrequency(sum / count);
      // Serial.println(frequency);
      sum = 0;
      count = 0;
      if (frequency >= 10000) {
        tid = frequency / 5000;
      }
      else if (frequency >= 5000) {
        tid = frequency / 2500;
      }
      else if (frequency >= 1000) {
        tid = frequency / 500;
      }
      else {
        tid = frequency / 100;
      }
      // Serial.println(tid);
      int r1 = random(0, 255);
      int g1 = random(0, 255);
      int b1 = random(0, 255);
      int r2 = random(0, 255);
      int g2 = random(0, 255);
      int b2 = random(0, 255);
      int r3 = random(0, 255);
      int g3 = random(0, 255);
      int b3 = random(0, 255);
      int z1 = NUM_LEDS / 2;
      int z2 = NUM_LEDS / 2;
      int x = NUM_LEDS / 4;
      int y1 = (NUM_LEDS / 4) * 3;
      int y2 = (NUM_LEDS / 4) * 3;
      FastLED.clear();
      for (int i = NUM_LEDS / 4; i < NUM_LEDS; i++) {
        leds[i] = CRGB(r1, g1, b1);
        leds[x] = CRGB(r1, g1, b1);
        leds[y1] = CRGB(r2, g2, b2);
        leds[y2] = CRGB(r2, g2, b2);
        leds[z1] = CRGB(r3, g3, b3);
        leds[z2] = CRGB(r3, g3, b3);
        FastLED.show();
        delay(tid);
        leds[i] = CRGB::Black;
        leds[x] = CRGB::Black;
        leds[y1] = CRGB::Black;
        leds[y2] = CRGB::Black;
        leds[z1] = CRGB::Black;
        leds[z2] = CRGB::Black;
        y1 = y1 - 1;
        if (x == -1) {
          x = -1;
        }
        else {
          x = x - 1;
        }
        if (y2 == NUM_LEDS) {
          y2 = NUM_LEDS;
        }
        else {
          y2 = y2 + 1;
        }
        if (z2 == NUM_LEDS) {
          z2 = NUM_LEDS;
        }
        else {
          z2 = z2 + 1;
        }
        if (z1 == -1) {
          z1 = -1;
        }
        else {
          z1 = z1 - 1;
        }
      }
    }
  }
}

void stege() {
  int tid = 0;
  if (FreqMeasure.available()) {
    sum = sum + FreqMeasure.read();
    count = count + 1;
    if (count >= 5) {
      float frequency = FreqMeasure.countToFrequency(sum / count);
      // Serial.println(frequency);
      sum = 0;
      count = 0;
      if (frequency >= 10000) {
        tid = frequency / 5000;
      }
      else if (frequency >= 5000) {
        tid = frequency / 2500;
      }
      else if (frequency >= 1000) {
        tid = frequency / 500;
      }
      else {
        tid = frequency / 100;
      }
      //  Serial.println(tid);
      int r = random(0, 255);
      int g = random(0, 255);
      int b = random(0, 255);
      int a = analogRead(db_pin);
      int db = (a + 83.2073) / 11.003;
      int q = db * 1.8;
      FastLED.clear();
      for (int i = 0; i < q; i++) {
        leds[i] = CRGB(r, g, b);
        FastLED.show();
        delay(tid);
      }
      for (int i = q; i > 0 ; i--) {
        leds[i] = CRGB::Black;
        FastLED.show();
        delay(tid);
      }
    }
  }
}

void mittenut() {
  int tid = 0;
  if (FreqMeasure.available()) {
    sum = sum + FreqMeasure.read();
    count = count + 1;
    if (count >= 5) {
      float frequency = FreqMeasure.countToFrequency(sum / count);
      // Serial.println(frequency);
      sum = 0;
      count = 0;
      if (frequency >= 10000) {
        tid = frequency / 5000;
      }
      else if (frequency >= 5000) {
        tid = frequency / 2500;
      }
      else if (frequency >= 1000) {
        tid = frequency / 500;
      }
      else {
        tid = frequency / 100;
      }
      //  Serial.println(tid);
      int r = random(0, 255);
      int g = random(0, 255);
      int b = random(0, 255);
      int x = 60;
      FastLED.clear();
      for (int i = 60; i < 120; i++) {
        x = x - 1;
        leds[i] = CRGB(r, g, b);
        leds[x] = CRGB(r, g, b);
        delay(tid);
        FastLED.show();
      }
      x = 0;
      for (int i = 120; i > 60; i--) {
        x = x + 1;
        leds[i] = CRGB::Black;
        leds[x] = CRGB::Black;
        delay(tid);
        FastLED.show();
      }
    }
  }
}

void sidor2 () {
  int tid = 0;
  if (FreqMeasure.available()) {
    sum = sum + FreqMeasure.read();
    count = count + 1;
    if (count >= 5) {
      float frequency = FreqMeasure.countToFrequency(sum / count);
      // Serial.println(frequency);
      sum = 0;
      count = 0;
      if (frequency >= 10000) {
        tid = frequency / 5000;
      }
      else if (frequency >= 5000) {
        tid = frequency / 2500;
      }
      else if (frequency >= 1000) {
        tid = frequency / 500;
      }
      else {
        tid = frequency / 100;
      }
      //  Serial.println(tid);
      int r1 = random(0, 255);
      int g1 = random(0, 255);
      int b1 = random(0, 255);
      int r2 = random(0, 255);
      int g2 = random(0, 255);
      int b2 = random(0, 255);
      int x = NUM_LEDS;
      FastLED.clear();
      for (int i = 0; i < NUM_LEDS; i++) {
        leds[i] = CRGB(r1, g1, b1);
        leds[x] = CRGB(r1, b1, b1);
        FastLED.show();
        delay(tid);
        x = x - 1;
      }
      for (int i = NUM_LEDS; i > NUM_LEDS / 2; i--) {
        leds[i] = CRGB::Black;
        leds[x] = CRGB::Black;
        FastLED.show();
        delay(tid);
        x = x + 1;
      }
      for (int i = NUM_LEDS / 2; i > 0; i--) {
        leds[i] = CRGB(r1, g1, b1);
        leds[x] = CRGB(r1, b1, b1);
        FastLED.show();
        delay(tid);
        leds[i] = CRGB::Black;
        leds[x] = CRGB::Black;
        x = x + 1;
      }
    }
  }
}

void grow () {
  int tid = 0;
  if (FreqMeasure.available()) {
    sum = sum + FreqMeasure.read();
    count = count + 1;
    if (count >= 5) {
      float frequency = FreqMeasure.countToFrequency(sum / count);
      // Serial.println(frequency);
      sum = 0;
      count = 0;
      if (frequency >= 10000) {
        tid = frequency / 10000;
      }
      else if (frequency >= 5000) {
        tid = frequency / 5000;
      }
      else if (frequency >= 1000) {
        tid = frequency / 1000;
      }
      else {
        tid = frequency / 200;
      }
      //  Serial.println(tid);
      int r = random(0, 255);
      int g = random(0, 255);
      int b = random(0, 255);
      int x = NUM_LEDS / 2;
      FastLED.clear();
      for (int q = NUM_LEDS / 2 + 1; q <= NUM_LEDS; q++) {
        if ( q % 8 == 0) {
          for (int i = NUM_LEDS / 2; i < q; i++) {
            leds[i] = CRGB(r, g, b);
            leds[x] = CRGB(r, g, b);
            FastLED.show();
            delay(tid);
            x = x - 1;
          }
          for (int i = q; i > NUM_LEDS / 2; i--) {
            leds[i] = CRGB::Black;
            leds[x] = CRGB::Black;
            FastLED.show();
            delay(tid);
            x = x + 1;
          }
        }
      }
    }
  }
}

void bling() {
  int tid = 0;
  if (FreqMeasure.available()) {
    sum = sum + FreqMeasure.read();
    count = count + 1;
    if (count >= 5) {
      float frequency = FreqMeasure.countToFrequency(sum / count);
      // Serial.println(frequency);
      sum = 0;
      count = 0;
      if (frequency >= 10000) {
        tid = frequency / 5000;
      }
      else if (frequency >= 5000) {
        tid = frequency / 2500;
      }
      else if (frequency >= 1000) {
        tid = frequency / 500;
      }
      else {
        tid = frequency / 100;
      }
      int r = random(0, 255);
      int g = random(0, 255);
      int b = random(0, 255);
      int x = NUM_LEDS / 2;
      for (int i = NUM_LEDS / 2; i <= NUM_LEDS; i++) {
        leds[i] = CRGB(r, g, b);
        leds[x] = CRGB(r, g, b);
        FastLED.show();
        delay(tid);
        x = x - 1;
      }
    }
  }
}

void grow2() {
  int tid = 0;
  if (FreqMeasure.available()) {
    sum = sum + FreqMeasure.read();
    count = count + 1;
    if (count >= 5) {
      float frequency = FreqMeasure.countToFrequency(sum / count);
      // Serial.println(frequency);
      sum = 0;
      count = 0;
      if (frequency >= 10000) {
        tid = frequency / 15000;
      }
      else if (frequency >= 5000) {
        tid = frequency / 7500;
      }
      else if (frequency >= 1000) {
        tid = frequency / 1500;
      }
      else {
        tid = frequency / 300;
      }
      int r1 = random(0, 255);
      int g1 = random(0, 255);
      int b1 = random(0, 255);
      int r2 = random(0, 255);
      int g2 = random(0, 255);
      int b2 = random(0, 255);
      FastLED.clear();
      for (int q = 0; q <= NUM_LEDS; q++) {
        if ( q % 12 == 0) {
          for (int i = 0; i < q; i++) {
            leds[i] = CRGB(r1, g1, b1);
            FastLED.show();
            delay(tid);
          }
          for (int i = q; i > 0; i--) {
            leds[i] = CRGB::Black;
            FastLED.show();
            delay(tid);
          }
        }
      }
    }
  }
}

void dbljus() {
  int tid = 0;
      FastLED.clear();
    for (int i = 0; i < NUM_LEDS; ++i) {
      leds[i] = CHSV(hue + (i * 10), 255, ljus);
            Serial.println(ljus);
    }
    EVERY_N_MILLISECONDS(10) {
      hue++;
    }
    EVERY_N_MILLISECONDS(200) {
            if (FreqMeasure.available()){
       int a = analogRead(db_pin);
      int db = (a+83.2073) / 11.003;
       ljus = db*random(2,5); 
      }
       else {
        ljus = 0;
       }
    }
    FastLED.show();
    }

void buttonPressed() {
  vartryckt = true;
}

void loop() {
  knapp.read();
  Serial.println(knapptryck);
  if (knapp.pressedFor(500)) {
    knapptryck = 0;
    vartryckt = false;
  }
  else if (knapp.wasPressed()) {
    delay(50);
    knapptryck = knapptryck + 1;
    vartryckt = false;
  }
  if (knapptryck == 0) {
    FastLED.clear();
    delay(10);
    FastLED.show();
  }
  else if (knapptryck == 1) {
    fill_solid( leds, NUM_LEDS, CRGB(0, 175, 210));
    delay(10);
    FastLED.show();
  }
  else if (knapptryck == 2) {
    fill_solid( leds, NUM_LEDS, CRGB(255, 0, 0));
    delay(10);
    FastLED.show();
  }
  else if (knapptryck == 3) {
    fill_solid( leds, NUM_LEDS, CRGB(0, 255, 0));
    delay(10);
    FastLED.show();
  }
  else if (knapptryck == 4) {
    fill_solid( leds, NUM_LEDS, CRGB(0, 0, 225));
    delay(10);
    FastLED.show();
  }
  else if (knapptryck == 5) {
    fill_solid( leds, NUM_LEDS, CRGB(255, 0, 215));
    delay(10);
    FastLED.show();
  }
  else if (knapptryck == 6) {
    for (int i = 0; i < NUM_LEDS; ++i) {
      leds[i] = CHSV(hue + (i * 10), 255, 255);
    }
    EVERY_N_MILLISECONDS(10) {
      hue++;
    }
    FastLED.show();
  }
  else if (knapptryck == 7) {
    int a = 0;
    for (int i = 0; i < 1;) {
      attachInterrupt(digitalPinToInterrupt(knapppin), buttonPressed, CHANGE);
      knapp.update();
      if (vartryckt == true) {
        vartryckt = false;
        d = d + 1;
        if (d >= 3) {
          Serial.println("Interupting");
          delay(10);
          digitalWrite (restart, LOW);
        }
      }
      a = a + 1;
      if (a > 500) {
        a = 0;
      }
      else {
        Serial.println(a);
        if (FreqMeasure.available() == false) {
          FastLED.clear();
          FastLED.show();
        }
        else if (a <= 50) {
          stege();
        }
        else if (a <= 150) {
          wawe();
        }
        else if (a <= 200) {
          mittenut();
        }
        else if (a <= 250) {
          sidor2();
        }
        else if (a <= 275) {
          grow();
        }
        else if (a <= 375) {
          dbljus();
        }
        else if (a <= 400) {
          grow2();
        }
        else if (a <= 500) {
          bling();
        }
        else {
          FastLED.clear();
          FastLED.show();
        }
      }
    }
  }
}
