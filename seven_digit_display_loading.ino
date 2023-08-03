void setup(){
    // Only 5 pins beacause my seventh pin died, and six pin(middle line) doesn't need to be used
    for (int i = 3; i < 8; i++){
        pinMode(i, OUTPUT);
    }
}

void loop(){
    for (int i = 3; i < 8; i++){
        digitalWrite(i, HIGH);
        delay(50);
        digitalWrite(i, LOW);
        delay(50);
    }
}
