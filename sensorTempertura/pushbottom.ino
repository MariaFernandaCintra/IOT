void testeBotao(int pinoBotao){
  Serial.print(F("Estado Botao: "));
  Serial.println(digitalRead(pinoBotao));
  delay(500);
}