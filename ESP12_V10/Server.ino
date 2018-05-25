void configura_Server()
{

  server = WiFiServer(IPorta);

  const char* ssid = SSIDcasa.c_str();  // foobar.c_str();
  const char* password = SENHAcasa.c_str();

  // Connect to WiFi network
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  Serial.println(password);

  delay(10);

  WiFi.begin(ssid, password);
  int tenta = 0;
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
   // Serial.print(WiFi.status());
    tenta++;
    if (tenta == 40) return;
  }
  Serial.println("");
  Serial.println("WiFi connected");

  ip2 = WiFi.subnetMask();
  ip1 = WiFi.gatewayIP();

  IPAddress iplocal(ip1[0], ip1[1], ip1[2], BIPfixo);

  ip = iplocal;
  Serial.println(ip);

 OTAfirmware();


  WiFi.config(ip, ip1, ip2);




  // Start the server
  server.begin();
  Serial.println("Server started");

  // Print the IP address
  Serial.println(WiFi.localIP());



   

}

