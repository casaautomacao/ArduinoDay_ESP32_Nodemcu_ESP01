void Le_variaveis()
{
  Serial.println(" ------ Le variáveis ------- ");
  // tratar dados vindos para configura rede wifi
  SSIDcasa = "", SENHAcasa = "", IPfixo = "", Porta = "";
  int tam;

  //SSID
  tam = EEPROM.read(1);
  for (int i = 0; i < tam; i++)
  {
    SSIDcasa += char(EEPROM.read(2 + i));
  }
  Serial.println(" ------leu SSIDcasa ------- ");
  Serial.println(SSIDcasa);
  Serial.println(tam);

  //Senha
  tam = EEPROM.read(31);
  for (int i = 0; i < tam; i++)
  {
    SENHAcasa += char(EEPROM.read(32 + i));
  }

  //IPfixo
  tam = EEPROM.read(61);
  BIPfixo = 0;
  for (int i = 0; i < tam; i++)
  {
    char trata = char(EEPROM.read(62 + i));
    IPfixo += trata; // byte BIPfixo = 0;  int IPorta = 0;
    BIPfixo = BIPfixo + ( trata - 48 ) * pow(10, tam - 1 - i);
  }

  //Porta
  tam = EEPROM.read(91);
  IPorta = 0;
  for (int i = 0; i < tam; i++)
  {
    char trata = char(EEPROM.read(92 + i));
    Porta += trata;
    IPorta = IPorta + ( trata - 48 ) * pow(10, tam - 1 - i);
  }


  if (IPorta == 0) IPorta = 80;

}


int Grava_variaveis(String req)
{
  int tam;
  Serial.println(" ------ Grava_variaveis ------- ");
  // tratar dados vindos para configura rede wifi
  SSIDcasa = "", SENHAcasa = "", IPfixo = "", Porta = "";

  int i = 5;
  int inicio = i;
  // SSID, SEnha, final do IP, porta
  while (req[i] != ',')
  {
    SSIDcasa += req[i];
    EEPROM.write(2 + i - inicio, req[i]);
    i++;
  }

  i++;
  inicio = i;
  while (req[i] != ',')
  {
    SENHAcasa += req[i];
    EEPROM.write(32 + i - inicio, req[i]);
    i++;
  }
  i++;
  inicio = i;
  while (req[i] != ',')
  {
    IPfixo += req[i];
    EEPROM.write(62 + i - inicio, req[i]);


    
    i++;
  }
  i++;
  inicio = i;
  while (req[i] != '.')
  {
    Porta += req[i];
    EEPROM.write(92 + i - inicio, req[i]);


    
    i++;
  }


  int tamSSID = SSIDcasa.length();
  int tamSenha = SENHAcasa.length();
  int tamIP = IPfixo.length();


  EEPROM.write(0, 1);

  EEPROM.write(1, tamSSID);
  EEPROM.write(31, tamSenha);
  EEPROM.write(61, tamIP);
  EEPROM.write(91, Porta.length());

  Serial.println(SSIDcasa);
  Serial.println(SENHAcasa);
  Serial.println(IPfixo);
  Serial.println(Porta);



  if (!tamSSID or !tamSenha or !tamIP) return 0;

  EEPROM.commit();
  EEPROM.end();
  delay(10);
  ModoOper  = EEPROM.read(0);   // primeiro endereço disponível é 0x7b000 se eeprom for 512k que a biblioteca gerencia, a principio
  return 1;
}

