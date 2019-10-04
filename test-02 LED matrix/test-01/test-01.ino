int mat[8][8] = {{1,0,0,0,0,0,0,1},
                 {0,1,0,0,0,0,1,0},
                 {0,0,1,0,0,1,0,0},
                 {0,0,0,1,1,0,0,0},
                 {0,0,0,1,1,0,0,0},
                 {0,0,1,0,0,1,0,0},
                 {0,1,0,0,0,0,1,0},
                 {1,0,0,0,0,0,0,1}};


void setup(){
  pinMode(0 , OUTPUT);
  pinMode(1 , OUTPUT);
  pinMode(2 , OUTPUT);
  pinMode(3 , OUTPUT);
  pinMode(4 , OUTPUT);
  pinMode(5 , OUTPUT);
  pinMode(6 , OUTPUT);
  pinMode(7 , OUTPUT);
  pinMode(8 , OUTPUT);
  pinMode(9 , OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(A0, OUTPUT);
  pinMode(A1, OUTPUT);
  
}

void loop(){
  for(int i=0; i<8; i++){
    digitalWrite(i , LOW);
    
    for(int j=0; j<8; j++){
      if(mat[j][i] == 1){
        digitalWrite(8 + j , HIGH);
        //delay(5);
      }
      else
        digitalWrite(8 + j , LOW);
    }
    delay(1);
    digitalWrite(i , HIGH);
  }
}

