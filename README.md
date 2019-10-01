# Micrófono amplificado MAX9812 con Arduino
Convertiremos la señal de sonido captado a voltaje mediante la placa Arduino.

### Requisitos
- Tener el IDE de [Arduino](https://www.arduino.cc/en/Main/Software) (o el de tu preferencia) con la versión más actual
- Tener el material para hacer el proyecto

### Código
**[Aqui](https://github.com/proyectoTEOS/Microfono-amplificado-MAX9812-con-Arduino/blob/master/Microfono-amplificado-MAX9812-con-Arduino.ino)** podrás obtener el link del código, también dejaremos
una vista previa aquí abajo.

```c++
/*
  Created by TEOS
  Domotic with Arduino https://goo.gl/btZpjs
  YouTube https://goo.gl/k7TUSZ
  Instagram https://goo.gl/zEIjia
  Facebook https://goo.gl/eivraR
  Twitter https://goo.gl/du5Wgn
  Github https://goo.gl/Xl5IiS
  WEB https://www.proyecto-teos.com
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
```

### Diagrama
El siguiente esquemático muestra como se debe conectar todos los componentes con la placa.
![](https://github.com/proyectoTEOS/Microfono-amplificado-MAX9812-con-Arduino/blob/master/microfono-amplificado-max9812-con-arduino-5.jpg)
