void setup() {
  Serial.begin(9600);
}

void loop() {
  float valorAleatorio = random(0, 100);
  Serial.print("Valor aleatório: ");
  Serial.println(valorAleatorio);

  delay(3000);
}