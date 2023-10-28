int relay = 12;  // Digital pin D6
int sensor = 13;  // d7 
int dem = 0;
int trangthai =0; // 0 la tat 1 la bac
void setup() {

  pinMode(sensor, INPUT);   // declare sensor as input
  pinMode(relay, OUTPUT);  // declare LED as output
 Serial.begin(115200);
}
void loop() {

  int  state = digitalRead(sensor);
    if(state == HIGH) {
       Serial.println("Motion detected!"); 
         if (trangthai == 0) { digitalWrite (relay, LOW);delay(1000);  trangthai =1;  Serial.println("Bac den!"); }
         dem = 0;
   
    }

    
    if(state == LOW) {
      Serial.println("Motion absent!");
     if (trangthai == 1) {dem = dem +1 ; }
      
        if (dem == 45)
          {
            digitalWrite (relay, HIGH);
            dem =0;
            trangthai =0;
             Serial.println("Tat den!");
          }
      delay(1000);
      }
   Serial.print("Dem ");   
   Serial.println(dem);
}
