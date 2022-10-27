
/*******************************************************************************
 * @file    DHT22_PCSE/Drivers/DHT22/DHT22_port.c
 * @author  Victor Belaunde
 * @brief  Implementación de una interface para conectar el microcontrolador STM32 con el driver DHT22
 *
 *
 *******************************************************************************/


/*******************************************************************************
 * Includes
 ******************************************************************************/

#include <stdio.h>
#include <main.h>
#include "DHT22_port.h"


/*******************************************************************************
 * Typedef
 ******************************************************************************/

typedef bool bool_t;

/*******************************************************************************
 * Define
 ******************************************************************************/

#define DHT_PORT GPIOA //Se instrumenta esta macro para definir que grupo de pines se utilizará


/*******************************************************************************
 * Private function prototypes
 ******************************************************************************/

//none


/*******************************************************************************
 * Private global variables
 ******************************************************************************/

//none


/*******************************************************************************
 * Funciones
 ******************************************************************************/

/**
 * @brief	Funcion para configurar el PIN como salida
 * @param	GPIO_Pin: para el pin especifico del STM32. Se asume que el grupo de
 * @return	none
 */
void Set_Pin_Output (uint16_t GPIO_Pin)
{
	GPIO_InitTypeDef GPIO_InitStruct = {0};
	GPIO_InitStruct.Pin = GPIO_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(DHT_PORT, &GPIO_InitStruct);
}


/**
 * @brief	Funcion para configurar el PIN como entrada
 * @param	*GPIOx para el grupo de pin y GPIO_Pin para el pin especifico ambos del STM32
 * @return	none
 */
void Set_Pin_Input (uint16_t GPIO_Pin)
{
	GPIO_InitTypeDef GPIO_InitStruct = {0};
	GPIO_InitStruct.Pin = GPIO_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	HAL_GPIO_Init(DHT_PORT, &GPIO_InitStruct);
}


/**
 * @brief	Funcion para escribir en el GPIO pasado y toma como valor de la macro DHT_PORT
 * @param	GPIO_pin: Es el pin donde se escribe el nivel
 * @param	nivel: 1 o 0
 * @return	none
 */
void Gpio_Write(GPIO_Pin, nivel){

	HAL_GPIO_WritePin (DHT_PORT, GPIO_Pin, nivel);

}

/**
 * @brief	Funcion para leer en el GPIO pasado y toma como valor de la macro DHT_PORT
 * @param	GPIO_pin: Es el pin donde se lee
 * @return	El valor del pin del puerto de entrada
 */
uint8_t Gpio_Read(uint8_t GPIO_Pin){

	return HAL_GPIO_ReadPin (DHT_PORT, GPIO_Pin);

}

/**
 * @brief	Funcion demoras en microsegundos que inicia en 0 uSeg hasta llegar al valor pasado por parametro
 * @param	us: Microsegundos que se quiere demorar
 * @return	none
 */
void delay_us (uint16_t us)
{
	__HAL_TIM_SET_COUNTER(&htim6,0);
	while (__HAL_TIM_GET_COUNTER(&htim6) < us);  // espera hasta que llega al valor pasado como parametro

}



