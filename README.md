Jeniffer Nathalia Borges de Paiva - 10370000

**Link do vídeo de demonstração no YOUTUBE:** [OBJETOS INTELIGENTES CONECTADOS ](https://www.youtube.com/watch?v=WnmMYvHiHOI)

**Descrição do Funcionamento e Uso do Protótipo de Irrigação e Monitoração de solo Inteligente**
Resumo do Funcionamento
O protótipo de irrigação inteligente é desenvolvido com sensores e atuadores conectados a uma placa Arduino para monitorar a umidade do solo (trazendo os resultados da umidade do solo e avisando se esta ou não regando) e fornecer água às plantas conforme necessário. Com base nos dados de umidade do solo, o Arduino determina se a irrigação é necessária. Um algoritmo de controle ajusta o limite de umidade desejado, considerando as necessidades específicas da planta e fatores ambientais. Se a umidade do solo estiver abaixo do limite definido, o sistema prossegue para a etapa de irrigação.

Funcionamento Detalhado
Leitura da Umidade do Solo:

O sensor de umidade do solo capacitivo é posicionado próximo às raízes das plantas.
Em intervalos de tempo predefinidos, o Arduino aciona o sensor para realizar uma leitura da umidade do solo.
O sensor utiliza a variação da capacitância entre suas sondas para determinar o nível de umidade do solo.
Os valores de umidade são convertidos em dados digitais pelo Arduino para processamento.
Irrigação:

O Arduino aciona o módulo relé, que controla a operação da bomba peristáltica.
A bomba peristáltica é ativada para bombear água da fonte para a mangueira de irrigação.
A água é liberada na base das plantas através da mangueira, fornecendo a quantidade adequada de água para restaurar o nível de umidade do solo.
Comunicação MQTT:

**Documentação das interfaces, protocolos e módulos de comunicação:**

O projeto utiliza um Arduino UNO com comunicação via cabo USB para enviar os dados para o computador (avisando a umidade do solo e se o solo esta com umidade suficiente ou se esta insuficiente, assim, regando a planta).
O computador executa um script em Python que recebe os dados pela porta serial e publica os dados para o broker MQTT.
Configuração do Broker MQTT:

É utilizado o Mosquitto como broker MQTT, configurado para escutar na porta padrão 1883 em um servidor local.
Script Python para Integração:

Leitura de Dados Serial: O script Python utiliza a biblioteca pySerial para estabelecer comunicação com o Arduino através da porta serial do computador, configurada com uma taxa de baud de 9600.
Publicação no Broker MQTT: Utilizando a biblioteca paho-mqtt, o script Python publica os dados recebidos do Arduino em tópicos específicos do broker MQTT.
Fluxo de Comunicação:

Leitura e Processamento de Dados: O script Python continuamente lê os dados enviados pelo Arduino via porta serial. Os dados são convertidos de formato binário para texto legível.
Envio para o Broker MQTT: Após a conversão, os dados são formatados e publicados nos tópicos MQTT apropriados utilizando a função publish da biblioteca paho-mqtt.


**Descrição do hardware utilizado (plataformas de desenvolvimento, sensores, atuadores)**
01 Arduino UNO \
01 Sensor de umidade do solo \
01 Módulo relé \
01 Bomba d'água \
01 Fonte 5V para conectar na bomba d'água \
01 USB A-B \
01 Mangueira utilizada na bomba d'água 


