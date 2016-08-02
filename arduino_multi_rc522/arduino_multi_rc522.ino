/**
  Read a card using a mfrc522 reader on your SPI interface
  Pin layout should be as follows (on Arduino Uno):
  MOSI: Pin 11 / ICSP-4
  MISO: Pin 12 / ICSP-1
  SCK: Pin 13 / ISCP-3
  SS: Pin 10
  RST: Pin 9

  Script is based on the script of Miguel Balboa.
  New cardnumber is printed when card has changed. Only a dot is printed
  if card is the same.

  @version 0.1
  @author Henri de Jong
  @since 06-01-2013
*/

#include <SPI.h>
#include <RFID.h>

#define SS_PIN_1    10
#define RST_PIN_1   9
#define SS_PIN_2    8
#define RST_PIN_2   7
#define SS_PIN_3    6
#define RST_PIN_3   5

RFID rfid1(SS_PIN_1, RST_PIN_1);
RFID rfid2(SS_PIN_2, RST_PIN_2);
//RFID rfid3(SS_PIN_3, RST_PIN_3);

// Setup variables:
int serNum0;
int serNum1;
int serNum2;
int serNum3;
int serNum4;

void clearCard();

void setup()
{
  Serial.begin(115200);
  SPI.begin();
  SPI.setClockDivider(SPI_CLOCK_DIV128);
  rfid1.init();
  rfid2.init();
//  rfid3.init();
}

void loop()
{
  if (rfid1.isCard()) {
    if (rfid1.readCardSerial()) {
      /* With a new cardnumber, show it. */
      Serial.println("Card found 1");
//      serNum0 = rfid1.serNum[0];
//      serNum1 = rfid1.serNum[1];
//      serNum2 = rfid1.serNum[2];
//      serNum3 = rfid1.serNum[3];
//      serNum4 = rfid1.serNum[4];

      //      Serial.println("Cardnumber 1:");
      //      Serial.print("Dec: ");
      //      Serial.print(rfid1.serNum[0], DEC);
      //      Serial.print(", ");
      //      Serial.print(rfid1.serNum[1], DEC);
      //      Serial.print(", ");
      //      Serial.print(rfid1.serNum[2], DEC);
      //      Serial.print(", ");
      //      Serial.print(rfid1.serNum[3], DEC);
      //      Serial.print(", ");
      //      Serial.print(rfid1.serNum[4], DEC);
      //      Serial.println(" ");
      //      clearCard();
    }
  }
  
  if (rfid2.isCard()) {
    if (rfid2.readCardSerial()) {
      Serial.println("Card found 2");
//      serNum0 = rfid2.serNum[0];
//      serNum1 = rfid2.serNum[1];
//      serNum2 = rfid2.serNum[2];
//      serNum3 = rfid2.serNum[3];
//      serNum4 = rfid2.serNum[4];

      //      Serial.println("Cardnumber 2:");
      //      Serial.print("Dec: ");
      //      Serial.print(rfid2.serNum[0], DEC);
      //      Serial.print(", ");
      //      Serial.print(rfid2.serNum[1], DEC);
      //      Serial.print(", ");
      //      Serial.print(rfid2.serNum[2], DEC);
      //      Serial.print(", ");
      //      Serial.print(rfid2.serNum[3], DEC);
      //      Serial.print(", ");
      //      Serial.print(rfid2.serNum[4], DEC);
      //      Serial.println(" ");
      //      clearCard();
    }
  }

//  if (rfid3.isCard()) {
//    if (rfid3.readCardSerial()) {
//      Serial.println("Card found 3");
//      serNum0 = rfid3.serNum[0];
//      serNum1 = rfid3.serNum[1];
//      serNum2 = rfid3.serNum[2];
//      serNum3 = rfid3.serNum[3];
//      serNum4 = rfid3.serNum[4];
//
//      //      Serial.println("Cardnumber 3:");
//      //      Serial.print("Dec: ");
//      //      Serial.print(rfid3.serNum[0], DEC);
//      //      Serial.print(", ");
//      //      Serial.print(rfid3.serNum[1], DEC);
//      //      Serial.print(", ");
//      //      Serial.print(rfid3.serNum[2], DEC);
//      //      Serial.print(", ");
//      //      Serial.print(rfid3.serNum[3], DEC);
//      //      Serial.print(", ");
//      //      Serial.print(rfid3.serNum[4], DEC);
//      //      Serial.println(" ");
//      //      clearCard();
//    }
//  }

  //  if (rfid1.serNum[0] == 136
  //      && rfid1.serNum[1] == 5
  //      && rfid1.serNum[2] == 53
  //      && rfid1.serNum[3] == 169
  //      && rfid1.serNum[4] == 17
  //     ) {
  //    Serial.println("CARD 1");
  //    clearCard();
  //    rfid1.halt();
  //  } else if (rfid1.serNum[0] == 136
  //             && rfid1.serNum[1] == 5
  //             && rfid1.serNum[2] == 57
  //             && rfid1.serNum[3] == 24
  //             && rfid1.serNum[4] == 172
  //            ) {
  //    Serial.println("CARD 2");
  //    clearCard();
  //    rfid1.halt();
  //  }

  rfid1.halt();
  rfid2.halt();
//  rfid3.halt();
}

void clearCard()  {
  rfid1.serNum[0] = 0;
  rfid1.serNum[1] = 0;
  rfid1.serNum[2] = 0;
  rfid1.serNum[3] = 0;
  rfid1.serNum[4] = 0;

  rfid2.serNum[0] = 0;
  rfid2.serNum[1] = 0;
  rfid2.serNum[2] = 0;
  rfid2.serNum[3] = 0;
  rfid2.serNum[4] = 0;

//  rfid3.serNum[0] = 0;
//  rfid3.serNum[1] = 0;
//  rfid3.serNum[2] = 0;
//  rfid3.serNum[3] = 0;
//  rfid3.serNum[4] = 0;
}

