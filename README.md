# 5.semester - IoT
Af Jannik Thygesen

## 1.0 Introduktion 

Sideløbende med undervisningen i "EH5IOT-01 Internet of Things" arbejdes der på et IoT projekt. Arbejdet med dette projekt dokumenteres løbende i denne rapport og ved afslutningen af semeseret, så afleveres rapporten via Digital Eksamen på AU. Det er muligt at 

Projeket skal have disse grundlæggende krav opfyldt(fuld liste ses på Brightspace):

- Skal drives af en Particle Argon eller lignende
- Skal være forbundet til internettet og bruge data fra internettet
- Skal være forbundet til lokal enhed, fx sensor eller ligende og bruge data fra lokal enhed
- Skal **samlet** have en bedre funktionalitet end tilsvarende system uden adgang til internettet

## 2.0 Ide- projektbeskrivelse for IoT-projektet
  
Forløbig ide:

Rumstationen ISS flyver konstant rundt om jorden og viser sig ved forskellige geografiske steder på jorden til forskellige tidspunkter. Ønsker man at se ISS med egne øjne, så skal primært to krav være opfyldt: 1. den skal være synlig fra den by du befinder dig i og 2. det skal gerne være mørkt. 

Derfor er ideen, at få data fra ISS Tracking API ned til Particle Argon. Derudover skal der tilkobles en magnetometer til Partile Argon som kan måle retningen du kigger i. På baggrund af de to oplysninger skal det fremgå af konsolen hvorvidt du peger Particle Argon i den rigtige retning for at øge dine chancer for at se rumstationen på himmelen. 




## 3.0 Krav analyse

## 4.0 System design

Grundlæggende opbygning:

For at få data udefra: Der er oprettet et Webhook som er forbundet til ISS tracking API. Fra VSU bruges "particle.subscribe" til at få adgang til dette data og dette skal vises i terminalen.

For at få data lokalt: Magnetometer skal tilkobles og skal give brugeren informationer om hvilken retning Particle peger i. 

Funktionalitet: Den nuværende retning sammen med data om ISS' nuværende position skal give brugeren en ide om, hvorvidt brugeren kan forvente at se ISS rumstationen i den retning. 


## 5.0 Implementering

## 6.0 Test & Verifikation

## Aspekter af Cyber Security

## Aspekter af Machine Learning

## 7.0 Konklusion

## 8.0 Perspektivering og fremtidigt arbejde




## 8.0 Løbende opdateringer

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
