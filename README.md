# PCSE
REPOSITORIO PARA EL TRABAJO FINAL DE PROTOCOLO DE COMUNICACIÓN DE SISTEMAS EMBEBIDOS


Se utilizará un sensor DHT22, una placa Nucleo F429ZI y comunicación vías UART con un monitor seria conectado a un computador.
Se utiliza un formato de datos sobre una línea única para la comunicación y sincronización entre un MCU y el sensor DHT22
Los datos consisten de partes decimales y enteras. El bloque completo de datos consiste en 40 bits, y el sensor envía primero el bit de datos más alto.

ESTRUCURA DEL DRIVER:

DHT22
  --->
      INC
       -->DHT22.h
       -->DHT22_port.h
      SRC
      -->DHT22.c.      Archivo con funciones del driver genérico, las cuales son llamadas desde la aplicación(capa superior)
      -->DHT22_port.c. Archivo para comunicarse con el hardware(port) y abstraído de la capa de aplicación
      

Archivo Main con la aplicación del drive. 
Solo se utilizan 3 funciones para conseguir los valores censados.
Realiza la toma cada 3 seg
En caso de error en la comunicación o en la conversión devuelve -99.


SE DEBEN IMPLEMENTAR EN LA APLICACIÓN LAS SIGUIENTES FUNCIONES

		DHT_start();
    
    Toma_Valores(DHT_PIN); // CON EL PIN DONDE SE ENCUENTRA CONECTADO EL SERSOR DHT22
    
    Recive_Temperatura();
    
    Recive_Humedad();




