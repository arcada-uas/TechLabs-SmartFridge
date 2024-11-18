# Smart fridge inventory monitor  
Introducerade killarna till kylskåpet och gav dem 2 ESP8266 + 3 RPi0 + 4 Ultraljudssensorer + RPi4 med tillbehör  
KIllarna förstod utmaningen, också avgränsningen.  
	Fokus är inte kylskåpssäkerhet, inte heller user interface design, inte heller lähimaksubetalningsintegration  
Målet är att implementera en lösning där RPi0 kopplas till en ultraljudssensor per produkt.  
Vi efterlyser alltså en lösning för monitorering av inventarie.   
  
## Requirements  
*In order of importance:*  
Stop inventory from falling off the slanted shelves (the "gravity based autoloader")  
	3D models and basic documentation of mechanical implementation (3d print?)  
	Rough spec, can it take 10 soda bottles? How about kolmioleipäs?  
Product specifications for the smart fridge  
	Are we planning to serve only sodas, how different is the challenge for certain food or snacks?  
Sensors and microcontrollers mounted in fridge.  
Sensors notice when product is removed.  
What product was removed and how many.  
Data is sent to a server or a phone (BT or Wifi)  
	Wireless implementation to avoid cables through fridge door  
Log with timestamp and products  
Great documentation, both developer and user docs (Wiki)  
Possibility to enter management mode for refill  
	Some type of authentication  
Notify when inventory is running low  
Alarm when "payment" is not done  
Laminated piece of paper with products and prices  
	If possible: display that shows producs and prices   
Power management/monitoring  
	How long does one 20Ah powerbank last?  
A simple risk assessment and eventual anti-scammer improvements  
	Remember we are not police, inventory is not that valuable...  
Temperature monitoring 
