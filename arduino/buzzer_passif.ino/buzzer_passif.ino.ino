int pinBuzzer = 12;

void setup() {
   // initialise les broches
   pinMode(pinBuzzer, OUTPUT);
}

void loop() {
   for (int x = 0; x < 500 ; x++){
     tone (pinBuzzer, x);
     delay(1);
     }
   for (int x = 500; x > 0 ; x--){
     tone (pinBuzzer, x);
     delay(1);
     }
}