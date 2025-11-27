# Atividade - Mapa de Calor calculando dBm de sinal WiFi
O intuito dessa atividade é coletar dados sobre a potência do sinal WiFi em dBm usando um ESP32 e publicar esses valores em uma dashboard de uma plataforma online, nesse caso o Ubidots.

O projeto tem um ESP32 conectado a um Wifi, medindo o sinal de radiofrequência por meio de uma antena omnidirecional e imprimindo os dados em dBm na porta serial da Arduino IDE. Após isso os dados são publicados para o ubidots por meio de um objeto httpp. 
 
O código comentado se encontra no seguinte arquivo:
Projetos Modulo 04/Wifi Signal dbm/code.cpp ou [clicando aqui](/Projetos%20Modulo%2004/Wifi%20Signal%20dbm/code.cpp)

No Ubidots existem 2 gráficos que apresentam os valores do dBm, em relação a tempo x dBm, que são eles um gráfico de linha e um gráfico de gauge. 

**Abaixo uma imagem de como está:**
![gráficos](/Projetos%20Modulo%2004/Wifi%20Signal%20dbm/assets/graphs.png)

Para simular todo esse processo e mostrar a perda da conexão similar a uma caixa de faraday (entrando no elevador da faculdade) eu gravei essa experiência completa que pode ser acessada no vídeo abaixo:
[Abra o vídeo](https://drive.google.com/file/d/1oVdzSjgjO9u12x5vz67k-BNxaPX4J4UM/view?usp=sharing)