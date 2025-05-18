#include <Wire.h>
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

// Wi-Fi Credentials
const char* ssid = "BotNet";
const char* password = "ConnorRev-9";

// Web server on port 80
ESP8266WebServer server(80);

// Sensor Pins
#define TRIG_PIN 4    // D2 (GPIO4) - Shared Trigger Pin
#define ECHO_PIN_1 12 // D6 (GPIO12) - Echo for Lane 1 (Coca-Cola)
#define ECHO_PIN_2 13 // D7 (GPIO13) - Echo for Lane 2 (Coffee)
#define ECHO_PIN_3 14 // D5 (GPIO14) - Echo for Lane 3 (Smoothies)

// Distance ranges
struct Range {
    float minDistance;
    float maxDistance;
};

// Coca-Cola (Lane 1)
const Range colaRanges[] = {
    {3.3, 7.0},
    {7.01, 14.3},
    {14.31, 20.0},
    {20.01, 28.0}
};

// Coffee (Lane 2)
const Range coffeeRanges[] = {
    {0.0, 5.2},
    {5.21, 12.0},
    {12.01, 17.0},
    {17.01, 23.0},
    {23.01, 30.0}
};

// Smoothies (Lane 3)
const Range smoothieRanges[] = {
    {0.0, 12.8},
    {12.81, 17.3},
    {17.31, 22.88},
    {22.89, 28.3},
    {28.31, 30.2}
};

void setup() {
    Serial.begin(115200);
    Serial.println("\nStarting Smart Fridge...");

    WiFi.begin(ssid, password);
    Serial.print("Connecting to WiFi...");
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }

    Serial.println("\nWiFi connected!");
    Serial.print("IP Address: ");
    Serial.println(WiFi.localIP());

    pinMode(TRIG_PIN, OUTPUT);
    pinMode(ECHO_PIN_1, INPUT);
    pinMode(ECHO_PIN_2, INPUT);
    pinMode(ECHO_PIN_3, INPUT);

    server.on("/", handleRoot);
    server.begin();
    Serial.println("HTTP server started.");
}

float measureDistance(int echoPin) {
    digitalWrite(TRIG_PIN, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIG_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG_PIN, LOW);

    long duration = pulseIn(echoPin, HIGH, 30000);
    if (duration == 0) return -1;

    return (duration * 0.0343) / 2;
}

int calculateColaCansLeft(float distance) {
    for (int i = 0; i < 4; i++) {
        if (distance >= colaRanges[i].minDistance && distance <= colaRanges[i].maxDistance) {
            return 4 - i;
        }
    }
    return 0;
}

int calculateCoffeeCansLeft(float distance) {
    for (int i = 0; i < 5; i++) {
        if (distance >= coffeeRanges[i].minDistance && distance <= coffeeRanges[i].maxDistance) {
            return 5 - i;
        }
    }
    return 0;
}

int calculateSmoothieCansLeft(float distance) {
    if (distance < 0) return 0;
    if (distance <= 12.8) return 4;
    else if (distance <= 17.3) return 3;
    else if (distance <= 22.88) return 2;
    else if (distance <= 28.3) return 1;
    else return 0;
}

String displayCans(int count, String image, float scaleFactor) {
    String output = "<div style='display:flex; gap:5px; justify-content:center;'>";
    for (int i = 0; i < count; i++) {
        output += "<img src='" + image + "' style='width: " + String(60 * scaleFactor) + "px; height: auto;'>";
    }
    output += "</div>";
    return output;
}

void handleRoot() {
    float distance1 = measureDistance(ECHO_PIN_1);
    delay(100);
    float distance2 = measureDistance(ECHO_PIN_2);
    delay(100);
    float distance3 = measureDistance(ECHO_PIN_3);

    int cansLeft1 = calculateColaCansLeft(distance1);
    int cansLeft2 = calculateCoffeeCansLeft(distance2);
    int cansLeft3 = calculateSmoothieCansLeft(distance3);

    String html = "<html><head>";
    html += "<meta http-equiv='refresh' content='2'>";
    html += "<title>Smart Fridge Inventory</title>";
    html += "<style>body { font-family: Arial; text-align: center; } .restock { color: red; font-weight: bold; }</style></head><body>";

    html += "<h1>Smart Fridge Sensor Data</h1>";

    // Lane 1: Coca-Cola
    html += "<div><h2>Lane 1: Coca-Cola</h2>";
    html += "<p>" + String(cansLeft1) + " cans left</p>";
    if (cansLeft1 == 0) html += "<p class='restock'>Please restock!</p>";
    html += displayCans(cansLeft1, "https://melcom.com/media/catalog/product/cache/d0e1b0d5c74d14bfa9f7dd43ec52d082/x/5/x584a_1.jpg", 1.3);
    html += "<p>(Distance: " + String(distance1) + " cm)</p></div>";

    // Lane 2: Coffee
    html += "<div><h2>Lane 2: Coffee Cans</h2>";
    html += "<p>" + String(cansLeft2) + " cans left</p>";
    if (cansLeft2 == 0) html += "<p class='restock'>Please restock!</p>";
    html += displayCans(cansLeft2, "https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcRwr6HSL-OyBAPD2LCD-cyMpGq-ZcaVujSh-g&s", 1.0);
    html += "<p>(Distance: " + String(distance2) + " cm)</p></div>";

    // Lane 3: Smoothies
    html += "<div><h2>Lane 3: Smoothies</h2>";
    html += "<p>" + String(cansLeft3) + " cans left</p>";
    if (cansLeft3 == 0) html += "<p class='restock'>Please restock!</p>";
    html += displayCans(cansLeft3, "https://public.keskofiles.com/f/k-ruoka/product/6430054833936?auto=format&fm=jpg&cs=srgb", 1.1);
    html += "<p>(Distance: " + String(distance3) + " cm)</p></div>";

    html += "</body></html>";
    server.send(200, "text/html", html);
}

void loop() {
    server.handleClient();
}
