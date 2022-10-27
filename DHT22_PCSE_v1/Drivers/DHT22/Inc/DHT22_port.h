/*
 * DHT22_port.h
 *
 *  Created on: Oct 26, 2022
 *      Author: VictorBelaunde
 */

#ifndef DHT22_INC_DHT22_PORT_H_
#define DHT22_INC_DHT22_PORT_H_


/*******************************************************************************
 * Define
 ******************************************************************************/

//none


/*******************************************************************************
 * Private function prototypes
 ******************************************************************************/
/**
 * @brief	Funcion para configurar el PIN como salida
 * @param	GPIO_Pin: para el pin especifico del STM32. Se asume que el grupo de
 * @return	none
 */
void Set_Pin_Output (uint16_t GPIO_Pin);

/**
 * @brief	Funcion para configurar el PIN como entrada
 * @param	*GPIOx para el grupo de pin y GPIO_Pin para el pin especifico ambos del STM32
 * @return	none
 */
void Set_Pin_Input (uint16_t GPIO_Pin);

/**
 * @brief	Funcion demoras en microsegundos que inicia en 0 uSeg hasta llegar al valor pasado por parametro
 * @param	us: Microsegundos que se quiere demorar
 * @return	none
 */
void delay_us (uint16_t us);

/**
 * @brief	Funcion para escribir en el GPIO pasado y toma como valor de la macro DHT_PORT
 * @param	GPIO_pin: Es el pin donde se escribe el nivel
 * @param	nivel: 1 o 0
 * @return	none
 */
void Gpio_Write(uint8_t GPIO_Pin, uint8_t nivel);

/**
 * @brief	Funcion para leer en el GPIO pasado y toma como valor de la macro DHT_PORT
 * @param	GPIO_pin: Es el pin donde se lee
 * @return	El valor del pin del puerto de entrada
 */
void Gpio_Read(uint8_t GPIO_Pin);



/*******************************************************************************
 * Private global variables
 ******************************************************************************/

//none






#endif /* DHT22_INC_DHT22_PORT_H_ */
