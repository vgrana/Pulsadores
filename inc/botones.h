/*
 * botones.h
 *
 *  Created on: 20 sep. 2019
 *      Author: valeria
 */

#ifndef PROGRAMS_BOTONES_INC_BOTONES_H_
#define PROGRAMS_BOTONES_INC_BOTONES_H_
#define tiempoEncendido 40
enum Estado {
	Button_Up, Button_Folling, Button_Down, Button_Rising, ultimoCambio
};
typedef void (*buttonHandler)(void);

typedef struct Boton {
	int Estado;
	int ultimoCambio;
	int Apagado_Encendido;
	buttonHandler onRelease;
	buttonHandler onPress;
	int pin;

} Boton;

void estadoIniciar(Boton * boton, buttonHandler onPress1,
		buttonHandler onRelease1, int pin);

void estado(Boton * boton);

#endif /* PROGRAMS_BOTONES_INC_BOTONES_H_ */
