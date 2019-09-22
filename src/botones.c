/*
 * botones.c
 *
 *  Created on: 20 sep. 2019
 *      Author: valeria
 */

#include "botones.h"
#include "sapi.h"

void estadoIniciar(Boton * boton, buttonHandler onPress1,
		buttonHandler onRelease1, int pin) {
	boton->Estado = Button_Up;
	boton->ultimoCambio = tickRead();
	boton->onPress = onPress1;
	boton->onRelease = onRelease1;
	boton->pin=pin;

}

void estado(Boton * boton) {
	int TicketActual = tickRead();
	int tiempoPasado = TicketActual - boton->ultimoCambio;

	switch (boton->Estado) {
	case Button_Up: {
		if (gpioRead(boton->pin) == 0) {

			boton->Estado = Button_Folling;
			boton->ultimoCambio = TicketActual;
		}

		break;
	}

	case Button_Folling: {
		if (tiempoPasado >= tiempoEncendido) {
			if (gpioRead(boton->pin) == 0) {
				//cambiar por boton->onPress();
//				gpioWrite(LEDR, ON);
//				gpioWrite(LEDG, ON);

				boton->onPress();
				boton->Estado = Button_Down;
				boton->ultimoCambio = TicketActual;

			} else {
				boton->Estado = Button_Up;
				boton->ultimoCambio = TicketActual;

			}
		}
		break;
	}

	case Button_Down: {
		if (gpioRead(boton->pin) == 1) {
			boton->Estado = Button_Rising;
			boton->ultimoCambio = TicketActual;
		}
		break;
	}
	case Button_Rising: {
		if (tiempoPasado >= tiempoEncendido) {
			if (gpioRead(boton->pin) == 1) {
				//sin funcion!
//				gpioWrite(LEDR, OFF);
//				gpioWrite(LEDG, OFF);
				//con una funcion!
				boton->onRelease();
				boton->Estado = Button_Up;
				boton->ultimoCambio = TicketActual;
			} else {
				boton->Estado = Button_Down;
				boton->ultimoCambio = TicketActual;
			}
		}
		break;
	}
	}

}

