#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

// Wi-Fi Credentials
const char* ssid = "granqvist";
const char* password = "";

// Web server on port 80
ESP8266WebServer server(80);

// Sensor Pins
#define TRIG_PIN 4    // D2 (GPIO4) - Shared Trigger Pin
#define ECHO_PIN_1 12 // D6 (GPIO12) - Echo for Sensor 1
#define ECHO_PIN_2 13 // D7 (GPIO13) - Echo for Sensor 2
#define ECHO_PIN_3 14 // D5 (GPIO14) - Echo for Sensor 3

void setup() {
    Serial.begin(115200);
    WiFi.begin(ssid, password);
    
    Serial.print("Connecting to WiFi...");
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }

    Serial.println("\nWiFi connected!");
    Serial.print("IP Address: ");
    Serial.println(WiFi.localIP());

    // Configure GPIO pins
    pinMode(TRIG_PIN, OUTPUT);
    pinMode(ECHO_PIN_1, INPUT);
    pinMode(ECHO_PIN_2, INPUT);
    pinMode(ECHO_PIN_3, INPUT);

    // Set up web server
    server.on("/", handleRoot);
    server.begin();
    Serial.println("HTTP server started");
}

// Function to measure distance from a sensor
float measureDistance(int echoPin) {
    digitalWrite(TRIG_PIN, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIG_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG_PIN, LOW);

    long duration = pulseIn(echoPin, HIGH);
    float distance = (duration * 0.0343) / 2;
    return distance;
}

// Webpage HTML
void handleRoot() {
    float distance1 = measureDistance(ECHO_PIN_1);
    delay(100);
    float distance2 = measureDistance(ECHO_PIN_2);
    delay(100);
    float distance3 = measureDistance(ECHO_PIN_3);

    String html = "<html><head>";
    html += "<meta http-equiv='refresh' content='2'>";  // Auto-refresh page every 2 seconds
    html += "<title>Smart Fridge Sensor Data</title></head><body>";
    html += "<h1>Smart Fridge Sensor Data</h1>";
    html += "<p><b>Sensor 1:</b> " + String(distance1) + " cm</p>";
    html += "<p><b>Sensor 2:</b> " + String(distance2) + " cm</p>";
    html += "<p><b>Sensor 3:</b> " + String(distance3) + " cm</p>";
    html += "</body></html>";

    server.send(200, "text/html", html);
}

void loop() {
    server.handleClient();  // Handle web requests
}
