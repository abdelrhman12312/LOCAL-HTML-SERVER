

// Load Wi-Fi library
#include <ESP8266WiFi.h>
#include <Wire.h>
#include "Adafruit_MCP23017.h"

// Replace with your network credentials
const char* ssid     = "YOUR WIFI NETWWORK SSD ";
const char* password = "PASSWORD";

// Set web server port number to 80
WiFiServer server(80);

// Variable to store the HTTP request
String header;

// Auxiliar variables to store the current output state
//defult out state for the 16 outputs
String outstate1  = "off";
String outstate2  = "off";
String outstate3  = "off";
String outstate4  = "off";
String outstate5  = "off";
String outstate6  = "off";
String outstate7  = "off";
String outstate8  = "off";
String outstate9  = "off";
String outstate10 = "off";
String outstate11 = "off";
String outstate12 = "off";
String outstate13 = "off";
String outstate14 = "off";
String outstate15 = "off";
String outstate16 = "off";
// make io expander object
Adafruit_MCP23017 mcp;
// Assign output variables to GPIO pins
//const int output5 = 5;
//const int output4 = 4;

// Current time
unsigned long currentTime = millis();
// Previous time
unsigned long previousTime = 0;
// Define timeout time in milliseconds (example: 2000ms = 2s)
const long timeoutTime = 2000;

void setup() {
  mcp.begin();
  Serial.begin(115200);
  //make all pins as outputs
  for(int i = 0 ; i < 15; i++)
    mcp.pinMode(i,OUTPUT);
//make all relays as off for the start of the program
  for(int i = 0 ; i < 15; i++)
    mcp.digitalWrite(i,LOW);
  /* Initialize the output variables as outputs
  pinMode(output5, OUTPUT);
  pinMode(output4, OUTPUT);
  // Set outputs to LOW
  digitalWrite(output5, LOW);
  digitalWrite(output4, LOW);
          */
  // Connect to Wi-Fi network with SSID and password
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  // Print local IP address and start web server
  Serial.println("");
  Serial.println("WiFi connected.");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  server.begin();
}

void loop(){
  WiFiClient client = server.available();   // Listen for incoming clients

  if (client) {                             // If a new client connects,
    Serial.println("New Client.");          // print a message out in the serial port
    String currentLine = "";                // make a String to hold incoming data from the client
    currentTime = millis();
    previousTime = currentTime;
    while (client.connected() && currentTime - previousTime <= timeoutTime) { // loop while the client's connected
      currentTime = millis();
      if (client.available()) {             // if there's bytes to read from the client,
        char c = client.read();             // read a byte, then
        Serial.write(c);                    // print it out the serial monitor
        header += c;
        if (c == '\n') {                    // if the byte is a newline character
          // if the current line is blank, you got two newline characters in a row.
          // that's the end of the client HTTP request, so send a response:
          if (currentLine.length() == 0) {
            // HTTP headers always start with a response code (e.g. HTTP/1.1 200 OK)
            // and a content-type so the client knows what's coming, then a blank line:
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println("Connection: close");
            client.println();

            // turns the GPIOs on and off
            //GPIO 1 code
            if (header.indexOf("GET /1/on") >= 0) {
              Serial.println("GPIO 1 on");
              outstate1 = "on";
              digitalWrite(0, HIGH);
            } else if (header.indexOf("GET /1/off") >= 0) {
              Serial.println("GPIO 1 off");
              outstate1 = "off";
              digitalWrite(0, LOW);
            } //the GPIO 2 code
              else if (header.indexOf("GET /2/on") >= 0) {
              Serial.println("GPIO 2 on");
              outstate2 = "on";
              digitalWrite(1, HIGH);
            } else if (header.indexOf("GET /2/off") >= 0) {
              Serial.println("GPIO 2 off");
              outstate2 = "off";
              digitalWrite(1, LOW);
            } //the GPIO 3 code
              else if (header.indexOf("GET /3/on") >= 0) {
              Serial.println("GPIO 3 on");
              outstate3 = "on";
              digitalWrite(2, HIGH);
            } else if (header.indexOf("GET /3/off") >= 0) {
              Serial.println("GPIO 3 off");
              outstate3 = "off";
              digitalWrite(2, LOW);
            } //the GPIO 4 code
              else if (header.indexOf("GET /4/on") >= 0) {
              Serial.println("GPIO 4 on");
              outstate4 = "on";
              digitalWrite(3, HIGH);
            } else if (header.indexOf("GET /4/off") >= 0) {
              Serial.println("GPIO 4 off");
              outstate4 = "off";
              digitalWrite(3, LOW);
            } //GPIO 5
            else  if (header.indexOf("GET /5/on") >= 0) {
              Serial.println("GPIO 5 on");
              outstate5 = "on";
              digitalWrite(4, HIGH);
            } else if (header.indexOf("GET /5/off") >= 0) {
              Serial.println("GPIO 5 off");
              outstate5 = "off";
              digitalWrite(4, LOW);
            } //the GPIO 6 code
              else if (header.indexOf("GET /6/on") >= 0) {
              Serial.println("GPIO 6 on");
              outstate6 = "on";
              digitalWrite(5, HIGH);
            } else if (header.indexOf("GET /6/off") >= 0) {
              Serial.println("GPIO 6 off");
              outstate6 = "off";
              digitalWrite(5, LOW);
            } //the GPIO 7 code
              else if (header.indexOf("GET /7/on") >= 0) {
              Serial.println("GPIO 7 on");
              outstate7 = "on";
              digitalWrite(6, HIGH);
            } else if (header.indexOf("GET /7/off") >= 0) {
              Serial.println("GPIO 7 off");
              outstate7 = "off";
              digitalWrite(6, LOW);
            } //the GPIO 8 code
              else if (header.indexOf("GET /8/on") >= 0) {
              Serial.println("GPIO 8 on");
              outstate8 = "on";
              digitalWrite(7, HIGH);
            } else if (header.indexOf("GET /8/off") >= 0) {
              Serial.println("GPIO 8 off");
              outstate8 = "off";
              digitalWrite(7, LOW);
            }
          //GPIO 9
            if (header.indexOf("GET /9/on") >= 0) {
              Serial.println("GPIO 9 on");
              outstate9 = "on";
              digitalWrite(8, HIGH);
            } else if (header.indexOf("GET /9/off") >= 0) {
              Serial.println("GPIO 9 off");
              outstate9 = "off";
              digitalWrite(8, LOW);
            } //the GPIO 10 code
              else if (header.indexOf("GET /10/on") >= 0) {
              Serial.println("GPIO 10 on");
              outstate10 = "on";
              digitalWrite(9, HIGH);
            } else if (header.indexOf("GET /10/off") >= 0) {
              Serial.println("GPIO 10 off");
              outstate10 = "off";
              digitalWrite(9, LOW);
            } //the GPIO 11 code
              else if (header.indexOf("GET /11/on") >= 0) {
              Serial.println("GPIO 11 on");
              outstate11 = "on";
              digitalWrite(10, HIGH);
            } else if (header.indexOf("GET /11/off") >= 0) {
              Serial.println("GPIO 11 off");
              outstate11 = "off";
              digitalWrite(10, LOW);
            } //the GPIO 12 code
              else if (header.indexOf("GET /12/on") >= 0) {
              Serial.println("GPIO 12 on");
              outstate12 = "on";
              digitalWrite(11, HIGH);
            } else if (header.indexOf("GET /12/off") >= 0) {
              Serial.println("GPIO 12 off");
              outstate12 = "off";
              digitalWrite(11, LOW);
            } //GPIO 13 code
            if (header.indexOf("GET /13/on") >= 0) {
              Serial.println("GPIO 13 on");
              outstate13 = "on";
              digitalWrite(12, HIGH);
            } else if (header.indexOf("GET /13/off") >= 0) {
              Serial.println("GPIO 13 off");
              outstate13 = "off";
              digitalWrite(12, LOW);
            } //the GPIO 14 code
              else if (header.indexOf("GET /14/on") >= 0) {
              Serial.println("GPIO 14 on");
              outstate14 = "on";
              digitalWrite(13, HIGH);
            } else if (header.indexOf("GET /14/off") >= 0) {
              Serial.println("GPIO 14 off");
              outstate14 = "off";
              digitalWrite(13, LOW);
            } //the GPIO 15 code
              else if (header.indexOf("GET /15/on") >= 0) {
              Serial.println("GPIO 7 on");
              outstate15 = "on";
              digitalWrite(14, HIGH);
            } else if (header.indexOf("GET /15/off") >= 0) {
              Serial.println("GPIO 15 off");
              outstate15 = "off";
              digitalWrite(14, LOW);
            } //the GPIO 16 code
              else if (header.indexOf("GET /16/on") >= 0) {
              Serial.println("GPIO 8 on");
              outstate16 = "on";
              digitalWrite(15, HIGH);
            } else if (header.indexOf("GET /16/off") >= 0) {
              Serial.println("GPIO 16 off");
              outstate16 = "off";
              digitalWrite(15, LOW);
            }

            // Display the HTML web page
            client.println("<!DOCTYPE html><html>");
            client.println("<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">");
            client.println("<link rel=\"icon\" href=\"data:,\">");
            // CSS to style the on/off buttons
            // Feel free to change the background-color and font-size attributes to fit your preferences
            client.println("<style>html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}");
            client.println(".button { background-color: #195B6A; border: none; color: white; padding: 16px 40px;");
            client.println("text-decoration: none; font-size: 30px; margin: 2px; cursor: pointer;}");
            client.println(".button2 {background-color: #77878A;}</style></head>");

            // Web Page Heading
            client.println("<body><h1>ESP8266 TEST web server </h1>");

            // Display current state, and ON/OFF buttons for GPIO 5
            //client.println("<p>GPIO 5 - State " + output5State + "</p>");
            // If the output5State is off, it displays the ON button
            if (outstate1=="off") {
              client.println("<p><a href=\"/1/on\"><button class=\"button\">ON</button></a></p>");
            } else {
              client.println("<p><a href=\"/1/off\"><button class=\"button button2\">OFF</button></a></p>");
            }

            // Display current state, and ON/OFF buttons for GPIO 4
            //client.println("<p>GPIO 4 - State " + output4State + "</p>");
            // If the output4State is off, it displays the ON button
            if (outstate2=="off") {
              client.println("<p><a href=\"/2/on\"><button class=\"button\">ON</button></a></p>");
            } else {
              client.println("<p><a href=\"/2/off\"><button class=\"button button2\">OFF</button></a></p>");
            }
            // Display current state, and ON/OFF buttons for GPIO 5
            //client.println("<p>GPIO 5 - State " + output5State + "</p>");
            // If the output5State is off, it displays the ON button
            if (outstate3=="off") {
              client.println("<p><a href=\"/3/on\"><button class=\"button\">ON</button></a></p>");
            } else {
              client.println("<p><a href=\"/3/off\"><button class=\"button button2\">OFF</button></a></p>");
            }
            // Display current state, and ON/OFF buttons for GPIO 5
            //client.println("<p>GPIO 5 - State " + output5State + "</p>");
            // If the output5State is off, it displays the ON button
            if (outstate4=="off") {
              client.println("<p><a href=\"/4/on\"><button class=\"button\">ON</button></a></p>");
            } else {
              client.println("<p><a href=\"/4/off\"><button class=\"button button2\">OFF</button></a></p>");
            }
            // Display current state, and ON/OFF buttons for GPIO 5
            //client.println("<p>GPIO 5 - State " + output5State + "</p>");
            // If the output5State is off, it displays the ON button
            if (outstate5=="off") {
              client.println("<p><a href=\"/5/on\"><button class=\"button\">ON</button></a></p>");
            } else {
              client.println("<p><a href=\"/5/off\"><button class=\"button button2\">OFF</button></a></p>");
            }
            // Display current state, and ON/OFF buttons for GPIO 5
            //client.println("<p>GPIO 5 - State " + output5State + "</p>");
            // If the output5State is off, it displays the ON button
            if (outstate6=="off") {
              client.println("<p><a href=\"/6/on\"><button class=\"button\">ON</button></a></p>");
            } else {
              client.println("<p><a href=\"/6/off\"><button class=\"button button2\">OFF</button></a></p>");
            }
            // Display current state, and ON/OFF buttons for GPIO 5
            //client.println("<p>GPIO 5 - State " + output5State + "</p>");
            // If the output5State is off, it displays the ON button
            if (outstate7=="off") {
              client.println("<p><a href=\"/7/on\"><button class=\"button\">ON</button></a></p>");
            } else {
              client.println("<p><a href=\"/7/off\"><button class=\"button button2\">OFF</button></a></p>");
            }
            // Display current state, and ON/OFF buttons for GPIO 5
            //client.println("<p>GPIO 5 - State " + output5State + "</p>");
            // If the output5State is off, it displays the ON button
            if (outstate8=="off") {
              client.println("<p><a href=\"/8/on\"><button class=\"button\">ON</button></a></p>");
            } else {
              client.println("<p><a href=\"/8/off\"><button class=\"button button2\">OFF</button></a></p>");
            }
            // Display current state, and ON/OFF buttons for GPIO 5
            //client.println("<p>GPIO 5 - State " + output5State + "</p>");
            // If the output5State is off, it displays the ON button
            if (outstate9=="off") {
              client.println("<p><a href=\"/9/on\"><button class=\"button\">ON</button></a></p>");
            } else {
              client.println("<p><a href=\"/9/off\"><button class=\"button button2\">OFF</button></a></p>");
            }
            // Display current state, and ON/OFF buttons for GPIO 5
            //client.println("<p>GPIO 5 - State " + output5State + "</p>");
            // If the output5State is off, it displays the ON button
            if (outstate10=="off") {
              client.println("<p><a href=\"/10/on\"><button class=\"button\">ON</button></a></p>");
            } else {
              client.println("<p><a href=\"/10/off\"><button class=\"button button2\">OFF</button></a></p>");
            }

            if (outstate11=="off") {
              client.println("<p><a href=\"/11/on\"><button class=\"button\">ON</button></a></p>");
            } else {
              client.println("<p><a href=\"/11/off\"><button class=\"button button2\">OFF</button></a></p>");
            }

            if (outstate12=="off") {
              client.println("<p><a href=\"/12/on\"><button class=\"button\">ON</button></a></p>");
            } else {
              client.println("<p><a href=\"/12/off\"><button class=\"button button2\">OFF</button></a></p>");
            }

            if (outstate13=="off") {
              client.println("<p><a href=\"/13/on\"><button class=\"button\">ON</button></a></p>");
            } else {
              client.println("<p><a href=\"/13/off\"><button class=\"button button2\">OFF</button></a></p>");
            }

            if (outstate14=="off") {
              client.println("<p><a href=\"/14/on\"><button class=\"button\">ON</button></a></p>");
            } else {
              client.println("<p><a href=\"/14/off\"><button class=\"button button2\">OFF</button></a></p>");
            }

            if (outstate15=="off") {
              client.println("<p><a href=\"/15/on\"><button class=\"button\">ON</button></a></p>");
            } else {
              client.println("<p><a href=\"/15/off\"><button class=\"button button2\">OFF</button></a></p>");
            }
            // If the output5State is off, it displays the ON button
            if (outstate16=="off") {
              client.println("<p><a href=\"/16/on\"><button class=\"button\">ON</button></a></p>");
            } else {
              client.println("<p><a href=\"/16/off\"><button class=\"button button2\">OFF</button></a></p>");
            }
            client.println("</body></html>");

            // The HTTP response ends with another blank line
            client.println();
            // Break out of the while loop
            break;
          } else { // if you got a newline, then clear currentLine
            currentLine = "";
          }
        } else if (c != '\r') {  // if you got anything else but a carriage return character,
          currentLine += c;      // add it to the end of the currentLine
        }
      }
    }
    // Clear the header variable
    header = "";
    // Close the connection
    client.stop();
    Serial.println("Client disconnected.");
    Serial.println("");
  }
}
