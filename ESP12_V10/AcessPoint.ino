
void AcessPoint()
{

  
  Serial.print("Mode de operação em: ");
  Serial.println(ModoOper);

  Serial.println();

  const char *ssid = "pAr_";
  const char *ssid2 = wifi_station_get_hostname(); // naõ pode passar de 11 caracteres

 
  strcpy(result, ssid); // copy string one into the result.
  strcat(result, ssid2); //

  Serial.print("Configurando AP: nome: ");
  Serial.print(result);
  Serial.println(" - senha:12345678");

 WiFi.softAP(result, "12345678", 1 , 0);

  IPAddress myIP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(myIP);

   server.begin();

  delay(10);

  WiFi.mode(WIFI_AP);

  Serial.println("AP configurado");
}











void Verifica_cliente()
{

  // Check if a client has connected
  WiFiClient client = server.available();
  if (!client) {
    tempCom.Saida(0);
    return;
  }

  // Wait until the client sends some data
  // Serial.println("new client");
  while (!client.available()) {
    delay(1);

    if (tempCom.Saida(1))
    {
      //    Serial.println("Tempo excedeu");
      client.flush();

      String s = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n<!DOCTYPE HTML>\r\n<html>\r\nNAO COMUNICOU !!! ";
      s += "</html>\n";

      // Send the response to the client
      client.print(s);
      delay(1);
      tempCom.Saida(0);
      return;

    }
  }

  // Read the first line of the request
  String req = client.readStringUntil('\r');
  Serial.println(req);
  client.flush();



  int retorno = Grava_variaveis(req);





  // tem que tentar uma conexao aqui











  String s = "";
  s =  "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n";







  if (!retorno) {

    s += "erro nos dados ";

    client.print(s);
    return;
  }
  else
  {


    // configura_Server();

    s += "configurado ";

    client.print(s);
    Serial.print(s);


    Serial.print("  -  pre 3s");

    client.stop();
    delay(1000);

    ESP.restart();


  }


}





