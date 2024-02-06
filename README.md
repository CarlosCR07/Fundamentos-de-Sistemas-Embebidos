**FUNDAMENTOS DE SISTEMAS EMBEBIDOS - FI - UNAM**
*P1. Interfaz física*
Material electrónico:
- 1 potenciómetro mayor a 100 kOhms
- 2 Comparadores encapsulado con 4 unidades ... https://www.steren.com.mx/comparador-lineal-cuadruple.html?gclid=CjwKCAjw3qGYBhBSEiwAcnTRLgH7j2Bj3lywlUPsNKAzBurkz0MpyGdoV9cvFxCz-VqDmP_3FXr42RoCMY4QAvD_BwE
- 8 opto-asilador/acoplador con salida de transistor ... https://www.steren.com.mx/opto-aislador-con-salida-de-transistor-encapsulado-730a-04.html
- 8 LED rojos o verdes
- 10 resistores 330 Ohms
- 10 resistores 10k Ohms
- 2 protoboard
- 1 batería de 9V
- 1 Rasspberry pi 3B+ (proporcionadas por la Facultad de Ingeniería)
- 1 cargador para tarjeta embebida
- Jumpers

Material bibliográfico/referencias

- Comparardores  https://www.electronics-tutorials.ws/opamp/op-amp-comparator.html
- Hoja de especificaciones 339 https://www.google.com/url?sa=t&source=web&rct=j&url=https://www.ti.com/lit/gpn/lm339&ved=2ahUKEwirysG31uz5AhVPkmoFHYA1BdMQFnoECAgQAQ&usg=AOvVaw3ktJ830HIEcI4axY3UKKSY
- Opto-aisladores  https://www.jameco.com/Jameco/workshop/Howitworks/what-is-an-optocoupler-and-how-it-works.html
- Libro Exploring Raspberry Pi: https://onlinelibrary-wiley-com.pbidi.unam.mx:2443/doi/book/10.1002/9781119211051
         - Respositorio Libro: https://github.com/derekmolloy/exploringrpi/
- Raspberry Pi PINOUT https://www.researchgate.net/publication/351755761/figure/fig2/AS:1025960279302144@1621619400109/Schematic-zoom-of-the-Raspberry-Pi-3-B-pins-Adapted-from-14.ppm


*P2 Comunicación sistemas embebidos*
Conocer distintos protocolos y canales de comunicación utilizados en sistemas embebidos (I2C, SPI, UART, Sockets). Realizar una comparación entre los mismos y determinar el uso de dicho protocolo o canal de comunicación
Conexiones:
Pinout Raspberry Pi: https://roboticsbackend.com/raspberry-pi-3-pins/
Pinout Arduino: https://roboticsbackend.com/arduino-uno-pins-a-complete-practical-guide/

Es recomendado utilizar una fuente de energía alterna, al puerto USB de la tarjeta Raspberry Pi, para alimentar la tarjeta Arduino. Así como los circuitos de cambio de niveles lógicos de voltaje:
Alimentación: https://docs.arduino.cc/learn/electronics/power-pins#choosing-a-power-input
                         https://www.geekfactory.mx/tutoriales-arduino/alimentar-el-arduino-la-guia-definitiva/
3.3V Salida 
->

5V Entrada: https://next-hack.com/index.php/2020/02/15/how-to-interface-a-3-3v-output-to-a-5v-input/
5V Salida -> 3.3V Entrada: https://next-hack.com/index.php/2017/09/15/how-to-interface-a-5v-output-to-a-3-3v-input/


Para comunicación I2C y SPI la tarjeta Raspbetty Pi será utilizado como el maestro y la tarjeta Arduino como el esclavo
I2C: https://roboticsbackend.com/raspberry-pi-master-arduino-slave-i2c-communication-with-wiringpi/
SPI: https://roboticsbackend.com/raspberry-pi-master-arduino-uno-slave-spi-communication-with-wiringpi/

Para la comunicación UART se utilizará el puerto USB de ambas tarjetas

UART: https://roboticsbackend.com/raspberry-pi-arduino-serial-communication/

Sockets: https://github.com/Mad-Scientist-Monkey/sockets-ccpp-rpi

*PROYECTO FINAL*
Instalaciones para el correcto funcionamiento de ROS(PC y RBpi) + Ubuntu(PC) + Raspbian(RBpi) + Arduino(RBpi)
Esto es para su PC
      - Instalación de WSL con Ubuntu 20.04 para Windows 10 o superior
Opción 1: 
 - Instalar Ubuntu 20.04 desde Microsoft Store
 - Para tener capacidades gráficas: https://learn.microsoft.com/en-us/windows/wsl/tutorials/gui-apps
 
  Opción 2:
 - Con esto pueden utilizar tanto la terminal como un escritorio remoto para tener un GUI:      https://www.youtube.com/watch?v=IL7Jd9rjgrM&list=PLhfrWIlLOoKNMHhB39bh3XBpoLxV3f0V9&index=8
  
      - Instalación de ROS Noetic en Ubuntu 20.04 (PC)
   Sigan unicamente el paso 4 y 7, este paso aplica tanto para Ubuntu tanto en máquina virtual (vmWare, VirtualBox, etc) como en WSL

      https://github.com/ishkapoor2000/Install_ROS_Noetic_On_WSL#4-installing-ros-on-wsl.

Esto es para la Raspberry Pi en Raspbian Buster de 64 bits

     - Instalación de ROS Noetic para Raspbian Buster
   Sigan unicamente
5 Steps to Install ROS Noetic on Raspberry Pi 4, aunque diga que es para Raspbery 4, funciona para la tarjeta que tienen.

      https://varhowto.com/install-ros-noetic-raspberry-pi-4/#5_Steps_to_Install_ROS_Noetic_on_Raspberry_Pi_4

     - Instalación de Arduino IDE para Raspbian Buster
   Descargar Arduino IDE 1.8.19

        https://downloads.arduino.cc/arduino-1.8.19-linuxaarch64.tar.xz
   Instalación Arduino IDE

        https://docs.arduino.cc/software/ide-v1/tutorials/Linux
     - Instalación de rosserial en Arduino IDE.
        http://wiki.ros.org/rosserial_arduino/Tutorials/Arduino%20IDE%20Setup

Libros para ROS

https://librunam.dgb.unam.mx:8443/F/EA9AH3K7HIGVH6AJL6TYBBYM8RDN9B5QIJEK13AGD18MKGKPC4-16699?func=find-b&local_base=MX001&request=ros+beginners&find_code=WRD&adjacent=N&filter_code_1=WLN&filter_request_1=&filter_code_2=WYR&filter_request_2=&filter_code_3=WYR&filter_request_3=


Ojo es necesario que ambas versiones de ROS sean Noetic, de no ser así no va a funcionar.
