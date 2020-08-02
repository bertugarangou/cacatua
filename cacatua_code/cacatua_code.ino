/*********************************************************************/
//CACATUA by Albert Garangou Culebras (c)
//Data inici: 02d/08m/2020a
//Versió Alpha
//
//Any distribution is prohibided until been given explicit right.
/*********************************************************************/
#include <Stepper.h>

/*****************************CACATUA(c)******************************/
char autor[] = "";
char titol[] = "";
/*********************************************************************/

//posicions
#define MAX_MOV 245 //fisic 251, maxim 250, assegurar (nomes tests) 245

//notes
#define Do 100  
#define DoSustingut 125  
#define DoBemoll 75
#define Re 150  
#define ReSustingut 175  
#define ReBemoll 125
#define Mi 200  
#define MiSustingut 225  
#define MiBemoll 175
#define Fa 250  
#define FaSustingut 275  
#define FaBemoll 225
#define Sol 300 
#define SolSustingut 325 
#define SolBemoll 275
#define La 350  
#define LaSustingut 375  
#define LaBemoll 325
#define Si 400  
#define SiSustingut 425  
#define SiBemoll 375

int pos_actu = 0; //0 a 245
int dir = 1;  //1 dreta -1 esquerra. El motor ha de quedar a la dreta: |(0)------------ll---(245)<|M|

//motor
Stepper motor(48, 9, 10, 11, 12);

/**********************************************/
//PLAY: fa sonar una nota durant un temps (s o tipus de nota?)
void play(int nota, long duracio){
  
  motor.setSpeed(nota);
  unsigned long time0 = millis();
  unsigned long time1 = millis();
  while(time0 - time1 >= long(abs(duracio*1000))){

    if(pos_actu = 245){
      dir = -1;
    }else if(pos_actu == 0){
      dir = 1;      
    }

    motor.step(dir);
    pos_actu += dir;
    
    time0 = millis();
  }
  
  //reset speed
  motor.setSpeed(0);
  
}

//FINITO: acaba el programa
void finito(){
  while(true){}
}

void ressetejar(){
  motor.setSpeed(200);
  motor.step(-260); //assegurar
  delay(200);
  motor.step(5);  //alliberar i recol.locar
  delay(200);
  motor.setSpeed(650);
  motor.step(MAX_MOV);  //test maxim: si pica alguna cosa passa
  delay(100);
  motor.step(-(MAX_MOV)); //retornar: si pica alguna cosa passa
  delay(400);
  motor.setSpeed(0); //netejar speed
}
/**********************************************/
void setup() {
  //reset
  ressetejar();
}
/**********************************************/


void loop() {
  pos_actu = 0;
  play(1, Do);

  finito();
}
