# TrabajoSemaforos

            Trabajo Practico Semaforos
              Sistemas Operativos y redes
   
   Alumno: Alburquerque Nicolas
   Profesores: Noelia Sosa , Mariano Vargas
   
   
   
   En el trabajo se busco implementar lo aprendido en clase, principalmente Semaforos, en el cual se pide hacer competir a 3 personas (threads) para lograr hacer dos hamburguesas
  , para eso se debe llamar a las funciones "cortar" "salando" "planchando" "horneando" las cuales al tener que ser secuenciales y solo existir un elemento, las mismas 
  contienen semaforos para asi no pisarse una a la otra ni utilizar dos threads los mismos elementos. Las funciones tambien tienen un sleep para asi simular que los 
  competidores estan cocinando.
  En el Trabajo tambien se busca leer un archivo, para eso se utiliza la funcion "lectura" donde se abre el archivo y escribe su contenido en la terminal. Tambien escribe 
  la salida en un archivo de texto, para cumplir con esto se utiliza un "fopen" con "w" para asi crear un archivo de texto y poder escribir en el, una vez abierto se utiliza
  "fprintf" para poder almacenar en el archivo, y luego con "fclose" cerrar el archivo.
  En el trabajo opto por solo usar tres semaforos, los cuales van a empezar en "1" asi el primero que llegue entra directamente.
  Por ultimo tambien se opto por cada thread ejecutado llame a funciones diferentes los cuales son llamados "cocinandoando", 2 y 3 respectivamente segun el orden de los threads
  saliendo por la terminal cada una de las acciones que realiza el equipo y terminando cuando uno de los equipos logra hacer las dos hamburguesas.
  
  
   
   
