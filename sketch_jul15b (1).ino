#include <ESP8266WiFi.h>
 
const char* ssid = "Galaxy j7";
const char* password = "msdhonisonai";
WiFiServer server(80);
void setup() {
  Serial.begin(115200);
  delay(10);

  // put your setup code here, to run once:
  pinMode(00, OUTPUT);
  pinMode(01, OUTPUT);
  pinMode(02, OUTPUT);
  pinMode(03, OUTPUT);
  pinMode(04, OUTPUT);
  pinMode(05, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(14, OUTPUT);
  pinMode(15, OUTPUT);
  pinMode(16, OUTPUT);

  digitalWrite(00, LOW);
  digitalWrite(01, LOW);
  digitalWrite(02, LOW);
  digitalWrite(03, LOW);
  digitalWrite(04, LOW);
  digitalWrite(05, LOW);
  digitalWrite(12, LOW);
  digitalWrite(13, LOW);
  digitalWrite(14, LOW);
  digitalWrite(15, LOW);
  digitalWrite(16, HIGH);

  // Connect to WiFi network
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
 
  WiFi.begin(ssid, password);
 
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  //Serial.println("Hi Kolkata");
  Serial.println("WiFi connected");
 
  // Start the server
  server.begin();
  Serial.println("Server started");
 
  // Print the IP address
  Serial.print("Use this URL to connect: ");
  Serial.print("http://");
  Serial.print(WiFi.localIP());
  Serial.println("/");
}

 
void loop() {
  // Check if a client has connected
  WiFiClient client = server.available();
  if (!client) {
    return;
  }
 
  // Wait until the client sends some data
  Serial.println("new client");
  while(!client.available()){
    delay(1);
  }
 
  // Read the first line of the request
  String request = client.readStringUntil('\r');
  Serial.println(request);
  client.flush();
 
  // Match the request
 
  int value_00 = LOW;
  int value_01 = LOW;
  int value_02 = LOW;
  int value_03 = LOW;
  int value_04 = LOW;
  int value_05 = LOW;
  int value_12 = LOW;
  int value_13 = LOW;
  int value_14 = LOW;
  int value_15 = LOW;
  int value_16 = LOW;
  if (request.indexOf("/LED00=ON") != -1)  {
    digitalWrite(00, HIGH);
    value_00 = HIGH;
  }
  if (request.indexOf("/LED00=OFF") != -1)  {
    digitalWrite(00, LOW);
    value_00 = LOW;
  }
  if (request.indexOf("/LED01=ON") != -1)  {
    digitalWrite(01, HIGH);
    value_01 = HIGH;
  }
  if (request.indexOf("/LED01=OFF") != -1)  {
    digitalWrite(01, LOW);
    value_01 = LOW;
  }
  if (request.indexOf("/LED02=ON") != -1)  {
    digitalWrite(02, HIGH);
    value_02 = HIGH;
  }
  if (request.indexOf("/LED02=OFF") != -1)  {
    digitalWrite(02, LOW);
    value_02 = LOW;
  }
  if (request.indexOf("/LED03=ON") != -1)  {
    digitalWrite(03, HIGH);
    value_03 = HIGH;
  }
  if (request.indexOf("/LED03=OFF") != -1)  {
    digitalWrite(03, LOW);
    value_03 = LOW;
  }
  if (request.indexOf("/LED04=ON") != -1)  {
    digitalWrite(04, HIGH);
    value_04 = HIGH;
  }
  if (request.indexOf("/LED04=OFF") != -1)  {
    digitalWrite(04, LOW);
    value_04 = LOW;
  }
  if (request.indexOf("/LED05=ON") != -1)  {
    digitalWrite(05, HIGH);
    value_05 = HIGH;
  }
  if (request.indexOf("/LED05=OFF") != -1)  {
    digitalWrite(05, LOW);
    value_05 = LOW;
  }
  if (request.indexOf("/LED12=ON") != -1)  {
    digitalWrite(12, HIGH);
    value_12 = HIGH;
  }
  if (request.indexOf("/LED12=OFF") != -1)  {
    digitalWrite(12, LOW);
    value_12 = LOW;
  }
  if (request.indexOf("/LED13=ON") != -1)  {
    digitalWrite(13, HIGH);
    value_13 = HIGH;
  }
  if (request.indexOf("/LED13=OFF") != -1)  {
    digitalWrite(13, LOW);
    value_13 = LOW;
  }
  if (request.indexOf("/LED14=ON") != -1)  {
    digitalWrite(14, HIGH);
    value_14 = HIGH;
  }
  if (request.indexOf("/LED14=OFF") != -1)  {
    digitalWrite(14, LOW);
    value_14 = LOW;
  }
  if (request.indexOf("/LED15=ON") != -1)  {
    digitalWrite(15, HIGH);
    value_15 = HIGH;
  }
  if (request.indexOf("/LED15=OFF") != -1)  {
    digitalWrite(15, LOW);
    value_15 = LOW;
  }
  if (request.indexOf("/LED16=ON") != -1)  {
    digitalWrite(16, HIGH);
    value_16 = HIGH;
  }
  if (request.indexOf("/LED16=OFF") != -1)  {
    digitalWrite(16, LOW);
    value_16 = LOW;
  }
 
// Set ledPin according to the request
//digitalWrite(ledPin, value);
 
  // Return the response
  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println(""); //  do not forget this one
  client.println("<!DOCTYPE HTML>");
  client.println("<html>");
 
  client.print("Led pin is now: ");
 
  if(value_00 == HIGH) {
    client.print("On");
  } else {
    client.print("Off");
  }
  client.println("<br><br>");
  client.println("<a href=\"/LED00=ON\"\"><button style=\"background-color:blue\">Turn 00 On </button></a>");
  client.println("<a href=\"/LED00=OFF\"\"><button style=\"background-color:red\">Turn 00 Off </button></a><br /><br />");  
  client.println("<a href=\"/LED01=ON\"\"><button style=\"background-color:blue\">Turn 01 On </button></a>");
  client.println("<a href=\"/LED01=OFF\"\"><button style=\"background-color:red\">Turn 01 Off </button></a><br /><br />");  
  client.println("<a href=\"/LED02=ON\"\"><button style=\"background-color:blue\">Turn 02 On </button></a>");
  client.println("<a href=\"/LED02=OFF\"\"><button style=\"background-color:red\">Turn 02 Off </button></a><br /><br />");
  client.println("<a href=\"/LED03=ON\"\"><button style=\"background-color:blue\">Turn 03 On </button></a>");
  client.println("<a href=\"/LED03=OFF\"\"><button style=\"background-color:red\">Turn 03 Off </button></a><br /><br />");  
  client.println("<a href=\"/LED04=ON\"\"><button style=\"background-color:blue\">Turn 04 On </button></a>");
  client.println("<a href=\"/LED04=OFF\"\"><button style=\"background-color:red\">Turn 04 Off </button></a><br /><br />");  
  client.println("<a href=\"/LED05=ON\"\"><button style=\"background-color:blue\">Turn 05 On </button></a>");
  client.println("<a href=\"/LED05=OFF\"\"><button style=\"background-color:red\">Turn 05 Off </button></a><br /><br />");  
  client.println("<a href=\"/LED12=ON\"\"><button style=\"background-color:blue\">Turn 12 On </button></a>"); 
  client.println("<a href=\"/LED12=OFF\"\"><button style=\"background-color:red\">Turn 12 Off </button></a><br /><br />");
  client.println("<a href=\"/LED13=ON\"\"><button style=\"background-color:blue\">Turn 13 On </button></a>");
  client.println("<a href=\"/LED13=OFF\"\"><button style=\"background-color:red\">Turn 13 Off </button></a><br /><br />");  
  client.println("<a href=\"/LED14=ON\"\"><button style=\"background-color:blue\">Turn 14 On </button></a>");
  client.println("<a href=\"/LED14=OFF\"\"><button style=\"background-color:red\">Turn 14 Off </button></a><br /><br />");  
  client.println("<a href=\"/LED15=ON\"\"><button style=\"background-color:blue\">Turn 15 On </button></a>");
  client.println("<a href=\"/LED15=OFF\"\"><button style=\"background-color:red\">Turn 15 Off </button></a><br /><br />"); 
  client.println("<a href=\"/LED16=ON\"\"><button style=\"background-color:blue\">Turn 16 On </button></a>");
  client.println("<a href=\"/LED16=OFF\"\"><button style=\"background-color:red\">Turn 16 Off </button></a><br /><br />");   
  client.println("</html>");
 
  delay(1);
  Serial.println("Client disonnected");
  Serial.println("");
 
}
