# Chapitre 1 — Exercice 5 : le mal du transport, sans casque

## Protocole

- Vidéo filmée caméra à la main pendant une marche rapide, sans stabilisation.
- Écran ordinaire, en plein écran, regardé de très près.
- Durée : deux minutes, sans pause.
- Trois personnes, dont moi, de sensibilités différentes. Chacune décrit
  son ressenti juste après la vidéo.

## Les trois témoignages

### Témoignage 1 — sujet sensible (inconfort rapide et fort)

*Profil : personne très sensible au mal des transports (voiture, bateau) et à la VR.*

> « Dès la trentième seconde, j'ai ressenti une nette sensation de tournis et un
> début de nausée. Les mouvements brusques de la caméra (les soubresauts à chaque
> pas) et la faible distance avec l'écran m'ont complètement désorienté. J'ai eu
> l'impression que la pièce tanguait autour de moi lorsque j'ai détourné les yeux.
> À la fin des deux minutes, j'avais mal au crâne et une sensation de lourdeur dans
> l'estomac, comme si j'étais passager d'une voiture sur une route sinueuse en
> lisant un livre. »

### Témoignage 2 — sujet modéré (fatigue visuelle, légère gêne)

*Profil : personne qui n'est pas malade, mais qui se fatigue vite.*

> « Je n'ai pas eu de nausée prononcée, mais j'ai rapidement éprouvé une forte
> fatigue visuelle et une tension au niveau des yeux (effort constant pour essayer
> de stabiliser l'image). Vers la fin de la vidéo, une légère sensation de flottement
> et d'étourdissement est apparue. Le fait d'être en plein écran et très près
> amplifiait l'immersion forcée : j'avais le réflexe d'anticiper les mouvements de
> la marche avec mon propre corps. »

### Témoignage 3 — sujet peu sensible (désorientation sans symptôme physique)

*Profil : personne peu sensible, habituée aux jeux vidéo en vue subjective (FPS).*

> « Aucun mal de cœur ni nausée, mais une perception très nette de l'instabilité.
> J'ai trouvé l'exercice désagréable à regarder à cause des vibrations permanentes.
> Mon cerveau a bien compris que je ne bougeais pas, donc je n'ai pas eu de vertige
> profond, mais mes yeux se sont fatigués et j'ai ressenti un soulagement immédiat
> lorsque la vidéo s'est arrêtée. On sent clairement que l'absence de repères fixes
> perturbe la vision périphérique. »

## Analyse

### Le même conflit que dans le casque, pris à l'envers

Le chapitre explique la nausée par un conflit sensoriel : l'oreille interne et la
vue ne disent pas la même chose. Ici, le conflit est inversé :

| | Ce que dit la vue | Ce que dit l'oreille interne |
|---|---|---|
| Vidéo à la main | « je bouge, je marche, je tressaute » | « je suis immobile » |
| Casque en retard | « le monde n'a pas encore bougé » | « ma tête a tourné » |

Dans les deux cas, le cerveau reçoit deux informations contradictoires sur le
mouvement du corps. Le témoignage 2 le montre bien : le corps essaie d'anticiper
des pas qu'il ne fait pas. Le témoignage 3 le dit en une phrase : le cerveau a
compris qu'il ne bougeait pas, mais la vue continuait d'affirmer le contraire.

### Ce qui aggrave le malaise, d'après les témoignages

- **Les mouvements brusques et imprévisibles** (les soubresauts à chaque pas) :
  cités par le témoignage 1, et les vibrations permanentes par le témoignage 3.
- **La taille de l'image dans le champ de vision** : être très près de l'écran, en
  plein écran, est cité par les témoignages 1 et 2. Le témoignage 3 parle de la
  vision périphérique : c'est elle qui donne au cerveau l'impression de mouvement
  du corps.
- **Les effets qui durent après l'arrêt** : pour le témoignage 1, la pièce tanguait
  encore en détournant les yeux, et le mal de tête restait à la fin.

### Pourquoi c'est une « version affaiblie »

Sur un écran, même de près, le bord de l'image laisse voir la pièce immobile : la
vue garde des repères fixes, et une partie d'elle-même donne raison à l'oreille
interne. L'image ne dépend pas non plus des mouvements de la tête : en tournant la
tête, on retrouve le monde réel.

Dans un casque, ces deux échappatoires disparaissent. L'image occupe tout le champ
de vision, y compris la périphérie, et il n'y a plus aucun repère fixe réel. La même
cause produira donc des effets plus forts et plus rapides que ceux décrits ici.

### Ce que cela dit pour le travail à venir

1. **La sensibilité varie énormément d'une personne à l'autre.** Les trois sujets ont
   vu la même vidéo, sur le même écran, pendant le même temps : l'un a eu la nausée,
   l'autre une simple fatigue, le troisième seulement une gêne. Comme l'écart entre
   les pupilles à l'exercice 3, il n'existe pas d'utilisateur moyen.
2. **Le développeur est le pire testeur.** Le sujet 3, habitué aux jeux en vue
   subjective, est le moins touché. Un développeur qui teste son application chaque
   jour s'habitue de la même manière, et il sous-estimera le malaise des autres. D'où
   la méthode du chapitre : faire essayer à quelqu'un d'autre, et écouter.
3. **Ne jamais bouger la caméra sans que l'utilisateur bouge.** Les secousses de
   la marche, ajoutées artificiellement à une caméra en VR (balancement de la tête,
   tremblement), reproduiraient exactement cette vidéo. Dans un casque, seule la tête
   réelle doit déplacer le point de vue.
4. **Une mauvaise image ne s'efface pas.** Les symptômes du témoignage 1 continuent
   après l'arrêt. C'est pourquoi le chapitre juge une expérience à sa pire image, et
   non à sa moyenne : le corps garde la trace des ratés.
