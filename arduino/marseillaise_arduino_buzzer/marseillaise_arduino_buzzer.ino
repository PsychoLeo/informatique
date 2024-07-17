#define SPKR 12 /* pin */

/* noten, periode in us */
#define C0   3822
#define CIS0 3608
#define D0   3405
#define DIS0 3215
#define E0   3034
#define F0   2864
#define FIS0 2703
#define G0   2551
#define GIS0 2408
#define A0   2273  //  440 Hz
#define AIS0 2145
#define H0   2025
#define C1   1911
#define CIS1 1804
#define D1   1702
#define DIS1 1607
#define E1   1517
#define F1   1431
#define FIS1 1351
#define G1   1276
#define GIS1 1204
#define A1   1136
#define AIS1 1073
#define H1   1013
#define C2    956

#define PAUSE              0

#define sechzehntel      100
#define achtel          ( 2*sechzehntel)
#define dreisechzehntel ( 3*sechzehntel)
#define viertel         ( 4*sechzehntel)
#define dreiachtel      ( 6*sechzehntel)
#define halbe           ( 8*sechzehntel)
#define ganz            (16*sechzehntel)


uint16_t lautstaerke = 10;

void setup() {
  // put your setup code here, to run once:
  pinMode(SPKR, OUTPUT);
  cli();
}

void spiele(uint32_t ton, int32_t dauer)
{
  /* pause, kein ton */
  if (ton == 0)
  {
    while (dauer--)
    {
      _delay_ms(1);
    }
    return;
  }
  /* ton */
  int32_t pause = dauer / 10; /* 10% pause am Ende */
  dauer *= 900; /* 90% ms -> us */
  while (dauer > 0)
  {
    digitalWrite(SPKR, HIGH);
    delayMicroseconds(lautstaerke);
    digitalWrite(SPKR, LOW);
    delayMicroseconds(ton - lautstaerke);
    dauer -= ton;
  }
  while (pause-->0)
  {
    _delay_ms(1);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  spiele(D0, sechzehntel);
  spiele(D0, dreisechzehntel);
  spiele(D0, sechzehntel);
  
  spiele(G0, viertel);
  spiele(G0, viertel);
  spiele(A0, viertel);
  spiele(A0, viertel);

  spiele(D1, dreiachtel);
  spiele(H0, achtel);
  spiele(G0, dreisechzehntel);
  spiele(G0, sechzehntel);
  spiele(H0, dreisechzehntel);
  spiele(G0, sechzehntel);
  
  spiele(E0, viertel);
  spiele(C1, halbe);
  spiele(A0, dreisechzehntel);
  spiele(FIS0, sechzehntel);

  spiele(G0, halbe);
  spiele(PAUSE, viertel);
  spiele(G0, dreisechzehntel);
  spiele(A0, sechzehntel);

  spiele(H0, viertel);
  spiele(H0, viertel);
  spiele(H0, viertel);
  spiele(C1, dreisechzehntel);
  spiele(H0, sechzehntel);

  spiele(H0, viertel);
  spiele(A0, viertel);
  spiele(PAUSE, viertel);
  spiele(A0, dreisechzehntel);
  spiele(H0, sechzehntel);

  spiele(C1, viertel);
  spiele(C1, viertel);
  spiele(C1, viertel);
  spiele(D1, dreisechzehntel);
  spiele(C1, sechzehntel);

  spiele(H0, halbe);
  spiele(PAUSE, viertel);
  spiele(D1, dreisechzehntel);
  spiele(D1, sechzehntel);

  spiele(D1, viertel);
  spiele(H0, dreisechzehntel);
  spiele(G0, sechzehntel);
  spiele(D1, viertel);
  spiele(H0, dreisechzehntel);
  spiele(G0, sechzehntel);

  spiele(D0, halbe);

  spiele(PAUSE, dreiachtel);
}