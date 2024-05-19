#define RELE_PIN 3
#define SENSOR_PIN A0 

const int UMIDADE_CRITICA = 600; 
const int NUM_LEITURAS = 10;

bool irrigar = false;

void setup() {
  pinMode(RELE_PIN, OUTPUT);
  pinMode(SENSOR_PIN, INPUT);
  digitalWrite(RELE_PIN, HIGH);
  Serial.begin(9600);
}

int lerUmidadeMedia() {
  long soma = 0;
  for (int i = 0; i < NUM_LEITURAS; i++) {
    soma += analogRead(SENSOR_PIN);
    delay(50);
  }
  return soma / NUM_LEITURAS;
}

void loop() {
  int umidade = lerUmidadeMedia();
  Serial.print("Umidade do solo: ");
  Serial.println(umidade);

  if (umidade > UMIDADE_CRITICA) {
    irrigar = true;
  } else {
    irrigar = false;
  }

  if (irrigar) {
    digitalWrite(RELE_PIN, LOW);
    Serial.println("Regando a planta...");
  } else {
    digitalWrite(RELE_PIN, HIGH);
    Serial.println("Solo com umidade suficiente.");
  }

  delay(5000);
}
