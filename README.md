I created a streamdeck with 12 keys to make it easier for me to use my PC. For my part, I have 9 keys for opening applications and 3 keys for volume control. But it is customizable as desired. I even allowed myself to add LEDs corresponding to the main color of each application.

Equipment list:

 - Arduino Pro Micro
 - Cherry MX Blue (or other) x12
 - WS2812B LED x12
 - 3D Printer
 - Filament in the color of your choice (Personally, I chose black (Bambu) for the shell, blue nebula (Bambu) for the keycaps, and white (Bambu) for the keys that I customized)
 - 3D modeling software (For me it's Fusion 360)
 - Wiring wire
 - Soldering iron...
 - Arduino IDE 2.3.6 software with the Keyboard and FastLED Library installed and Arduino AVR Boards on Board Manager
 
Tutorial:

1. Print the Main_body, plate_switches and Stream Deck Leds Adapter files (0.2mm layer, 20% infill).
2. Install the 12 Cherry MX Blue (or other) on the plate_switches.
3. Solder the wiring to the keys according to the diagram in the DIY Streamdeck 12 key Wiring.pdf file.
4. Prepare the 12 WS2812B LEDs using the Stream Deck LED Adapter in 3x4 LED strips according to the diagram in the DIY Streamdeck 12 key Wiring.pdf file.
5. Install the WS2812B strips on the plate_switches according to the following plan:

```
       Key1     Key2     Key3     Key4
    -  Led0  -  Led1  -  Led2  -  Led3  -
       Key5     Key6     Key7     Key8  |
    -  Led7  -  Led6  -  Led5  -  Led4  -
    |  Key9     Key10    Key11    Key12
    -  Led8  -  Led9  -  Led10 -  Led11
```

7. Solder all the wiring to the Arduino Pro Micro according to the diagram in the DIY Streamdeck 12 key Wiring.pdf file.
8. Install everything on the Main_body.
9. Optional: Create your keycaps using the Cherry MX Keycap Empty file as a reference.
10. Print 12 Cherry MX Keycap Emptys or your custom keycaps, or even, if you're interested, use keys already created in the Cherry MX Keycap Custom file.
11. Install the keycaps on Cherry MX (or other) devices.
12. Connect the Arduino Pro Micro to your PC via USB. A USB3 port on the PC is recommended
13. If the Arduino IDE is not installed, install it. Otherwise, proceed to the next step.
14. Open the Stream_Deck_12_buttons.ino file (check that you have the Library and Board installed).
15. Select your Arduino Leonardo board with the correct COM port.
16. If you want to change the color of an LED, this is located at the beginning of the "void setup" section with the RGB codes. Do not exceed the setBrightness parameter to 60, otherwise there is a risk of over-consumption of too much power on the USB port.
17. Upload and enjoy.

