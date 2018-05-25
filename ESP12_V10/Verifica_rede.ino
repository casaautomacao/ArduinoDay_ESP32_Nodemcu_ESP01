
int detecta_SSID() {


  // WiFi.scanNetworks will return the number of networks found
  int n = WiFi.scanNetworks();
  Serial.println("scan done");
  if (n == 0)
    Serial.println("no networks found");
  else
  {
  //  Serial.print(n);
   // Serial.println(" networks found");
    for (int i = 0; i < n; ++i)
    {
    //  Serial.print(SSIDcasa);
    //  Serial.print(WiFi.SSID(i));
   //   Serial.println();

      if (WiFi.SSID(i) ==  SSIDcasa )
      {
        Serial.println("SSID OK");
        return 1;
      }

    }
  }
  Serial.println("Nao achou SSID");

  return 0;

}
