int fhumedad_suelo;
int fluz;
float fhumedad;
float ftemperatura;

const byte pinReleB = 4;
const byte pinReleV = 3;

int medirHumedadSuelo()
{
  fhumedad_suelo = map(analogRead(pinHumedad), 0, 4095, 0, 100); // map(value, fromLow, fromHigh, toLow, toHigh) para mapear los valores (de 4096 a 100, pe.)
  return fhumedad_suelo;
}



float medirHT( String dato ) //Dato puede ser "temperatura" o "humedad"
{
  if(dato == "humedad")
  {
    fhumedad = dht.readHumidity();
    return fhumedad;
  }
  else if(dato == "temperatura")
  {
    ftemperatura = dht.readTemperature();
    return ftemperatura;
  }
}

int medirLuz()
{
  fluz = map(analogRead(pinLDR), 0, 4095, 0, 100); // map(value, fromLow, fromHigh, toLow, toHigh) para mapear los valores (de 4096 a 100, pe)
  return fluz;
}

double medirTemperaturaSuelo()
{
  sensor.requestTemperatures();
  return sensor.getTempCByIndex(0);
}

void activarVentilacion(byte estadoReleV)
{
  Wire.beginTransmission(1);
  Wire.write(pinReleV);
  Wire.write(estadoReleV);
  Wire.endTransmission();
}

void activarBomba(byte estadoReleB)
{
  Wire.beginTransmission(1);
  Wire.write(pinReleB);
  Wire.write(estadoReleB);
  Wire.endTransmission();
}

void enviarPuertoSerie(int dhum_suelo, int dhum_amb, int dtemp_suelo, int dtemp_amb, int dluz)
{

  Serial.print("Humedad del suelo: ");
  Serial.println(dhum_suelo);
  Serial.print("Humedad del ambiente: ");
  Serial.println(dhum_amb);
  Serial.print("Temperatura del suelo: ");
  Serial.println(dtemp_suelo);
  Serial.print("Temperatura del ambiente: ");
  Serial.println(dtemp_amb);
  Serial.print("Luz: ");
  Serial.println(dluz);
  Serial.println("-------------------------------");


}