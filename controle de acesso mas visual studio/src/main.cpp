#include <Arduino.h>
#include <SPI.h>
#include <MFRC522.h>

#define SS_PIN 10
#define RST_PIN 9

String IDtag = ""; //Variável que armazenará o ID da Tag
bool Permitido = false; //Variável que verifica a permissão 
//Vetor responsável por armazenar os ID's das Tag's cadastradas
String TagsCadastradas[] = {"36925783", 
                            "74a015f5",
                            "ID_3"};
MFRC522 LeitorRFID(SS_PIN, RST_PIN);

char promSerail;
int limitador =0;

void Leitura();void acessoLiberado();void acessoNegado();void efeitoPermitido(); void infomr1();void infomr2();

void setup(){


Serial.begin(9600);
SPI.begin();                   
LeitorRFID.PCD_Init(); 

}


int teste1;
int teste2;
void loop(){
    Leitura();
  
 
}







void Leitura(){
if (Serial.available())
{
  

        IDtag = ""; //Inicialmente IDtag deve estar vazia.
        
        // Verifica se existe uma Tag presente
        if ( !LeitorRFID.PICC_IsNewCardPresent() || !LeitorRFID.PICC_ReadCardSerial() ) {
            delay(50);
            return;
        }
        
        // Pega o ID da Tag através da função LeitorRFID.uid e Armazena o ID na variável IDtag        
        for (byte i = 0; i < LeitorRFID.uid.size; i++) {        
            IDtag.concat(String(LeitorRFID.uid.uidByte[i], HEX));
        }        
        
        //Compara o valor do ID lido com os IDs armazenados no vetor TagsCadastradas[]
        for (int i = 0; i < (sizeof(TagsCadastradas)/sizeof(String)); i++) {
          if(  IDtag.equalsIgnoreCase(TagsCadastradas[i])  ){
              Permitido = true; //Variável Permitido assume valor verdadeiro caso o ID Lido esteja cadastrado
          }
        }       
        if(Permitido == true) acessoLiberado(); //Se a variável Permitido for verdadeira será chamada a função acessoLiberado()        
        else acessoNegado(); //Se não será chamada a função acessoNegado()
        delay(10); //aguarda 2 segundos para efetuar uma nova 
}
}

void acessoLiberado(){


 
      if ( IDtag.equalsIgnoreCase(TagsCadastradas[0])) //UID 1 - Chaveiro
  {
    infomr1();
  }
   if (IDtag.equalsIgnoreCase(TagsCadastradas[1])) //UID 1 - Chaveiro
  {
    infomr2();
  }

  
//mensageminicial();
  
    Permitido = false;  //Seta a variável Permitido como false novamente
}
void acessoNegado(){

if(Serial.available()){


promSerail = Serial.read();
if(promSerail == 'g'){
Serial.println("Tag NAO Cadastrada: ");
} //Exibe a mensagem "Tag NAO Cadastrada" e o ID da tag cadastrada
 // efeitoNegado(); //Chama a função efeitoNegado()



 if (promSerail == 'q')
  {
  
      Serial.println("ERRO1");
    
  }
if(promSerail == 'p')
{
    
      Serial.println("ERRO2");
    
    }
    
 if (promSerail == 'w')
  {
    
      Serial.println("ERRO3");
    
  
  }


if( promSerail == 'r'){
   
      Serial.println(IDtag);

 
  }
  if( promSerail == 'e'){
   
      Serial.println("ERRO4");

 
  }
}

}

void efeitoPermitido(){  
  
  
}
void efeitoNegado(){

}



void infomr1(){

  
  if(Serial.available())
{

promSerail = Serial.read();


 if (promSerail == 'q')
  {
  
      Serial.println("gabriel");
    
  }
if(promSerail == 'p')
{
    
      Serial.println("Vinicius de Melo Santana");
    
    }
    
 if (promSerail == 'w')
  {
    
      Serial.println("2");
    
  
  }

    
  
if( promSerail == 'e'){
   
      Serial.println("8210");
      
    
 
 
  }

if( promSerail == 'r'){
   
      Serial.println(IDtag);
      
    
 
 
  }

  if(promSerail == 'g'){
Serial.println("Tag Cadastrada: "); //Exibe a mensagem "Tag NAO Cadastrada" e o ID da tag cadastrada
 // efeitoNegado(); //Chama a função efeitoNegado()
}
}
}
void infomr2()
{

  if(Serial.available())
{

promSerail = Serial.read();


 if (promSerail == 'q')
  {
  
      Serial.println("gabriel");
    
  }
if(promSerail == 'p')
{
    
      Serial.println("gerusa carvalho de melo santana");
    
    }
    
 if (promSerail == 'w')
  {
    
      Serial.println("2");
    
  
  }

    
  
if( promSerail == 'e'){
   
      Serial.println("5100");
      
    
 
 
  }

if( promSerail == 'r'){
   
      Serial.println(IDtag);
      
    
 
 
  }

  if(promSerail == 'g'){
Serial.println("Tag Cadastrada: "); //Exibe a mensagem "Tag NAO Cadastrada" e o ID da tag cadastrada
 // efeitoNegado(); //Chama a função efeitoNegado()
}
}
}