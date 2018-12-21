Introduction
Le but de ce projet sera de simuler la première partie d'un vol spatial aller-retour. Nous nous baserons sur la structure d'une fusée Soyuz. Une telle fusée est composée de 3 étages:

Un premier étage composé de 4 boosters, qui vont s'allumer au décollage et brûleront pendant ~2 minutes avant d'être détachés.
Un second étage composé d'un moteur central s'allumant en même temps que les boosters, mais pouvant brûler pendant ~5 minutes.
Un troisième étage composé également d'un moteur central, mais ne pouvant s'allumer qu'une fois les étages inférieurs détachés.

Enfin, cette fusée sera dotée d'une capsule Soyuz qui pourra s'arrimer à l'ISS, avant de redescendre sur Terre.

Ingrédients du modèle
Dans ce modèle simplifié, nous considérerons les aspects suivants :

Bien que la poussée des moteurs sera considérée comme constante, l'accélération engendrée dépendant de la masse ne sera pas constante.
Nous approximons la Terre comme un astre à symétrie sphérique, mais nous ne négligeons pas le fait qu'elle tourne sur elle-même. La fusée décolle à Kourou (5°14'9.60" N -52°46'30.00" W).
On considère la pression atmosphérique comme exponentiellement décroissante. Sa valeur peut être trouvée ici.
Les forces de frottements de l'air pour un élément de fusée iii sont donnés par Fi=12ρv2CiF_{i} = \frac{1}{2} \rho v^2 C_{i}Fi​=21​ρv2Ci​. On considère également que l'on peut additionner les frottements de telle manière à ce que la force totale soit donnée par Ftot=∑iFiF_{tot} = \sum_i F_{i}Ftot​=∑i​Fi​.

Des valeurs numériques réalistes vous seront communiquées par la suite.

Instructions du projet

À partir de ces données, simulez le lancement d'une fusée.
En considérant qu'on atteint l'apogée de notre trajectoire lorsque r˙=0\dot{r} = 0r˙=0 (attention, ça ne veut pas dire que v⃗=0⃗\vec{v} = \vec{0}v=0) et que seuls les deux premiers étages sont nécessaires pour ceci, déterminez la quantité de carburant nécessaire en fonction de l'apogée et de la masse du 3e étage + capsule.
Pour être en orbite circulaire, il faut une vitesse de vR=GMrv_R = \sqrt{\frac{GM}{r}}vR​=rGM​​, déterminez la quantité de carburant nécessaire au 3e étage pour y parvenir.
Pour chaque étape, enregistrez les informations nécessaire sur disque à l'aide du format de données de votre choix.
# ProjetIA
