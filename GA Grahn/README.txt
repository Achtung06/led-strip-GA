Varje synlig led i slingan WS2812B har 3 leds i sig, röd, blå och grön. Varje av dessa 3 ledsen tar in 8 bit data, vilket motsvarar 24 bit data per synlig led. Det är så man kan kontrollera var led för sig, för man skickar ut en mängd data (I detta fallet 2880 bit då det är 120 leds) och varje led tar sin data och skickar vidare restren av datan till nästa. Anledningen varför det står WS2812 i koden och inte WS2812B är för att WS2812B är bara en uppgradering av WS2812 och märkte ganska snabbt att om man lägger till B ett börjar koden krångla ibland av någon anledning.

if (FreqMeasure.available()) {
    sum = sum + FreqMeasure.read();
    count = count + 1;
    if (count >= 5) {
      float frequency = FreqMeasure.countToFrequency(sum / count);

Detta kodblocket som används i nästan alla effekterna är taget från:
https://www.pjrc.com/teensy/td_libs_FreqMeasure.html

for (int i = 0; i < NUM_LEDS; ++i) {
leds[i] = CHSV(hue + (i * 10), 255, 255);
}
EVERY_N_MILLISECONDS(10) {
hue++;
}
FastLED.show();

Detta kodblocket är taget längst ner från:
https://stackoverflow.com/questions/59394851/how-to-create-a-rainbow-wave-on-led-strip-using-arduino

Allt annat har jag skrivit själv, har såklart tagit insperation från annan kod men inte kopierat något.
