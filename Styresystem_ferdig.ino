int status_skuff1 = 0;
int status_skuff2 = 0;
int status_skuff3 = 0;
int status_skuff4 = 0;
int skuff_bryter1 = 1;
int skuff_bryter2 = 1;
int skuff_bryter3 = 1;
int skuff_bryter4 = 1;
long tid = 0;
long tid2 = 0;
long tid3 = 0;
long tid4 = 0;
long tid_naa = 0;
long intervall = 0;

//Pin-navn
int magnetpin1 = 44;
int magnetpin2 = 45;
int magnetpin3 = 46;
int magnetpin4 = 47;
int ledpin1 = 22;
int ledpin2 = 23;
int ledpin3 = 24;
int ledpin4 = 25;
int bryter1 = 26;
int bryter2 = 27;
int bryter3 = 28;
int bryter4 = 29;
int reset1 = 30;
int reset2 = 31;
int reset3 = 32;
int reset4 = 33;
int status1 = 34;
int status2 = 35;
int status3 = 36;
int status4 = 37;
int premie = 38;

void setup() {
  //2-13 PWM pins
  //22 - 53 Digital pins
pinMode(magnetpin1, OUTPUT); //Elektromagnet skuff 1
pinMode(magnetpin2, OUTPUT); //Elektromagnet skuff 2
pinMode(magnetpin3, OUTPUT); //Elektromagnet skuff 3
pinMode(magnetpin4, OUTPUT); //Elektromagnet skuff 4

pinMode(ledpin1, OUTPUT); //LED skuff 1
pinMode(ledpin2, OUTPUT); //LED skuff 2
pinMode(ledpin3, OUTPUT); //LED skuff 3
pinMode(ledpin4, OUTPUT); //LED skuff 4

pinMode(bryter1, INPUT); //Bryter skuff 1
pinMode(bryter2, INPUT); //Bryter skuff 2
pinMode(bryter3, INPUT); //Bryter skuff 3
pinMode(bryter4, INPUT); //Bryter skuff 4

pinMode(reset1, OUTPUT); //Reset skuff 1
pinMode(reset2, OUTPUT); //Reset skuff 2
pinMode(reset3, OUTPUT); //Reset skuff 3
pinMode(reset4, OUTPUT); //Reset skuff 4

pinMode(status1, INPUT); //status skuff 1
pinMode(status2, INPUT); //status skuff 2
pinMode(status3, INPUT); //status skuff 3
pinMode(status4, INPUT); //status skuff 4
}

void loop() {
//********************************************************
//******************* INITIALISERING *********************
//********************************************************
digitalWrite(ledpin1, HIGH);     //LED skuff 1 PÅ
digitalWrite(ledpin2, LOW);      //LED skuff 2 AV
digitalWrite(ledpin3, LOW);      //LED skuff 2 AV
digitalWrite(ledpin4, LOW);      //LED skuff 2 AV
digitalWrite(magnetpin1, LOW);   //Magnet 1 AV
digitalWrite(magnetpin2, HIGH);  //Magnet 2 PÅ
digitalWrite(magnetpin3, HIGH);  //Manget 3 PÅ
digitalWrite(magnetpin4, HIGH);  //Magnet 4 PÅ
digitalWrite(reset1, LOW);       //Alle reset satt AV
digitalWrite(reset2, LOW);
digitalWrite(reset3, LOW);
digitalWrite(reset4, LOW);

//*******************************************************
//******************* HOVEDPROGRAM **********************
//*******************************************************


//******************** Skuff 1 **************************


skuff_bryter1 = digitalRead(bryter1);   //Har skuff 1 blitt tatt ut?
  if (skuff_bryter1 == 0)
  {
    while(skuff_bryter1 == 0)            // Venter på at skuff 1 skal bli satt inn igjen
    {
      skuff_bryter1 = digitalRead(bryter1); 
      status_skuff1 = digitalRead(status1);           //Leser om oppgaven er løst eller ikke
    }
    status_skuff1 = digitalRead(status1);
      if(status_skuff1 == 1)            //Hvis løst oppgave 1
      {
       skuff1_lost(ledpin1, ledpin2, magnetpin1, magnetpin2);


//******************** Skuff 2 **************************

        
        tid2 = millis();
        while(skuff_bryter2 == 1)       // Venter på at skuff 2 skal bli åpnet
        {  
          skuff_bryter2 = digitalRead(bryter2);     
          tid_naa = millis();
          intervall = tid_naa - tid2;   //Måler hvor lenge skuffen forblir uåpnet
          if(intervall > 10000)         //2min = 120000   10sek = 10000
            {
              skuff2_ulost(reset1, reset2, ledpin2);      //Hvis skuffen er uåpnet i X antall sekund, reset systemet.
              break;
            }
          
        }
        while(skuff_bryter2 == 0)     // Venter på at skuff 2 skal bli satt inn igjen
        { 
          skuff_bryter2 = digitalRead(bryter2);
          status_skuff2 = digitalRead(status2);         //Leser om oppgaven er løst eller ikke
        }
        status_skuff2 = digitalRead(status2);
          if(status_skuff2 == 1)
          {
            skuff2_lost(ledpin2, ledpin3, magnetpin2, magnetpin3);
          
    

//******************** Skuff 3 **************************

              tid3 = millis();
              while(skuff_bryter3 == 1)   // Venter på at skuff 3 skal bli åpnet
              {
                skuff_bryter3 = digitalRead(bryter3);
                tid_naa = millis();
                intervall = tid_naa - tid3;         //Måler hvor lenge skuffen forblir uåpnet
                if(intervall > 10000)               //Hvis skuffen er uåpnet i X antall sekund, reset systemet.
                  {
                    skuff3_ulost(reset1, reset2, reset3, ledpin3);
                    break;
                  }
              }
              while(skuff_bryter3 == 0)  //Venter på at skuff 3 skal bli satt inn igjen
              {
                skuff_bryter3 = digitalRead(bryter3);
                status_skuff3 = digitalRead(status3);     //Leser om oppgaven er løst eller ikke
              }
              status_skuff3 = digitalRead(status3);       
                if(status_skuff3 == 1)
                {
                 skuff3_lost(ledpin3, ledpin4, magnetpin3, magnetpin4); 
                
    

//******************** Skuff 4 **************************

                  tid4 = millis();
                  while(skuff_bryter4 ==1)    // Venter på at skuff 4 skal bli åpnet
                  {
                    skuff_bryter4 = digitalRead(bryter4);
                    tid_naa = millis();
                    intervall = tid_naa - tid4;      //Måler hvor lenge skuffen forblir uåpnet
                    if(intervall > 10000)           //Hvis skuffen er uåpnet i X antall sekund, reset systemet.
                        {
                          skuff4_ulost(reset1, reset2, reset3, reset4, ledpin4);
                          break;
                        }
                  }
                  while(skuff_bryter4 == 0)   // Venter på at skuff 4 skal bli satt inn igjen
                  {  
                    skuff_bryter4 = digitalRead(bryter4);
                    status_skuff4 = digitalRead(status4);       /Leser om oppgaven er løst eller ikke
                  }
                  status_skuff4 = digitalRead(status4);
                    if(status_skuff4 == 1)
                    {
                      skuff4_lost(ledpin4, magnetpin4);
                      premie_funksjon(ledpin1, ledpin2, ledpin3, ledpin4);
                      reset_system(reset1, reset2, reset3, reset4);
                    


//********************* else'ene ***************************

                    }
                    else              // Hvis uløst oppgave 4
                    {
                      skuff4_ulost(reset1, reset2, reset3, reset4, ledpin4);
                    }
                    
                    
                
                }
                else                   // Hvis uløst oppgave 3
                {
                  skuff3_ulost(reset1, reset2, reset3, ledpin3);
                }
                
          
          }
          else                          //Hvis uløst oppgave 2
          {
           skuff2_ulost(reset1, reset2, ledpin2);  
          }
          
       
      }
      else                              //Hvis uløst oppgave 1
      {
       skuff1_ulost(reset1, ledpin1);
      }
    
  }

}

//*******************************************************
//************* FUNKSJON - LØST OPPGAVE 1 ***************
//*******************************************************
void skuff1_lost(int led1, int led2, int magnet1, int magnet2){
  digitalWrite(led1, LOW);
  digitalWrite(led2, HIGH);
  digitalWrite(magnet1, HIGH);
  digitalWrite(magnet2, LOW);
  return;
}

//*******************************************************
//************* FUNKSJON - ULØST OPPGAVE 1 **************
//*******************************************************
void skuff1_ulost(int reset_1, int led1){
  digitalWrite(reset_1, HIGH);
  digitalWrite(led1, LOW);
  delay(250);
  return;
}

//*******************************************************
//************* FUNKSJON - LØST OPPGAVE 2 ***************
//*******************************************************
void skuff2_lost(int led2, int led3, int magnet2, int magnet3){
  digitalWrite(led2, LOW);
  digitalWrite(led3, HIGH);
  digitalWrite(magnet2, HIGH);
  digitalWrite(magnet3, LOW);
  return;
}

//*******************************************************
//************* FUNKSJON - ULØST OPPGAVE 2 **************
//*******************************************************
void skuff2_ulost(int reset_1, int reset_2, int led2){
  digitalWrite(reset_1, HIGH);
  digitalWrite(reset_2, HIGH);
  digitalWrite(led2, LOW);
  delay(250);
  return;
}

//*******************************************************
//************* FUNKSJON - LØST OPPGAVE 3 ***************
//*******************************************************
void skuff3_lost(int led3, int led4, int magnet3, int magnet4){
  digitalWrite(led3, LOW);
  digitalWrite(led4, HIGH);
  digitalWrite(magnet3, HIGH);
  digitalWrite(magnet4, LOW);
  return;
}

//*******************************************************
//************* FUNKSJON - ULØST OPPGAVE 3 **************
//*******************************************************
void skuff3_ulost(int reset_1, int reset_2, int reset_3, int led3){
  digitalWrite(reset_1, HIGH);
  digitalWrite(reset_2, HIGH);
  digitalWrite(reset_3, HIGH);
  digitalWrite(led3, LOW);
  delay(250);
  return;
}

//*******************************************************
//************* FUNKSJON - LØST OPPGAVE 4 ***************
//*******************************************************
void skuff4_lost(int led4, int magnet4){
  digitalWrite(led4, LOW);
  digitalWrite(magnet4, HIGH);
  return;
}

//*******************************************************
//************* FUNKSJON - ULØST OPPGAVE 4 **************
//*******************************************************
void skuff4_ulost(int reset_1, int reset_2, int reset_3, int reset_4, int led4){
  digitalWrite(reset_1, HIGH);
  digitalWrite(reset_2, HIGH);
  digitalWrite(reset_3, HIGH);
  digitalWrite(reset_4, HIGH);
  digitalWrite(led4, LOW);
  delay(250);
  return;
}

//*******************************************************
//****************** FUNKSJON - PREMIE ******************
//*******************************************************
//En LED-dans som i denne demo'en representerer fullført oppgaver.

void premie_funksjon(int led1 , int led2, int led3, int led4){
  digitalWrite(led1, HIGH);
  digitalWrite(led2, HIGH);
  digitalWrite(led3, HIGH);
  digitalWrite(led4, HIGH);
  delay(250);
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
  delay(250);
  digitalWrite(led1, HIGH);
  digitalWrite(led2, HIGH);
  digitalWrite(led3, HIGH);
  digitalWrite(led4, HIGH);
  delay(250);
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
  delay(250);
  digitalWrite(led1, HIGH);
  digitalWrite(led2, HIGH);
  digitalWrite(led3, HIGH);
  digitalWrite(led4, HIGH);
  delay(250);
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
  delay(250);
  digitalWrite(led1, HIGH);
  delay(250);
  digitalWrite(led1, LOW);
  digitalWrite(led2, HIGH);
  delay(250);
  digitalWrite(led2, LOW);
  digitalWrite(led3, HIGH);
  delay(250);
  digitalWrite(led3, LOW);
  digitalWrite(led4, HIGH);
  delay(250);
  digitalWrite(led4, LOW);
  digitalWrite(led1, HIGH);
  delay(250);
  digitalWrite(led1, LOW);
  digitalWrite(led2, HIGH);
  delay(250);
  digitalWrite(led2, LOW);
  digitalWrite(led3, HIGH);
  delay(250);
  digitalWrite(led3, LOW);
  digitalWrite(led4, HIGH);
  delay(250);
  digitalWrite(led4, LOW);
  digitalWrite(led1, HIGH);
  delay(250);
  digitalWrite(led1, LOW);
  digitalWrite(led2, HIGH);
  delay(250);
  digitalWrite(led2, LOW);
  digitalWrite(led3, HIGH);
  delay(250);
  digitalWrite(led3, LOW);
  digitalWrite(led4, HIGH);
  delay(250);
  return;
}

//*******************************************************
//************** FUNKSJON - RESET SYSTEM ****************
//*******************************************************
void reset_system(int reset_1 , int reset_2, int reset_3, int reset_4){
  digitalWrite(reset_1, HIGH);
  digitalWrite(reset_2, HIGH);
  digitalWrite(reset_3, HIGH);
  digitalWrite(reset_4, HIGH);
  delay(250);
  return;
}
