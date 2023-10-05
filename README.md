# 5.semester-IoT
Ide- projektbeskrivelse for IoT-projektet


Projeket skal have følgende krav opfyldt:

- Skal drives af en Particle Argon eller lignende
- Skal være forbundet til internettet og bruge data fra internettet
- Skal være forbundet til lokal enhed, fx sensor eller ligende og bruge data fra lokal enhed

  
Forløbig ide:

Rumstationen ISS flyver konstant rundt om jorden og viser sig ved forskellige geografiske steder på jorden til forskellige tidspunkter. Ønsker man at se ISS med egne øjne, så skal primært to krav være opfyldt: 1. den skal være synlig fra den by du befinder dig i og 2. det skal gerne være mørkt. 

Derfor er ideen, at få data fra ISS Tracking API ned til Particle Argon. Derudover skal der tilkobles en magnetometer til Partile Argon som kan måle retningen du kigger i. På baggrund af de to oplysninger skal det fremgå af konsolen hvorvidt du peger Particle Argon i den rigtige retning for at øge dine chancer for at se rumstationen på himmelen. 

F.eks. kan det tænkes, at følgende statusser kan implementeres: 

- Rød LED: Rumstationen er ikke i nærheden af din by
- Gul LED: Rumstationen er i nærheden af din by, men det er lyst
- Grøn LED: Rumstationen er i nærheden af din by og det er mørkt.


Løbende opdateringer


Opdatering 14/9/23

Ideen er som udgangspunkt godkendt. Forslag til udbyggelse: magnetometer+accelerometer som kan tilkobles projektet og via LED lys give en indikation om man kigger i den rigtige retning. 


Opdatering 5/10/23

Udskiftet lokal sensor til magnetometer for at kunne give brugeren muligheden for at vide, hvorvidt han kigger den rigtige retning efter ISS rumstationen. Den oprindelige ide med LED-status for optimale tidspunkter at kigge efter ISS rumstationen kan evt. bruges i projektet senere hen, hvor man i stedet for konsollen kan kigge på en LED og se om man kigger det rigtige sted hen. Projektet ideen herover er opdateret med denne nye tilgang.  


Interressante links:

https://spotthestation.nasa.gov/tracking_map.cfm     Som er NASAs tracking i webform med angivelse af position +/- 90 minutter (som er tiden ISS bruger på en omgang omkring jorden)
https://wheretheiss.at/                              Som giver løbende tracking data
