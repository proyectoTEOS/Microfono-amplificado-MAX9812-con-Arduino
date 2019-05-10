/*
  Created by TEOS
  Domotic with Arduino https://goo.gl/btZpjs
  YouTube https://goo.gl/k7TUSZ
  Instagram https://goo.gl/zEIjia
  Facebook https://goo.gl/eivraR
  Twitter https://goo.gl/du5Wgn
  Github https://goo.gl/Xl5IiS
  Google Plus https://goo.gl/gBnUdh
  WEB https://goo.gl/jtiYJy
*/

const uint8_t soundPinT = A0, sampleWindowT = 50;

void setup() {
  Serial.begin(9600);
}

void loop() {
  String resultSerialT;
  unsigned long startMillisT = millis();
  uint16_t peakToPeakT = 0, signalMaxT = 0, signalMinT = 1024, incomingSoundT, bitsResolutionT = 1024;

  while (millis() - startMillisT < sampleWindowT) {
    incomingSoundT = analogRead(soundPinT);
    if (incomingSoundT < bitsResolutionT) {
      if (incomingSoundT > signalMaxT)
        signalMaxT = incomingSoundT;
      else if (incomingSoundT < signalMinT) {
        signalMinT = incomingSoundT;
      }
    }
  }

  peakToPeakT = signalMaxT - signalMinT;
  double voltsT = (peakToPeakT * 5.0) / bitsResolutionT;
  resultSerialT = "Voltaje detectado: " + String(voltsT);
  Serial.println(resultSerialT);
}
