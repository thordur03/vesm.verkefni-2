

const int row[8] = {
  2, 7, 19, 5, 13, 18, 12, 16
};


const int col[8] = {
  6, 11, 10, 3, 17, 4, 8, 9
};

int pixels[8][8];


int x = 5;
int y = 5;

unsigned long lidinn_timi = 0;
int bidtimi = 200;
int buttonState = 0;
int buttonPin = 1;
int button2State = 0;
int button2Pin = 0;
void setup() {
  
  for (int thisPin = 0; thisPin < 8; thisPin++) {
    // initialize the output pins:
    pinMode(col[thisPin], OUTPUT);
    pinMode(row[thisPin], OUTPUT);
    digitalWrite(col[thisPin], LOW);
  }

  for (int x = 0; x < 8; x++) {
    for (int y = 0; y < 8; y++) {
      pixels[x][y] = LOW;
    }
  }
  pixels[x][y] = 1;
  pinMode(buttonPin, INPUT_PULLUP); 

}




void loop() {
  int timi_nuna = millis();
  if(timi_nuna - lidinn_timi > bidtimi) {
    readSensors();
    lidinn_timi = timi_nuna;
    }
  refreshScreen();
  
  
}





void readSensors() {
  int xpos = analogRead(A0);
  int ypos = analogRead(A1);
  int buttonState = digitalRead(buttonPin);
  if(xpos < 200) {
    if(x < 7) {
      x++;  
    }
  }
  if(xpos > 750) {
    if(x > 0) {
      x--;  
    }
  }
   if(ypos > 750) {
    if(y < 7) {
      y++;  
        
    }
  }
  if(ypos < 200) {
    if(y > 0) {
  
      y--;  
      
    }
  }
  
  pixels[x][y] = 1;
  if (buttonState == 0) {
    pixels[x][y] = 0;
  }
  
  
}

void refreshScreen() {
  for (int thisRow = 0; thisRow < 8; thisRow++) {
    digitalWrite(row[thisRow], LOW);
    for (int thisCol = 0; thisCol < 8; thisCol++) {
      int thisPixel = pixels[thisRow][thisCol];
      
      digitalWrite(col[thisCol], thisPixel);

      if (thisPixel == HIGH) {
        digitalWrite(col[thisCol], LOW);
      }
    }   
    digitalWrite(row[thisRow], HIGH);
  }
  
}
void clearScreen() {
  int buttonState = digitalRead(1);
   if(buttonState == 1) {
    x = 0;
    y = 0;
   }
  }
