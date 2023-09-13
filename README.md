# 5.semester-IoT
Ide- projektbeskrivelse for IoT-projektet


Projeket skal have følgende krav opfyldt:

- Skal drives af en Particle Argon eller lignende
- Skal være forbundet til internettet og bruge data fra internettet
- Skal være forbundet til lokal enhed, fx sensor eller ligende og bruge data fra lokal enhed

  
Forløbig ide:

Rumstationen ISS flyver konstant rundt om jorden og viser sig ved forskellige geografiske steder på jorden til forskellige tidspunkter. Ønsker man at se ISS med egne øjne, så skal primært to krav være opfyldt: 1. den skal være synlig fra den by du befinder dig i og 2. det skal gerne være mørkt. 

Derfor er ideen, at få data fra ISS Tracking API ned til Particle Argon. Derudover skal der tilkobles en lyssensor til Partile Argon som kan måle om det er mørkt eller lyst. PÅ baggrund af de to oplysninger skal en LED indikere om det på nuværende tidspunkt er en god ide at gå og kigge efter ISS rumstationen. 

F.eks. kan det tænkes, at følgende status kan implementeres: 

- Rød LED: Rumstationen er ikke i nærheden af din by
- Gul LED: Rumstationen er i nærheden af din by, men det er lyst
- Grøn LED: Rumstationen er i nærheden af din by og det er mørkt. 
