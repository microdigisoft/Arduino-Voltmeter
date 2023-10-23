int analogInput = A1; // Define Analog pin A1 f to read potential
float vout = 0.0;
float vin = 0.0;
float R1 = 30000.0; //
float R2 = 7500.0; //
int value = 0;
void setup() {
  pinMode(analogInput, INPUT);
  Serial.begin(9600);
  Serial.print("DC VOLTMETER");
}
void loop() {
  // read the value at analog input
  value = analogRead(analogInput);
  vout = (value * 5.0) / 1024.0; // see text
  vin = vout / (R2 / (R1 + R2)); // Calculate Inout voltage

  Serial.print("INPUT V= ");
  Serial.println(vin, 2);
  delay(500);
}