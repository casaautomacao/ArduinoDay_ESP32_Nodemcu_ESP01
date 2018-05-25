void OTAfirmware()
{

// Serial.println("OTA 1");
  ArduinoOTA.onStart([]()  {
    Serial.println("Start");
  });
//Serial.println("OTA 2");

  ArduinoOTA.onEnd([]() {
    Serial.println("\nEnd");
  });

//Serial.println("OTA 3");

  
  ArduinoOTA.onProgress([](unsigned int progress, unsigned int total) {
    Serial.printf("Progress: %u%%\r", (progress / (total / 100)));
  });

//Serial.println("OTA 4");
  
  ArduinoOTA.onError([](ota_error_t error) {
    Serial.printf("Error[%u]: ", error);
    if (error == OTA_AUTH_ERROR) Serial.println("Auth Failed");
    else if (error == OTA_BEGIN_ERROR) Serial.println("Begin Failed");
    else if (error == OTA_CONNECT_ERROR) Serial.println("Connect Failed");
    else if (error == OTA_RECEIVE_ERROR) Serial.println("Receive Failed");
    else if (error == OTA_END_ERROR) Serial.println("End Failed");
  });
//Serial.println("OTA 5");
  
  ArduinoOTA.begin();
  Serial.println("OTA 6");

  
}

