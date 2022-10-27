
/*******************************************************************************
 * @file    DHT22_PCSE/Drivers/DHT22/Src/DHT22.c
 * @author  Victor Belaunde
 * @brief  Implementación de un driver para el sensor digital de temperatura y humedad DHT22
 * El driver es modular y escalable para varias arquitecturas
 *
 *******************************************************************************/


/*******************************************************************************
 * Includes
 ******************************************************************************/

#include <stdio.h>
#include "DHT22_port.h"
#include "DHT22.h"


/*******************************************************************************
 * Typedef
 ******************************************************************************/

typedef bool bool_t;

/*******************************************************************************
 * Define
 ******************************************************************************/

//none


/*******************************************************************************
 * Private function prototypes
 ******************************************************************************/

//none


/*******************************************************************************
 * Private global variables
 ******************************************************************************/

static uint8_t Hum_byte1, Hum_byte2, Temp_byte1, Temp_byte2;
static uint16_t SUM
static float Humedad      = -99.0;
static float Temperatura   = -99.0;


/**
 * @brief	Funcion para iniciar la comunicación con DHT22
 * @param	none
 * @return	none
 */
void DHT_start(){
	Set_Pin_Output (DHT_PIN);  // setea el PIN como salida

	Gpio_Write(DHT_PIN, 0); // pone el PIN bajo para iniciar la comununicacion
	delay_us(18000);

	Gpio_Write(DHT_PIN, 1);
	delay_us(20);

	Set_Pin_Input(DHT_PIN);    // setea el PIN como entrada

}

/**
 * @brief	Funcion para revisar si el sensor responde con la señal de inicio
 * @param	DHT_pin: Pin donde se encuentra el sensor
 * @return	Responde: Confirma si el sensor respondió o no
 */
uint8_t DHT_responde(DHT_Pin){
	uint8_t Responde = 0;
	delay_us(40);

	if (!(Gpio_Read(DHT_Pin)))
	{
		delay_us(80);

		if ((Gpio_Read(DHT_Pin)))
			{
			Responde = 1;

			}
		else Responde = -1;
	}
	while ((Gpio_Read(DHT_Pin)));   // espera hasta que se pone en 0

	return Responde;
}


/**
 * @brief	Funcion para tomar las mediciones de temperatura y humedad que emite el sensor con 40bits
 * @param	DHT_pin: Pin donde se encuentra el sensor
 * @return	Responde: Confirma si el sensor respondió o no
 */
uint8_t DHT_Read (DHT_pin)
{
	uint8_t bit,j;

	for (j=0;j<8;j++)
	{
		while (!(Gpio_Read(DHT_Pin)));   //espera a que cambie a 1

		delay_us(40);

		if (!(Gpio_Read(DHT_Pin)))   // verifica que tipo de nivel es
		{
			bit &= ~(1<<(7-j));   // Escribe un 0
		}
		else bit |= (1<<(7-j));  // Si el PIN es high, escribe 1

		while ((Gpio_Read(DHT_Pin)));  // espera a que cambie a 0
	}
	return bit;
}


/**
 * @brief	Funcion principal que llama al resto de las funciones para iniciar la toma de valores, controla y convierte a temperatura y humedad
 * @param	DHT_pin: Pin donde se encuentra el sensor
 * @return	none:Si está todo OK carga las variables con los valores, de lo contrario llama a la func de error
 */
Toma_Valores(uint8_t DHT_PIN){

	if (DHT_responde(DHT_Pin) == 1) {

		Hum_byte1 = DHT_Read ();
		Hum_byte2 = DHT_Read ();
		Temp_byte1 = DHT_Read ();
		Temp_byte2 = DHT_Read ();
		SUM = DHT_Read();
		if (SUM == (Hum_byte1 + Hum_byte2 + Temp_byte1+ Temp_byte2)){

			Temperatura = ((Temp_byte1<<8)|Temp_byte2);

			Humedad = ((Hum_byte1<<8)|Hum_byte2);
		}
		else{
				Msj_Error();
		}

	}
	else{
		Msj_Error();
	}

}

/**
 * @brief	Funcion para devolver el valor sensado
 * @param	none
 * @return	Temperatura
 */
float Recibe_Temperatura(){
	return Temperatura;
}

/**
 * @brief	Funcion para devolver el valor sensado
 * @param	none
 * @return	Humedad
 */
float Recibe_Humedad(){
	return Humedad;
}


/**
 * @brief	Funcion de error solo carga las variables (temperatura y humedad) con valores no validos
 * @param	none
 * @return	none
 */
void Msj_Error(){

	Temperatura = -99;
	Humedad = -99;
}



