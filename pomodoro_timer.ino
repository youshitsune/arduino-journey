void setup() {
    pinMode(2, OUTPUT);
    pinMode(3, INPUT);
}

void run(){
    while (1==1){
        delay(2700000);
        tone(9, 1000);
        delay(250);
        noTone(9);
        digitalWrite(2, HIGH);
        delay(120000);
        digitalWrite(2, LOW);
    }  
}

void loop() {
    if (digitalRead(3) == HIGH){
        run();  
    }
}
