# 5.semester-IoT
Ide- projektbeskrivelse for IoT-projektet


Projeket skal have følgende krav opfyldt:

- Skal drives af en Particle Argon eller lignende
- Skal være forbundet til internettet og bruge data fra internettet
- Skal være forbundet til lokal enhed, fx sensor eller ligende og bruge data fra lokal enhed

  
Forløbig ide:

Rumstationen ISS flyver konstant rundt om jorden og viser sig ved forskellige geografiske steder på jorden til forskellige tidspunkter. Ønsker man at se ISS med egne øjne, så skal primært to krav være opfyldt: 1. den skal være synlig fra den by du befinder dig i og 2. det skal gerne være mørkt. 

Derfor er ideen, at få data fra ISS Tracking API ned til Particle Argon. Derudover skal der tilkobles en lyssensor til Partile Argon som kan måle om det er mørkt eller lyst. På baggrund af de to oplysninger skal en LED indikere om det på nuværende tidspunkt er en god ide at gå og kigge efter ISS rumstationen. 

F.eks. kan det tænkes, at følgende statusser kan implementeres: 

- Rød LED: Rumstationen er ikke i nærheden af din by
- Gul LED: Rumstationen er i nærheden af din by, men det er lyst
- Grøn LED: Rumstationen er i nærheden af din by og det er mørkt.


Løbende opdateringer


Opdatering 14/9/23

Ideen er som udgangspunkt godkendt. Forslag til udbyggelse: magnetometer+accelerometer som kan tilkobles projektet og via LED lys give en indikation om man kigger i den rigtige retning. 


Interressante links:

https://spotthestation.nasa.gov/tracking_map.cfm     Som er NASAs tracking i webform med angivelse af position +/- 90 minutter (som er tiden ISS bruger på en omgang omkring jorden)
https://wheretheiss.at/                              Som er et Tracking API
