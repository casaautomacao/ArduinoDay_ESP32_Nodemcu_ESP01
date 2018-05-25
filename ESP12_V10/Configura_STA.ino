String configuraSTA(String local)
{

  int retorno = Grava_variaveis(local);  // analisar dados antes de gravar
  Serial.print("retorno- ");
  Serial.println(retorno);

  String s = "";
  s =  "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n";

  if (!retorno)
  {
    s += "erro nos dados";
  }
  else
  {
    s += "configurado ";
    Serial.print(s);
    Serial.print("  -  pre 3s");

  }

  return s;
}

