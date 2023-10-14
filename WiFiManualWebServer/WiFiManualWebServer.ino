/*
    This sketch demonstrates how to set up a simple HTTP-like server.
    The server will set a GPIO pin depending on the request
      http://server_ip/gpio/0 will set the GPIO2 low,
      http://server_ip/gpio/1 will set the GPIO2 high
    server_ip is the IP address of the ESP8266 module, will be
    printed to Serial when the module is connected.
*/

#include <ESP8266WiFi.h>
#include "motor.h"

#ifndef STASSID
#define STASSID "MI 9"
#define STAPSK "12345678"
#endif

const char* ssid = STASSID;
const char* password = STAPSK;

// Create an instance of the server
// specify the port to listen on as an argument
WiFiServer server(80);

void setup() {
  Serial.begin(115200);

  // prepare LED
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, 0);

  // Connect to WiFi network
  Serial.println();
  Serial.println();
  Serial.print(F("Connecting to "));
  Serial.println(ssid);

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(F("."));
  }
  Serial.println();
  Serial.println(F("WiFi connected"));

  // Start the server
  server.begin();
  Serial.println(F("Server started"));

  // Print the IP address
  Serial.println(WiFi.localIP());
}

void loop() {
  // Check if a client has connected
  WiFiClient client = server.accept();
  if (!client) { return; }
  Serial.println(F("new client"));

  client.setTimeout(5000);  // default is 1000

  // Read the first line of the request
  String req = client.readStringUntil('\r');
  Serial.println(F("request: "));
  Serial.println(req);

  // Match the request
  /* Controles do carrinho  */
  char val;
  if (req.indexOf(F("/W")) != -1) {
    moveFrente();
  } else if (req.indexOf(F("/S")) != -1) {
    moveRe();
  } else if(req.indexOf(F("/D")) != -1){
    direita();
  } else if(req.indexOf(F("/A")) != -1){
    esquerda();
  }
  else {
    Serial.println(F("invalid request"));
    parar();
  }

  // read/ignore the rest of the request
  // do not client.flush(): it is for output only, see below
  while (client.available()) {
    // byte by byte is not very efficient
    client.read();
  }

  // Send the response to the client
  // it is OK for multiple small client.print/write,
  // because nagle algorithm will group them into one single packet
  client.print(F("HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n<!DOCTYPE HTML>\r\n<html>\r\n"));
  client.print(F("<head>"));
  client.print(F("</head>"));
  /* body */
  client.println("<body>");
    client.print(F("<main>"));
      client.print(F("<section class='joystick center'>"));
        client.println(F("<div class='animations'>"));
          client.println(F("<aside class='left-hand'>"));
            client.println(F("<div class='controler'>"));
              client.print("<a href='http://");
              client.print(WiFi.localIP());
              client.println("/A' class='left'>teste</a> qualquer coisa");
  /* termina body */
  client.println("<a href='http://");
  client.print(WiFi.localIP());
  client.print(F("/W'>FRENTE</a> to switch LED GPIO on, or <a href='http://"));
  client.print(WiFi.localIP());
  client.print(F("/gpio/0'>here</a> to switch LED GPIO off.</html>"));

  // The client will actually be *flushed* then disconnected
  // when the function returns and 'client' object is destroyed (out-of-scope)
  // flush = ensure written data are received by the other side
  Serial.println(F("Disconnecting from client"));
}
