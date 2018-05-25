// esta funcao é utilizada no processo produtivo para fazer o primeiro upload da nuvem após gravação via uart

void OTAhttp1()
{
    EEPROM.write(130, 1);
    EEPROM.commit();
    
  Serial.setDebugOutput(true);
  Serial.println();

  WiFi.begin("Crescera automacao", "casadaautomacao");
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
  }
  Serial.println("Connected, updating");
  delay(1000);

  //t_httpUpdate_return ret = ESPhttpUpdate.update("https://raw.githubusercontent.com/Zyxmn/esp8266_BlinkyBin/master/Blinky.cpp.bin", "", "21 99 13 84 63 72 17 13 B9 ED 0E 8F 00 A5 9B 73 0D D0 56 58");
t_httpUpdate_return ret = ESPhttpUpdate.update("http://automacaoparaleigos.ddns.net:3389/firmware.bin");



}




void OTAhttp2()
{

 const char* ssid2 = SSIDcasa.c_str();  // foobar.c_str();
  const char* password2 = SENHAcasa.c_str();


  EEPROM.write(131, 255);
    EEPROM.commit();

  Serial.setDebugOutput(true);
  Serial.println();

  WiFi.begin(ssid2, password2);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
  }
  Serial.println("Connected, updating");
  delay(1000);

// t_httpUpdate_return ret = ESPhttpUpdate.update("https://raw.githubusercontent.com/casaautomacao/pAr/master/firmware.bin", "", "CC AA 48 48 66 46 0E 91 53 2C 9C 7C 23 2A B1 74 4D 29 9D 33");
t_httpUpdate_return ret = ESPhttpUpdate.update("http://automacaoparaleigos.ddns.net:3389/firmware.bin");

// t_httpUpdate_return ret = ESPhttpUpdate.update("https://raw.githubusercontent.com/casaautomacao/pAr/master/Blink.bin", "", "CC AA 48 48 66 46 0E 91 53 2C 9C 7C 23 2A B1 74 4D 29 9D 33");

//t_httpUpdate_return ret = ESPhttpUpdate.update("https://anyfile.255bits.com/wix/download?id=32627f86c543fe6be0328e97c539eeb9", "", "37 B7 DF 18 5C BA 68 EA 1A CF F0 63 2E 40 47 A0 F5 B6 84 1B");



  
}

