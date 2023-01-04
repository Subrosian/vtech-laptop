
typedef struct{
  int key;
  bool state;
} keyData;

keyData keys[8][10];


int keyRows[]={2,3,4,5,6,7,8,9};
int keyCols[]={10,11,12,15,16,17,18,19,20,21};//PULLED UP

void setup() {
  //ROW 0
  keys[0][0].key=MODIFIERKEY_SHIFT; //LEFT PLAYER 
  keys[0][1].key=KEY_3; 
  keys[0][2].key=KEY_LEFT; 
  keys[0][3].key=KEY_0; 
  //keys[0][4].key=; 
  keys[0][5].key=KEY_E;
  keys[0][6].key=KEY_SPACE; //REPEAT 
  keys[0][7].key=KEY_P; 
  //keys[0][8].key=; 
  //keys[0][9].key=; 
  
  //ROW 1
  keys[1][0].key=KEY_X; 
  keys[1][1].key=KEY_R; 
  keys[1][2].key=KEY_K; 
  keys[1][3].key=KEY_8; 
  //keys[1][4].key=; 
  keys[1][5].key=KEY_D; 
  keys[1][6].key=KEY_M; 
  keys[1][7].key=KEY_I; 
  //keys[1][8].key=; 
  //keys[1][9].key=; 
  
  //ROW 2
  keys[2][0].key=KEY_V; 
  keys[2][1].key=KEY_5; 
  keys[2][2].key=KEY_H; 
  keys[2][3].key=KEY_6; 
  //keys[2][4].key=; 
  keys[2][5].key=KEY_G; 
  keys[2][6].key=KEY_B; 
  keys[2][7].key=KEY_Y; 
  //keys[2][8].key=; 
  //keys[2][9].key=; 
  
  //ROW 3
  keys[3][0].key=KEY_Q; 
  keys[3][1].key=KEY_1; 
  //keys[3][2].key=; //ANSWER 
  //keys[3][3].key=; //OFF
  //keys[3][4].key=; 
  keys[3][5].key=MODIFIERKEY_CTRL; //PLAYER 
  //keys[3][6].key=; //RIGHT PLAYER
  keys[3][7].key=KEY_ENTER; 
  //keys[3][8].key=; 
  //keys[3][9].key=; 
  
  //ROW 4
  keys[4][0].key=KEY_W; 
  keys[4][1].key=KEY_2; 
  keys[4][2].key=KEY_RIGHT; 
  //keys[4][3].key=; //LEVEL 
  //keys[4][4].key=; 
  keys[4][5].key=KEY_A; 
  keys[4][6].key=KEY_DOWN; 
  keys[4][7].key=KEY_UP; 
  //keys[4][8].key=; 
  //keys[4][9].key=; 
  
  //ROW 5
  keys[5][0].key=KEY_Z; 
  keys[5][1].key=KEY_4; 
  keys[5][2].key=KEY_L; 
  keys[5][3].key=KEY_9; 
  //keys[5][4].key=;  
  keys[5][5].key=KEY_S; 
  keys[5][6].key=KEY_BACKSPACE; //ERASE
  keys[5][7].key=KEY_O; 
  //keys[5][8].key=; 
  //keys[5][9].key=; 
  
  //ROW 6
  keys[6][0].key=KEY_C; 
  keys[6][1].key=KEY_T; 
  keys[6][2].key=KEY_J; 
  keys[6][3].key=KEY_7; 
  //keys[6][4].key=; 
  keys[6][5].key=KEY_F; 
  keys[6][6].key=KEY_N; 
  keys[6][7].key=KEY_U; 
  //keys[6][8].key=; 
  //keys[6][9].key=; 
  
  //ROW 7
  // keys[7][0].key=; 
  // keys[7][1].key=; 
  // keys[7][2].key=; 
  // keys[7][3].key=; 
  // keys[7][4].key=; 
  // keys[7][5].key=; 
  // keys[7][6].key=; 
  // keys[7][7].key=; 
  // keys[7][8].key=; 
  // keys[7][9].key=; 
  
  
  Serial.begin(9600);
  
  for(int z=0;z<10;z++){
    pinMode(keyCols[z],INPUT_PULLUP);
  }


 
}

void loop() {
delay (10);
    for(int z=0;z<10;z++){
        for(int i=0;i<8;i++){
          
          pinMode(keyRows[i],OUTPUT);
          digitalWrite(keyRows[i],LOW);
          bool sampledState = digitalRead(keyCols[z]);
          
          if (sampledState != keys[i][z].state){
            
            keys[i][z].state = sampledState;
            
            if (sampledState){ //IF TRUE KEY UP
              
              Keyboard.release(keys[i][z].key);
              
            }else{ //ELSE KEY DOWN
              
              Keyboard.press(keys[i][z].key);
              
            }
            
          }
          pinMode(keyRows[i],INPUT);
        }
    }
}
