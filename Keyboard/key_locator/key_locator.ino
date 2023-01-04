int keyRows[]={2,3,4,5,6,7,8,9};
int keyCols[]={10,11,12,15,16,17,18,19,20,21};//PULLED UP

void setup() {
  Serial.begin(9600);
  
  for(int z=0;z<10;z++){
    pinMode(keyCols[z],INPUT_PULLUP);
  }
 
}

void loop() {

    for(int z=0;z<10;z++){
        for(int i=0;i<8;i++){
          pinMode(keyRows[i],OUTPUT);
          digitalWrite(keyRows[i],LOW);
          if(digitalRead(keyCols[z])==LOW){ 
            Serial.print("COL");
            Serial.print(z);
            Serial.print("ROW:");
            Serial.println(i);
          }
          pinMode(keyRows[i],INPUT);
        }
    }
}
