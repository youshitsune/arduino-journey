#include <Adafruit_GFX.h>
#include <MCUFRIEND_kbv.h>

#define BLACK   0x0000
#define BLUE    0x001F
#define RED     0xF800
#define GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define WHITE   0xFFFF

MCUFRIEND_kbv tft;

int DHpin = 52; // input/output pin
byte dat[5];   
byte read_data()
{
  byte i = 0;
  byte result = 0;
  for (i = 0; i < 8; i++) {
      while (digitalRead(DHpin) == LOW); // wait 50us
      delayMicroseconds(30); //The duration of the high level is judged to determine whether the data is '0' or '1'
      if (digitalRead(DHpin) == HIGH)
        result |= (1 << (8 - i)); //High in the former, low in the post
    while (digitalRead(DHpin) == HIGH); //Data '1', waiting for the next bit of reception
    }
  return result;
}
void start_test()
{
  digitalWrite(DHpin, LOW); //Pull down the bus to send the start signal
  delay(30); //The delay is greater than 18 ms so that DHT 11 can detect the start signal
  digitalWrite(DHpin, HIGH);
  delayMicroseconds(40); //Wait for DHT11 to respond
  pinMode(DHpin, INPUT);
  while(digitalRead(DHpin) == HIGH);
  delayMicroseconds(80); //The DHT11 responds by pulling the bus low for 80us;
  
  if(digitalRead(DHpin) == LOW)
    delayMicroseconds(80); //DHT11 pulled up after the bus 80us to start sending data;
  for(int i = 0; i < 5; i++) //Receiving temperature and humidity data, check bits are not considered;
    dat[i] = read_data();
  pinMode(DHpin, OUTPUT);
  digitalWrite(DHpin, HIGH); //After the completion of a release of data bus, waiting for the host to start the next signal
}



void setup() {
  // Reading TFT ID:
  uint16_t ID = tft.readID();
  Serial.begin(9600);
  Serial.println(ID);
  //Initializing TFT display:
  tft.begin(ID);

    tft.fillScreen(BLACK);
  delay(500);

  //Set cursor:
  tft.setCursor(40, 25);

  //Set text color:
  tft.setTextColor(RED);

  //Set text size:
  tft.setTextSize(10);

  tft.println("TEMP");

  tft.drawFastHLine(0, 240, 320, WHITE);

  tft.setCursor(40, 280);
  tft.setTextColor(BLUE);
  tft.println("HUMD");
  pinMode(53, OUTPUT);
  digitalWrite(53, HIGH);
  pinMode(DHpin, OUTPUT);
  
}

void loop() {
  // Fill TFT Screen with a color:
  start_test();
  Serial.println(dat[2], DEC);
  tft.fillRect(60, 120, 200, 100, BLACK);
  tft.setTextSize(8);
  tft.setTextColor(RED);
  tft.setCursor(60, 120);
  tft.print(dat[2], DEC);
  tft.print(".");
  tft.println(dat[3],DEC);
  tft.fillRect(60, 375, 200, 100, BLACK);
  tft.setCursor(60, 375);
  tft.setTextColor(BLUE);
  tft.print(dat[0], DEC);
  tft.print(".");
  tft.print(dat[1], DEC);
  tft.println("%");
  delay(1000);

}
