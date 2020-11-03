//  Tradutor para codigo morse
/*  Regras de codigo morse:
                              1 PONTO (neste caso) equivale a 200 milissegundos com o led ligado
                              1 TRACO equivale a 3 PONTOS(600) com o led ligado
                              1 ESPACO entre palavras equivale a 7 PONTOS(1400) com o led desligado
                              espera entre tracos e/ou pontos = 1 PONTO(200) com o led desligado
                              espera entre duas letras = 1 TRACO(600) com o led desligado
                              
                              */

const int dotDelay = 200;  //  tempo de duracao de um ponto em codigo morse
const int ledpin = 7; //  conecte uma led no pino 7
const char *letters[] = 
{
  ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", //  letras em codigo morse de: a-i   ([0]-[8])
  ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.",  //  j-r ([9]-[17])
  "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."  //  s-z ([18]-[25]
};

const char *numbers[] = 
{
   "-----", ".----", "..---", "...--", "....-", //  numeros em codigo morse de: 0-4 ([0]-[4])
   ".....", "-....", "--...", "---..", "----."  //  5-9 ([5]-[9])
};



void setup()
{
  pinMode(ledpin, OUTPUT);
  Serial.begin(9600);
}



void loop()
{
  char msg; //  mensagem digitada para ser traduzida
  if(Serial.available() > 0) 
  {
    msg = Serial.read();
    if(msg >= 'a' && msg <= 'z')
    {
      flashSequence(letters[msg - 'a']);
    }
    else if(msg >= 'A' && msg <= 'Z')
    {
      flashSequence(letters[msg - 'A']);
    }
    else if(msg >= '0' && msg <= '9');
    {
      flashSequence(letters[msg - '0']);
    }
    else if(msg == ' ')
    {
      delay(dotDelay * 7);  //  espaco entre palavras
    }
  }
}



void flashSequence(char letter)
{
 int i = 0;
 while(letter[i] != '/0')
 {
  flashDotOrDash(letter[i]);
  delay(dotDelay);    //  espera entre flashes
  i++; 
 }
 delay(dotDelay * 3); //  espera entre letras
}



void flashDotOrDash(char dotOrDash)
{
  pinMode(ledpin, HIGH);
  if(dotOrDash == '.')
  {
    delay(dotDelay) //  ponto
  }
  else if(dotOrDash == '-')
  {
    delay(dotDelay * 3);  //  traço
  }
  pinMode(ledpin, LOW);
}
