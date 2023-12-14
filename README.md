# 5.semester - IoT
Af Jannik Thygesen, studienummer 

## 1.0 Introduktion 

Sideløbende med undervisningen i "EH5IOT-01 Internet of Things" arbejdes der på et IoT-projekt. Arbejdet med dette projekt dokumenteres løbende i denne rapport og ved afslutningen af semeseret, så afleveres rapporten via Digital Eksamen. 

Projeket skal have disse grundlæggende krav opfyldt(fuld liste ses på Brightspace, Exam Project):

- Krav 1: Skal drives af en Particle Argon eller lignende 
- Krav 2: være forbundet til internettet og bruge data fra internettet
- Krav 3: Skal være forbundet til lokal enhed, fx sensor eller ligende og bruge data fra lokal enhed
- Krav 4: Systemet Skal **samlet** have en bedre funktionalitet end tilsvarende system uden adgang til internettet

## 2.0 Ide- projektbeskrivelse for IoT-projektet
  
Forløbig ide:

Rumstationen ISS flyver konstant rundt om jorden og viser sig ved forskellige geografiske steder på jorden til forskellige tidspunkter. Ønsker man at se ISS med egne øjne, så skal primært to krav være opfyldt: 1. den skal være synlig fra den by du befinder dig i og 2. det skal gerne være mørkt. 

Derfor er ideen, at få data fra ISS Tracking API ned til Particle Argon. Derudover skal der tilkobles en magnetometer til Partile Argon som kan måle retningen du kigger i. På baggrund af de to oplysninger skal det fremgå af konsolen hvorvidt du peger Particle Argon i den rigtige retning for at øge dine chancer for at se rumstationen på himmelen. 


## 3.0 Krav analyse

- Krav 1:
  Projektet drives af en Particle Argon. Denne udleveret af underviser. Der er desuden indkøbt en Particle Photon 2 som backup og til udvikling i fremtiden.
  
- Krav 2:
  Fra Particle Console oprettes et Webhook der peger på en webpage med positionsoplysninger for ISS som API data. Da API-linket returnerer flere oplysninger end der skal bruges i dette projekt, så er der lavet en sortering af disse under "Advanced Setting".

- Krav 3:
  Der er valgt et HMC5883 magnetometer til dette projektet. Denne lokale sensor måler magnetisk styrke i et X-Y-Z-plan, og resultatet af dette kan bruges til beregningen af retningen sensoren vender.

- Krav 4:
  Ved at sammenkoble ovenstående tre krav, så opfylder systemet kravene til projektet ved at indeholde internetdata samt lokal data og derudover, at virke bedre end ikke at være forbundet til internettet. I dette projekt ses det ved at give oplysninger om placeringen af rumstationen ISS. Uden disse oplysninger ville det være umuligt for brugeren at vide hvilken retning der skulle kigges i. 

## 4.0 System design

Grundlæggende er 

For at få data udefra: Der er oprettet et Webhook som er forbundet til ISS tracking API. Fra VSU bruges "particle.subscribe" til at få adgang til dette data og dette skal vises i terminalen.

For at få data lokalt: Magnetometer skal tilkobles og skal give brugeren informationer om hvilken retning Particle peger i. 

Funktionalitet: Den nuværende retning sammen med data om ISS' nuværende position skal give brugeren en ide om, hvorvidt brugeren kan forvente at se ISS rumstationen i den retning. 
Latitude = Breddegrad. Angiver en position nord for ækvator 

## 5.0 Implementering

For at få indarbejdet de opstillede krav til opgaven, så arbejdes der primært med disse én ad gangen. Dette sikre større overblik og kontrol over de enkelte funktioner, men gør det også nemmere for projektet, da der løbende kan bygges ovenpå eksisterende løsninger efterhånden som de kan verfificeres. 

- Vedr. krav 1:\
  Particle Argon forbundes med USB-kabel til computeren og herefter oprettes forbindelse til lokalt Wi-Fi netværk. Der oprettes en konto på "Particle Console" som giver mulighed for at overvåge aktiviteten    for ens device, oprette og redigere Webhooks, følge med i events samt meget andet. \
  Som IDE installeres Microsofts Visual Studio Code(herefter VSC) og der installeres udvidelsespakken "Particle Workbench" som giver mulighed for at interagere med Particle Argon direkte fra VSC, herunder     at opdatere firmware, installere 3. parts biblioteker, compile kode og flashe denne direkte.\

- Vedr. krav 2:\
  Der oprettes et Webhook kaldet "ISS Tracking" med et event kaldet "Tracking". Da der skal importeres data ind til Particle Argon, så angives request type som "Get" og der angives følgende link som kilde 
  til positionsoplysninger for ISS:\
  
  https://api.wheretheiss.at/v1/satellites/25544
  
  Under Advanced Settings angives følgende parametre til Response Template:\

  Latitude: {{latitude}},\
  Longitude: {{longitude}},\
  Visibility: {{visibility}},

Dette gøres, da API-linket returnerer en del informationer som ikke er relevante for dette projekt, f.eks. hastigheden, timestamps og position ifht. solen, så bruges ovenstående til at kun lade de relevante data passere til koden når eventet "tracking" bliver kaldt. 

  -Vedr. Krav 3:\
Der indkøbes en [HMC5883 sensor fra Arduinotech](https://arduinotech.dk/shop/3-axis-electronic-compass-magnetometer-sensor-module/) til brug i dette projekt. Denne er valgt, da den opfylder de basale krav om at kunne måle magnetisk kraft i X, Y og Z retning, den kan drives med 3.3V direkte fra Particle Argon samtidigt med, der var umiddelbart understøttelse af denne sensor gennem [Particle Liberaies HMC5883](https://docs.particle.io/reference/device-os/libraries/a/Adafruit_HMC5883/). 

Det lykkedes dog ikke at få denne firmware til køre på Particle Argon - formentligt grundet for store versionsforskelle mellem denne oprindelige firmware også de nyere der er tilgængelige. Der forsøges at bruge ældre firmware til Particle Argon, men uden held. Derfor importeres og bruges [følgende kode fra ControlEverything]( https://github.com/ControlEverythingCommunity/HMC5883/blob/master/Particle/HMC5883.ino). 


  

  

  

  
   

  
  
  
  
## 6.0 Test & Verifikation

## Aspekter af Cyber Security

## Aspekter af Machine Learning

## 7.0 Konklusion

## 8.0 Perspektivering og fremtidigt arbejde




## 9.0 Løbende opdateringer

*14/12/2023*

Sammenlagt to koder der hhv. arbejder med API data og Sensor data til én samlet kode(IoT_Merged) sammen med eksempel på output(IoT_Merged_OUTPUT).

*14/12/2023*

Kode der aflæser lokal sensor og laver publish til til events, er nu lagt online(HMC5883) sammen med eksempel på output(HMC5883_OUTPUT).

*4/12/2023*

Kode der modtager API data og printer dette til console samt laver publish til events, er nu lagt online(API_data) sammen med eksempel på output(API_data_OUTPUT). 
Fortsat en udfordring at få brug JsonParser til at scanne for data og placere i variabler som der kan laves beregninger på. 

*19/11/2023*

Større opdatering på Github af projektet. 

*Oktober 2023*

Der arbejdes med at få data fra tracking API vist lokalt i terminal på Visual Studio Code(VSC). Der er oprettet et Webhook som modtager data fra API og bagefter bruges "particle.subscribe" til at få adgang til dette data. Der er dog store udfordringer med at få vist dette data i .json format i terminalen på VSC.


*5/10/23*

Udskiftet lokal sensor til magnetometer for at kunne give brugeren muligheden for at vide, hvorvidt han kigger den rigtige retning efter ISS rumstationen. Den oprindelige ide med LED-status for optimale tidspunkter at kigge efter ISS rumstationen kan evt. bruges i projektet senere hen, hvor man i stedet for konsollen kan kigge på en LED og se om man kigger det rigtige sted hen. Projektet ideen herover er opdateret med denne nye tilgang.  

Status for LED kunne f.eks. være:

F.eks. kan det tænkes, at følgende statusser kan implementeres: 

- Rød LED: Du kigger den forkerte retning
- Gul LED: Du er tæt på/indenfor XX antal grader 
- Grøn LED: Du peger direkte mod ISS rumstationen.

Interressante links:

- https://spotthestation.nasa.gov/tracking_map.cfm     Som er NASAs tracking i webform med angivelse af position +/- 90 minutter (som er tiden ISS bruger på en omgang omkring jorden)
- https://wheretheiss.at/                              Som giver løbende tracking data

*14/9/23*

Ideen er som udgangspunkt godkendt. Forslag til udbyggelse: magnetometer+accelerometer som kan tilkobles projektet og via LED lys give en indikation om man kigger i den rigtige retning. 
