# Kravspecifikation för en smart kylskåpslösning för försäljning av läskedryck

Denna kravspecifikation kombinerar funktionella och icke-funktionella krav för att säkerställa en smart och flexibel lösning för kylskåp med inventarieövervakning. Fokus ligger på användarvänlighet, teknisk funktionalitet och kostnadseffektivitet, med tydlig dokumentation för både utvecklare och användare.

## Funktionella krav

### Inventarieövervakning
 
- Sensorer (ultraljud) monterade för att upptäcka när en produkt tas bort.
- Identifiera vilken produkt som tas och hur många.
- Data skickas till server eller mobilapp via Bluetooth eller WiFi.
- Logga alla händelser med tidsstämpel och produktinformation.
 
### Gränssnitt för användning och hantering

- Möjlighet att ange ett “hanteringsläge” för påfyllning av produkter.
- Notifieringar vid låg inventarie.
- Larm vid obetald produkt (valbart om betalning kopplas till systemet).
- Display som visar produkter och priser (om möjligt).
- Alternativ: Laminerat papper med produkter och priser som backup.
 
### Produktfunktionalitet

- Produkter hålls på plats i “gravity-based autoloader” utan att falla av.
- Möjlighet att justera för olika produktstorlekar (exempel: läskflaskor och smörgåsar).
	
### Temperaturövervakning

- Monitorering av kylskåpstemperatur för att säkerställa produktkvalitet.

## Icke-funktionella krav

	
### Mekanisk design

- Dokumentation och 3D-modeller för den mekaniska lösningen, exempelvis komponenter för 3D-utskrift.
- Robust design för att hantera upp till 10 läskflaskor eller andra produkter av liknande storlek.

### Strömhantering

- Övervakning av energiförbrukning.
- Specifikation av batterilivslängd (exempel: hur länge räcker en 20Ah powerbank?).

### Kommunikationslösning

- Trådlös implementation för att undvika kablar genom kylskåpsdörren.

### Dokumentation

- Utförlig utvecklardokumentation (Wiki).
- Användarmanual för installation, drift och underhåll.

### Säkerhet och riskhantering

- Grundläggande autentisering för hanteringsläge.
- Enkel riskbedömning och åtgärder för att minska bedrägerier.
- Observera att produkternas värde är lågt – lösningen ska vara kostnadseffektiv.

## Övriga överväganden

- Är kylskåpet avsett för enbart läskedryck, eller ska även andra produkter som snacks inkluderas?
- Exempel: Hur skiljer sig kraven för förpackningar som smörgåsar jämfört med läskflaskor?
- Designen bör gärna kunna skalas eller anpassas efter framtida behov, exempelvis olika typer av sensorer eller produktstorlekar.


