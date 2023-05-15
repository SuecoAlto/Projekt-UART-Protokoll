#include "UART.h" //Inkluderar headerfilen för UART (Universal Asynchronous Receiver/Transmitter) som definierar viktiga prototyper och konstanter.

void USART2_Init(void) { //Initialiserar USART2, en instans av UART.

// 1. Aktiverar klockan för USART2

RCC->APB1ENR |= 0x20000; //Sätter bit 17 i APB1ENR-registret till 1, vilket ger klocktillgång till USART2.

// 2. Aktiverar klockan för GPIOA(portA)

RCC->AHB1ENR |= 0x01; //Sätter bit 0 i AHB1ENR-registret till 1, vilket ger klocktillgång till GPIOA.

// 3. Ställer in pins PA2 och PA3 på GPIOA till att ha alternativa funktioner
GPIOA->MODER &= ~0x00F0; //Rensar bitarna 4-7 för att förbereda pins PA2 och PA3 för alternativa funktioner.

GPIOA->MODER |= 0x00A0; //Sätter bitarna 5 och 7 till 1, vilket aktiverar alternativa funktioner för pins PA2 och PA3.

// 4. Väljer vilken alternativ funktion pins PA2 och PA3 ska ha.
GPIOA->AFR[0] &= ~0xFF00; //Rensar bitarna 8-15 för att förbereda för att ställa in den alternativa funktionen för pins PA2 och PA3.
GPIOA->AFR[0] |= 0x7700; //Sätter bitarna 8-11 och 12-15 till '0111', vilket ställer in den alternativa funktionen för pins PA2 och PA3 till USART2.

/* Konstruktion av enhetens kommunikation avslutas */

// Konfiguration utav UART

USART2->BRR = 0x0683; //Ställer in baudraten till 9600bps genom att skriva 0x0683 till BRR-registret. Detta med hjälp av hexadecimalen 0x0683 (9600bps).
USART2->CR1 = 0x000C; //Ställer in USART2 att arbeta med 8 bitars data, 1 stoppbit och ingen paritet genom att skriva 0x000C till CR1-registret.
USART2->CR2 = 0x000; //Rensar CR2-registret, vilket inte är nödvändigt i denna konfiguration. Nollställer CR2.
USART2->CR3 = 0x000; //Rensar CR3-registret, vilket inte är nödvändigt i denna konfiguration. Nollställer CR3.
USART2->CR1 |= 0x2000; //Aktiverar USART2 genom att sätta bit 13 i CR1-registret till 1.

}
// UART Write. Skriver en byte data till USART2.
int USART2_write(int ch){ //Deklarerar skrivfunktionen (Överföringen av data till terminalen)

  while(!(USART2->SR & 0x0080)){} //Sätter vi ett krav som kontrollerar att statusen på överföringen är tom och kan ta emot nästa karaktär (byte)
  USART2->DR = (ch & 0xFF); //Sätter överföringen av byten till dataregistret

  return ch;

}
// UART Read. Läser en byte data från USART.
int USART2_read(void){ //Deklarerar läsfunktionen (mottagning av information)

  while(!(USART2->SR & 0x0020)){} //Sätter vi ett krav som kontrollerar om det finns mer data att hämta
  return USART2->DR; //Läser datan från dataregistret.
}
