
/*******************************************************************************
 * @file    DHT22_PCSE/Drivers/DHT22/Inc/DHT22.h
 * @author  Victor Belaunde
 * @brief  Implementación de un driver para el sensor digital de temperatura y humedad DHT22
 * El driver es modular y escalable para varias arquitecturas
 *
 *******************************************************************************/

#ifndef DHT22_INC_DHT22_H_
#define DHT22_INC_DHT22_H_

/*******************************************************************************
 * Define
 ******************************************************************************/

//none


/*******************************************************************************
 * Private function prototypes
 ******************************************************************************/
/**
 * @brief	Funcion para revisar si el sensor responde con la señal de inicio
 * @param	DHT_pin: Pin donde se encuentra el sensor
 * @return	Responde: Confirma si el sensor respondió o no
 */
uint8_t DHT_responde(uint8_t DHT_Pin);

/**
 * @brief	Funcion para iniciar la comunicación con DHT22
 * @param	none
 * @return	none
 */
void DHT_start(void);

/**
 * @brief	Funcion para tomar las mediciones de temperatura y humedad que emite el sensor con 40bits
 * @param	DHT_pin: Pin donde se encuentra el sensor
 * @return	Responde: Confirma si el sensor respondió o no
 */
uint8_t DHT_Read (uint8_t DHT_pin);

/**
 * @brief	Funcion principal que llama al resto de las funciones para iniciar la toma de valores, controla y convierte a temperatura y humedad
 * @param	DHT_pin: Pin donde se encuentra el sensor
 * @return	none:Si está todo OK carga las variables con los valores, de lo contrario llama a la func de error
 */
uint8_t Toma_Valores(uint8_t DHT_PIN);

/**
 * @brief	Funcion para devolver el valor sensado
 * @param	none
 * @return	Humedad
 */
float Recibe_Humedad(void);

/**
 * @brief	Funcion para devolver el valor sensado
 * @param	none
 * @return	Temperatura
 */
float Recibe_Temperatura(void);


void Msj_Error(void);

#endif /* DHT22_INC_DHT22_H_ */
