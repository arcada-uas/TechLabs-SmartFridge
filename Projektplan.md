# Projektplan

## **Smart kylskåpslösning för inventarieövervakning**

## Kund/beställare
För projektet är kunderna Dennis Biström och Harri Anukka. Beställarna vill utveckla en kostnadseffektiv och användarvänlig lösning för smartakylskåp med inventarieövervakning.

## Problemställning
I skolans "studylab" är det en utmaning att övervaka och hantera produkterna i kylskåpet som är till försäljning för studerare och personal. Nuvarande lösningar kräver manuell kontroll, vilket kan leda till ineffektiv hantering, onödigt spill och bristande överblick över lagret.

Detta projekt syftar till att utveckla en teknisk lösning för att automatisera inventarieövervakning i kylskåpet genom att använda sensorer och mikrokontroller. Fokus ligger på enkelhet, tillförlitlighet och att anpassa lösningen till den specifika miljön i skolans lab.

Projektet har praktisk relevans genom att erbjuda en lösning som kan optimera påfyllningsrutiner, säkerställa produktkvalitet och förbättra användarupplevelsen för både studenter och personal. Dessutom kan lösningen fungera som ett inlärnings verktyg genom att demonstrera hur IoT och automation kan användas för att lösa vardagliga problem.


## Bakgrund/Tidigare forskning
En genomgång av tidigare forskning och projekt visar att ultraljudssensorer och mikrokontroller, som ESP8266 och Raspberry Pi, ofta används för övervakning av lager och automation.  
Utmaningar som dokumenterats inkluderar trådlös kommunikation genom kylskåpsdörrar och energihantering.  

**Källor:**
- [HC-SR04 artikel1 ](https://tutorials-raspberrypi.com/raspberry-pi-ultrasonic-sensor-hc-sr04/) 

- [HC-SR04/ESP 8266 artikel2](https://randomnerdtutorials.com/micropython-hc-sr04-ultrasonic-esp32-esp8266/)

- [Tidigare Iot Smart fridge projekt](https://github.com/Abhishek0697/IoT_Refrigerator) 

- [Tidigare Iot Smart fridge projekt](http://www.ijlera.com/papers/v2-i3/part-II/31.201703127.pdf)

- Boken "Get started with MicroPython on Raspberry Pi Pico"


## Syfte, mål och forskningsfrågor
### Syfte
Att utveckla en funktionell och kostnadseffektiv lösning för inventarieövervakning i ett smartkylskåp.

### Mål
1. Implementera en lösning där RPi0 kopplas till ultraljudssensorer för varje produkt.  
2. Utveckla mekanisk design som förhindrar att produkter faller av hyllor.  
3. Säkerställa trådlös dataöverföring till server med hjälp av (RP4?).  
4. Skapa tydlig utvecklardokumentation och användarmanual.  
5. Övervaka kylskåpstemperatur och energiförbrukning. *

### Forskningsfrågor
- Hur kan vi designa simpel lösning för inventarieövervakning i kylskåp?  
- Vilka mekaniska och tekniska lösningar är mest lämpliga för att hantera olika typer av produkter?
- Hurdanna produkter kan användas?  

## Metoder
### Teknisk implementation
- Mikrokontroller (ESP8266, RPi0) för datahantering.  
- Ultraljudssensorer (HC-SR04P) för att identifiera borttagna produkter och kvantitet.  
- Trådlös dataöverföring via Bluetooth eller WiFi (RP4).  

### Mekanisk design
- 3D-utskrifter för gravitationsbaserad påfyllare som håller produkter på plats.  
- Modell för flexibel hyllstorlek för olika produkter.  

### Dataanalys
- Loggning av produktdata (tidstämpel och produktinfo).  
- Analys av energiförbrukning och temperaturövervakning.*

### Bedömning av funktionalitet
- Test för sensorerna och trådlösa kommunikationens funktionalitet.  
- Error testing.
- Hållbarhets test av 3D-printtade modeller.


## Resultat
Förväntade resultaten:  
- En fungerande smartkylskåp med inventariesövervakning.  
- Tydlig dokumentation för utvecklare och användare.  
- Förbättrad inventariehantering genom notifieringar om låg nivå och obetalda produkter.  
- Mekanisk design som säkerställer stabilitet och flexibilitet för olika produkter.  


## Disposition
1. **Introduktion**  
   - Problemställning och syfte  

2. **Projektbeskrivning**  
   - Litteraturöversikt  

3. **Metoder**  
   - Teknisk implementation  
   - Mekanisk design  

4. **Resultat**  
   - Kylskåpets funktion och prestanda  

5. **Diskussion**  
   - Utvärdering av resultat  
   - Möjliga förbättringar
   - Framtida utvecklingar  

6. **Slutsats**    

---

## Tidtabell
| **Vecka** | **Ämne**                           |
|-----------|------------------------------------|
| 1-2       | Litteratursökning och bakgrund     |
| 1-2       | Design och planering av prototyp   |
| 2-3       | Implementering av sensorer och kod |
| 2-4       | Testning och felsökning            |
| 1-5       | Dokumentation och slutrapportering |

---