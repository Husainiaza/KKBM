#include <Adafruit_NeoPixel.h>

#define PIN 5
#define NUMPIXELS 300 // Popular NeoPixel ring size

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

#define DELAYVAL 10 // Time (in milliseconds) to pause between pixels

void setup() {
  
  pixels.begin(); 
  
}

void loop() {
  pixels.clear(); // padam semua LED

  for(int i=0; i<NUMPIXELS; i++) { // For each pixel...

    // pixels.Color() mengambil nilai dari 0,0,0 sehingga 255,255,255
    pixels.setPixelColor(i, pixels.Color(0, 150, 0));// RGB yang dipilih warna HIJAU
    pixels.show();  
    delay(DELAYVAL); 
  }

  for(int i=0; i<NUMPIXELS; i++) { // For each pixel...

    // pixels.Color() mengambil nilai dari 0,0,0 sehingga 255,255,255
    pixels.setPixelColor(i, pixels.Color(150, 0, 0));// RGB yang dipilih warna HIJAU
    pixels.show();  
    delay(DELAYVAL); 
  }

   for(int i=0; i<NUMPIXELS; i++) { // For each pixel...

    // pixels.Color() mengambil nilai dari 0,0,0 sehingga 255,255,255
    pixels.setPixelColor(i, pixels.Color(0, 0, 150));// RGB yang dipilih warna HIJAU
    pixels.show();  
    delay(DELAYVAL); 
  }

rainbow(10);
  
}

void rainbow(int wait) {
  for(long firstPixelHue = 0; firstPixelHue < 5*65536; firstPixelHue += 256) {
    for(int i=0; i<pixels.numPixels(); i++) { 
      int pixelHue = firstPixelHue + (i * 65536L / pixels.numPixels());
      pixels.setPixelColor(i, pixels.gamma32(pixels.ColorHSV(pixelHue)));
    }
    pixels.show();
    delay(wait);
  }
}
