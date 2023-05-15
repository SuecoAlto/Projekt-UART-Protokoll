//Inkludera led.h, headerfilen som innehåller deklarationen av Led-klassen och dess metoder.
#include "led.h"

//Skapa tre variabler av typen LedState_Type som kommer att användas för att lagra LED-lampornas tillstånd.
LedState_Type led1_state;
LedState_Type led2_state;
LedState_Type led3_state;

//Skapa en instans av Led-klassen med namnet led1. Denna LED är röd och startar i tillståndet ON.
Led led1(RED,ON);

//Definiera huvudfunktionen. Denna funktion kommer att köras när programmet startar.
int main(void){
  USART2_Init(); //Initiera USART2, detta är sannolikt nödvändigt för att LED-lamporna ska kunna kommunicera med andra delar av systemet.

  Led led2(BLUE,ON); //Skapa en instans av Led-klassen med namnet led2. Denna LED är blå och startar i tillståndet ON.

  Led *led3 = new Led(YELLOW,ON); //Skapa en dynamiskt allokerad instans av Led-klassen med namnet led3. Denna LED är gul och startar i tillståndet ON.

  led1_state = led1.getState(); //Läs och lagra tillståndet av led1 i variabeln led1_state.

  led1.setState(OFF); //Ändra tillståndet av led1 till OFF.

  delete led3; //Radera den dynamiskt allokerade LED-instansen led3 för att frigöra allokerat minne.

  while(1){} //Skapa en oändlig loop. Detta är vanligt i inbyggda system där programmet ska fortsätta köra så länge systemet är påslaget.

}
