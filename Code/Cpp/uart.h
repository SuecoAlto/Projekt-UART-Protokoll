//Starta "include guard" för att förhindra dubbelinkludering av denna headerfil.
#ifndef __UART_H
#define __UART_H

//Inkludera STM32F4 enhetsspecifika headerfil. Detta gör att vi kan använda
//specifika typer och funktioner för denna enhet i vår kod.
#include "stm32f4xx.h"

//Inkludera standard I/O-biblioteket. Detta ger oss tillgång till funktioner
//som printf och scanf, vilka är mycket användbara för I/O-operationer.
#include <stdio.h>

//Deklarera funktionen USART2_Init. Denna funktion initierar USART2-hårdvaran
//på vår STM32-enhet, och förbereder den för att skicka och ta emot data.
//Vi behöver deklarera den här för att andra filer som inkluderar denna
//headerfil ska kunna kalla på den.
void USART2_Init(void);

//Deklarera funktionen test_setup. Denna funktion är troligen ansvarig för att
//sätta upp någon sorts testmiljö eller testfall för vår kod. Precis som med
//USART2_Init behöver vi deklarera den här för att andra filer ska kunna
//kalla på den.
void test_setup(void);

// Avsluta vår headerfil. Om __UART_H redan var definierat när vi
// inkluderade denna fil, kommer preprocessor att hoppa över allt mellan
// ifndef och denna endif.
#endif
