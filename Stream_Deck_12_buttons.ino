// Key definitions
#define BUTTON_KEY1 KEY_F13
#define BUTTON_KEY2 KEY_F14
#define BUTTON_KEY3 KEY_F15
#define BUTTON_KEY4 KEY_F16
#define BUTTON_KEY5 KEY_F17
#define BUTTON_KEY6 KEY_F18
#define BUTTON_KEY7 KEY_F19
#define BUTTON_KEY8 KEY_F20
#define BUTTON_KEY9 KEY_F21
#define BUTTON_KEY10 KEY_F22
#define BUTTON_KEY11 KEY_F23
#define BUTTON_KEY12 KEY_F24
 
// Pin definitions
#define BUTTON_PIN1 2
#define BUTTON_PIN2 3
#define BUTTON_PIN3 4
#define BUTTON_PIN4 5
#define BUTTON_PIN5 6
#define BUTTON_PIN6 7
#define BUTTON_PIN7 8
#define BUTTON_PIN8 9
#define BUTTON_PIN9 18
#define BUTTON_PIN10 16
#define BUTTON_PIN11 14
#define BUTTON_PIN12 15
 
// Include Library
#include "Keyboard.h"
#include <FastLED.h>

// WS2812b strip settings
#define DATA_PIN 10
#define NUM_LEDS 12

// Define the array of leds
CRGB leds[NUM_LEDS];

// Button helper class for handling press/release and debouncing
class button {
  public:
  const char key;
  const uint8_t pin;
 
  button(uint8_t k, uint8_t p) : key(k), pin(p){}
 
  void press(boolean state){
    if(state == pressed || (millis() - lastPressed  <= debounceTime)){
      return; // Nothing to see here, folks
    }
 
    lastPressed = millis();
 
    state ? Keyboard.press(key) : Keyboard.release(key);    
    pressed = state;
  }
 
  void update(){
    press(!digitalRead(pin));
  }
 
  private:
  const long debounceTime = 30;
  unsigned long lastPressed;
  boolean pressed = 0;
} ;
 
// Button objects, organized in array
button buttons[] = {
  {BUTTON_KEY1, BUTTON_PIN1},
  {BUTTON_KEY2, BUTTON_PIN2},
  {BUTTON_KEY3, BUTTON_PIN3},
  {BUTTON_KEY4, BUTTON_PIN4},
  {BUTTON_KEY5, BUTTON_PIN5},
  {BUTTON_KEY6, BUTTON_PIN6},
  {BUTTON_KEY7, BUTTON_PIN7},
  {BUTTON_KEY8, BUTTON_PIN8},
  {BUTTON_KEY9, BUTTON_PIN9},
  {BUTTON_KEY10, BUTTON_PIN10},
  {BUTTON_KEY11, BUTTON_PIN11},
  {BUTTON_KEY12, BUTTON_PIN12},
};
 
const uint8_t NumButtons = sizeof(buttons) / sizeof(button);
const uint8_t ledPin = 17;

  // KEY - LED path
  //     Key1     Key2     Key3     Key4
  //  -  Led0  -  Led1  -  Led2  -  Led3  -
  //     Key5     Key6     Key7     Key8  |
  //  -  Led7  -  Led6  -  Led5  -  Led4  -
  //  |  Key9     Key10    Key11    Key12
  //  -  Led8  -  Led9  -  Led10 -  Led11

void setup() { 
  // Set WS22812b LED configuration for application color based on keystrokes
  FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, NUM_LEDS);
  FastLED.setBrightness(40);
  leds[0].setRGB( 0, 174, 66); //Bambu Studio
  leds[1].setRGB( 247, 112, 1); //Fusion 360
  leds[2].setRGB( 49, 168, 255); //Photoshop
  leds[3].setRGB( 0, 153, 203); //Volume Up
  leds[4].setRGB( 255, 0, 0); //Volume Mute
  leds[5].setRGB( 0, 151, 157); //Arduino IDE
  leds[6].setRGB( 52, 168, 83); //Android Studio
  leds[7].setRGB( 33, 165, 242); //VS Code
  leds[8].setRGB( 15, 212, 246); //Uniget UI
  leds[9].setRGB( 76, 111, 146); //MQTT Explorer
  leds[10].setRGB( 181, 169, 116); //MobaXterm
  leds[11].setRGB( 0, 57, 203); //Volume Minus
  FastLED.show();

  // Safety check. Ground pin #1 (RX) to cancel keyboard inputs.
  pinMode(1, INPUT_PULLUP);
  if(!digitalRead(1)){
    failsafe();
  }
 
  // Set LEDs Off. Active low.
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, HIGH);
  TXLED0;
 
  for(int i = 0; i < NumButtons; i++){
    pinMode(buttons[i].pin, INPUT_PULLUP);
  }

}

void loop() {
  for(int i = 0; i < NumButtons; i++){
    buttons[i].update();
  }
}
 
void failsafe(){
  for(;;){} // Just going to hang out here for awhile :D
}
