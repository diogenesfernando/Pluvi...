#include <EEPROM.h>

#include <Wire.h>

//#include <EEPROM.h>


#include <LiquidCrystal_I2C.h>

int sinal = 13; // Declara o pino digital 13 para receber sinal
int count = 0; // Contador de gotas
double medida = 0; //Medida em ml



int addr = 0; //Endereço da EEPROM


/*// =============================================================================================================
// --- Mapeamento de Hardware ---
#define     botao1      10     //botão1
#define     botao2      11     //botão2*/



// Cria um objeto LCD e atribui os pinos
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);// Set the LCD I2C address

 
void setup() {
 
  pinMode (sinal, INPUT); // Define o pino 13 como entrada
  lcd.begin(16, 2); // Define o display com 16 colunas e 2 linhas

          lcd.clear();  // Limpa o display do LCD    
          lcd.print("0 ml");  // Imprime a string no display do LCD
          //count = EEPROM.read(addr);   
          
}

void loop() {
 
 if(digitalRead(sinal)){
          count = count + 1;
          medida = count / 22.0;
          
          // Exibindo valor da leitura do pino digital 13 no display LCD
          lcd.clear();  // Limpa o display do LCD    
          lcd.setCursor(0, 0);
          lcd.print(count);
          lcd.print(" gota(s)");  // Imprime a string no display do LCD   
          lcd.setCursor(0, 1);
          lcd.print(medida);
          lcd.print(" ml");
          //delay(1000); 

          /*Armazene os valores lidos a partir da entrada analógica 0 dentro de uma EEPROM.
          Esses valores permanecem na EEPROM mesmo após o desligamento da placa Arduino e 
          podem ser mais tarde recuperados com outro esboço.*/ 

          EEPROM.write(addr, count);

  }
}
