# Chapitre 1 — Exercice 3 : six centimètres et demi

## Méthode de mesure (règle et miroir)

Chaque personne a mesuré son propre écart, de la même manière :

1. Se placer face à un miroir, à environ 20 cm, en bonne lumière.
2. Poser une règle graduée en millimètres à plat sur l'arête du nez, sous les yeux.
3. **Fermer l'œil droit** et, avec l'œil gauche ouvert, aligner le zéro de la règle
   sur le centre de la pupille gauche.
4. Sans bouger la tête ni la règle, **fermer l'œil gauche, ouvrir le droit**, et lire
   la graduation au centre de la pupille droite.

On ferme un œil à la fois pour que chaque œil regarde droit devant lui pendant
sa lecture ; avec les deux yeux ouverts, ils convergent vers le reflet et l'écart
lu est trop petit.

## Les six valeurs

| # | Personne   | Écart entre les pupilles (mm) |
|---|------------|------------------------------:|
| 1 | Moi        | 63 |
| 2 | Personne A | 63 |
| 3 | Personne B | 54 |
| 4 | Personne C | 74 |
| 5 | Personne D | 60 |
| 6 | Personne E | 75 |

## Résultats

- **Moyenne** : (63 + 63 + 54 + 74 + 60 + 75) / 6 = 389 / 6 = **64,8 mm**
- **Plus petite valeur** : 54 mm
- **Plus grande valeur** : 75 mm
- **Écart entre la plus petite et la plus grande** : 75 − 54 = **21 mm**

Pour compléter : la médiane vaut 63 mm, et l'écart-type de l'échantillon environ 8,2 mm.

## Comparaison avec la valeur du chapitre

Le chapitre donne **65 mm** en moyenne, avec une plage réelle d'environ 55 à 70 mm.

**La moyenne colle presque exactement** : 64,8 mm contre 65 mm, soit 0,2 mm d'écart.
Ma propre valeur (63 mm) est proche de la moyenne, elle aussi.

**Mais aucune personne n'est « la moyenne ».** Une seule valeur sur six se trouve à
moins de 2 mm de 65 mm (à condition d'arrondir généreusement : 63 mm). Et trois
valeurs sur six sortent de la plage indiquée par le chapitre : 54 mm sous la borne
basse, 74 et 75 mm au-dessus de la borne haute. L'écart entre les extrêmes (21 mm)
dépasse même la largeur de la plage du chapitre (15 mm).

Deux explications possibles, que je ne peux pas départager avec ces mesures :

- **une vraie dispersion** : le chapitre donne une plage indicative ; des valeurs
  un peu en dehors existent chez des adultes ;
- **une erreur de mesure** : une règle lue sur un reflet donne environ ± 2 mm,
  davantage si la tête ou la règle bouge entre les deux lectures. Les deux valeurs
  les plus hautes (74 et 75 mm) mériteraient d'être refaites, idéalement par une
  autre personne ou avec un pupillomètre d'opticien.

## Ce que cela dit pour la réalité virtuelle

C'est l'exemple annoncé par le chapitre : si l'application utilise 65 mm pour tout
le monde, elle se trompe de 11 mm pour la personne B (54 mm) et de 10 mm pour la
personne E (75 mm), soit environ 20 % et 13 %.

L'erreur ne fait rien planter, elle se ressent :

- pour la personne B, l'écart rendu est **plus grand** que le sien : le monde lui
  paraît **plus petit**, comme une maquette ;
- pour la personne E, l'écart rendu est **plus petit** que le sien : le monde lui
  paraît **plus grand**, et elle se sent rapetissée.

Conclusion : l'écart entre les pupilles ne doit pas être une constante du programme,
mais une valeur lue (réglage du casque ou du runtime) pour chaque utilisateur. La
moyenne de 65 mm n'est qu'une valeur par défaut, juste en moyenne et fausse pour
presque chacun.
