// Tech Trends Shameer
// Smart Irrigation System

int sensor_pin = A0;   // Moisture sensor connected to analog pin A0
int output_value = 0;  // Variable to store sensor reading
int pump_pin = 7;      // Relay or pump control pin

void setup() {
  pinMode(pump_pin, OUTPUT);
  Serial.begin(9600);
  Serial.println("Reading from the Moisture Sensor...");
  delay(2000);
}

void loop() {
  // Read analog value from sensor (0 - 1023)
  output_value = analogRead(sensor_pin);
  
  // Map the sensor reading to percentage (calibrate for your sensor)
  output_value = map(output_value, 550, 10, 0, 100);

  Serial.print("Moisture: ");
  Serial.print(output_value);
  Serial.println("%");
  
  // If soil is dry (low moisture value), turn pump ON
  if (output_value > 30) {  
    // Soil is dry
    digitalWrite(pump_pin, HIGH);  // Turn ON pump
    Serial.println("Soil is dry → Pump ON");
  } 
  else {
    // Soil is wet
    digitalWrite(pump_pin, LOW);   // Turn OFF pump
    Serial.println("Soil is wet → Pump OFF");
  }

  delay(1000);  // Wait 1 second before next reading
}
