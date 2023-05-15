#ifndef LED_H
#define LED_H

#include <stdint.h>
#include "UART.h"
#include "stm32f4xx.h" //Inkluderar Device Header för STM32F4xx serien. Denna fil innehåller specifikationer för hårdvaran på det specifika chipet.

//Definierar vilken GPIO (General Purpose Input/Output) port som ska användas för LED-funktionen. GPIOB används i detta fall.
#define LED_PORT GPIOB

//Definierar klocksignalen för den valda GPIO-porten. I detta fall används bit 1 för att aktivera klocksignalen för GPIOB.
#define LED_PORT_CLOCK (1U<<1)

//Definierar de specifika pins för olika LED-färger. Varje pin är kopplad till en specifik LED på hårdvaran.
#define LED_RED_PIN (1U<<14)
#define LED_GREEN_PIN (1U<<12)
#define LED_BLUE_PIN (1U<<15)
#define LED_YELLOW_PIN (1U<<13)

//Definierar mode bits för att sätta specifika LED-pins som output. Dessa värden används för att ställa in MODER-registret för den specifika GPIO-porten.
#define LED_RED_MODE_BIT (1U<<28)
#define LED_GREEN_MODE_BIT (1U<<24)
#define LED_YELLOW_MODE_BIT (1U<<26)
#define LED_BLUE_MODE_BIT (1U<<30)

//Definierar en enum för de olika LED-färgerna för att göra koden lättare att läsa och förstå.
typedef enum {
  RED = 0,
  GREEN,
  YELLOW,
  BLUE
}LedColor_Type;

//Definierar en enum för de olika tillstånd som en LED kan vara i. Detta gör koden mer läsbar och förståelig.
typedef enum {
  OFF = 0,
  ON = 1
}LedState_Type;

// Definierar en LED-klass som har attribut för färg och tillstånd. Detta tillåter oss att skapa LED-objekt som kan ha specifika egenskaper och beteenden.
class Led{

  private:
      LedColor_Type color; //Färgattribut för LED-objektet
      LedState_Type state; //Tillståndsattribut för LED-objektet

  public:

      Led(LedColor_Type _color,LedState_Type _state); //Konstruktor för LED-klass. Tillåter oss att skapa ett LED-objekt med en specifik färg och tillstånd.
      void setState(LedState_Type _state);  //Funktion för att sätta tillståndet för LED-objektet.
      LedState_Type getState() const; //Funktion för att få tillståndet för LED-objektet.

};

#endif
