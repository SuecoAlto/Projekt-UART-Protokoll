#include "LED.h" //Inkluderar LED.h headerfilen så att denna fil har tillgång till de olika LED-typerna och funktionerna

//Konstruktorn för LED-lamporna
Led::Led(LedColor_Type _color, LedState_Type _state)
{

  // Tilldelar färg och tillstånd för LED-objektet baserat på argumenten som skickas till konstruktorn
  this->color = _color;
  this->state = _state;

  //Aktiverar klockan för LED-porten (GPIOB) för att kunna använda porten
  RCC->AHB1ENR |= LED_PORT_CLOCK;

  //Konfigurera LED-pinsen beroende på deras färg och tillstånd
  switch(_color){

    case RED: //Sätta portläget för Röd LED-konfigurationen till output
      LED_PORT->MODER |= LED_RED_MODE_BIT;
      if(this->state == ON){
        //Tänder Röd LED
        LED_PORT->ODR |= LED_RED_PIN;
      }
      else{
        //Släcker Röd LED
        LED_PORT->ODR &= ~LED_RED_PIN;
      }
      break;

      case YELLOW: //Sätter portläget för Gul LED-konfigurationen till output
      LED_PORT->MODER |= LED_YELLOW_MODE_BIT;
      if(this->state == ON){
        //Tänder Gul LED
        LED_PORT->ODR |= LED_YELLOW_PIN;
      }
      else{
        //Släcker GUL LED
        LED_PORT->ODR &= ~LED_YELLOW_PIN;
      }
      break;

      case BLUE: //Sätta portläget för Blå LED-konfigurationen till output
      LED_PORT->MODER |= LED_BLUE_MODE_BIT;
      if(this->state == ON){
        //Tänder Blå LED
        LED_PORT->ODR |= LED_BLUE_PIN;
      }
      else{
        //Släcker Blå LED
        LED_PORT->ODR &= ~LED_BLUE_PIN;
      }
      break;

      case GREEN: //Sätta portläget för Grön LED-konfigurationen till output
      LED_PORT->MODER |= LED_GREEN_MODE_BIT;
      if(this->state == ON){
        //Tänder Grön LED
        LED_PORT->ODR |= LED_GREEN_PIN;
      }
      else{
        //Släcker Grön LED
        LED_PORT->ODR &= ~LED_GREEN_PIN;
      }
      break;

  }


}

void Led::setState(LedState_Type _state){

  //Ändrar tillståndet för LED-objektet
  this->state = _state;

  //Justerar LED-tillståndet baserat på dess färg
  switch(this->color){

      //om LED Röd/Sätter pin-läget för röd LED till output
    case RED:
      //sätta pin till outputläge
      LED_PORT->MODER |= LED_RED_MODE_BIT;
      //Om önskad status är ON
      if(this->state == ON){
        //Tänd röd led
        LED_PORT->ODR |= LED_RED_PIN;
      }
      else{
        //Släck röd led
        LED_PORT->ODR &= ~LED_RED_PIN;
      }
      break;

      case YELLOW:
      //Sätter pin-läget för gul LED till output
      LED_PORT->MODER |= LED_YELLOW_MODE_BIT;
      //Om önskad status är ON
      if(this->state == ON){
        //Tänd gul led
        LED_PORT->ODR |= LED_YELLOW_PIN;
      }
      else{
        //Släck gul led
        LED_PORT->ODR &= ~LED_YELLOW_PIN;
      }
      break;

      case BLUE:
      //Sätter pin-läget för Blå LED till output
      LED_PORT->MODER |= LED_BLUE_MODE_BIT;
      //Om önskad status är ON
      if(this->state == ON){
        //Tänder blå led
        LED_PORT->ODR |= LED_BLUE_PIN;
      }
      else{
        //släcker blå led
        LED_PORT->ODR &= ~LED_BLUE_PIN;
      }
      break;

      case GREEN:
      //Sätter pin-läget för gröm LED till output
      LED_PORT->MODER |= LED_GREEN_MODE_BIT;
      //Om önskad status är ON
      if(this->state == ON){
        //Tänder grön led
        LED_PORT->ODR |= LED_GREEN_PIN;
      }
      else{
        //Släcker grön led
        LED_PORT->ODR &= ~LED_GREEN_PIN;
      }
      break;
  }

}

LedState_Type Led::getState(void)const{

  //Hämtar tillståndet för LED-objektet baserat på dess färg
  //Ingen specifik åtgärd krävs för att hämta röd, gul, blå eller grön LED-tillstånd
  switch(this->color){

    case RED:
      break;

    case YELLOW:
      break;

    case BLUE:
      break;

    case GREEN:
      break;
  }
             //Returnerar LED-objektets nuvarande tillstånd
             return this->state;
}
