// importa bibliotecas de wifi e envio http
#include <WiFi.h>
#include <HTTPClient.h>

// declara variaveis de conexao
const char* WIFINAME = "Inteli.Iot";
const char* WIFIPASS = "%(Yk(sxGMtvFEs.3";
const char* UBIDOTS_TOKEN = "BBUS-KJUJGk3rfjDcp23ZDiUvv3NqWZtcby";

// declara variaveis de dispositivo e variavel no ubidots
String DEVICE_LABEL = "esp32"; 
String VARIABLE_LABEL = "rssi";

// funcao de setup para garantir conexao wifi
void setup() {
  Serial.begin(115200);

  WiFi.begin(WIFINAME, WIFIPASS);
  Serial.print("Conectando ao WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nConectado!");
  Serial.print("IP: ");
  Serial.println(WiFi.localIP());
}

void loop() {
    // verifica se esta conectado ao wifi
  if (WiFi.status() == WL_CONNECTED) {
    // cria objeto http
    HTTPClient http;
    // obtem valor do rssi
    long rssi = WiFi.RSSI();
    // monta url de requisicao
    String url = "http://industrial.api.ubidots.com/api/v1.6/devices/" + DEVICE_LABEL;
    // inicia conexao http
    http.begin(url);
    // adiciona headers
    http.addHeader("Content-Type", "application/json");
    http.addHeader("X-Auth-Token", UBIDOTS_TOKEN);
    // monta payload
    String payload = "{\"" + VARIABLE_LABEL + "\": " + String(rssi) + "}";
    // envia requisicao POST
    Serial.print("Enviando dados: ");
    Serial.println(payload);

    int httpResponseCode = http.POST(payload);
    // verifica resposta do servidor
    if (httpResponseCode > 0) {
      Serial.print("Resposta do servidor: ");
      Serial.println(httpResponseCode);
    } else {
      Serial.print("Erro no envio: ");
      Serial.println(httpResponseCode);
    }
    
    http.end();
    
  } else {
    Serial.println("WiFi Desconectado! Tentando reconectar...");
    WiFi.reconnect();
  }

  delay(1000);
}