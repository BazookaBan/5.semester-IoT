## Løbende opdateringer for IoT-projektet
*17/12/2023*

Der skrives på rapporten.

*15/12/2023*

Der skrives på rapporten og der produceres indhold, billeder, grafer osv. 

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
