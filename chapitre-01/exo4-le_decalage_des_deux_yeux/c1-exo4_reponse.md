# Chapitre 1 — Exercice 4 : le décalage des deux yeux

## Protocole

- Mur du fond situé à **5 m** de mes yeux.
- Doigt tenu à 30 cm, puis 1 m, puis 3 m (à 1 m et 3 m, un objet fin tenu par
  quelqu'un d'autre ou posé sur un support remplace le doigt).
- En fermant alternativement l'œil gauche et l'œil droit, je repère sur le mur les
  deux points que le doigt masque, et je mesure la distance entre ces deux points.

## Les trois mesures

| Distance du doigt | Déplacement apparent sur le mur (mesuré) |
|------------------:|-----------------------------------------:|
| 0,30 m | **1,02 m** |
| 1 m    | **26 cm** |
| 3 m    | **4,3 cm** |

## Vérification par le calcul

Les deux yeux, séparés de l'écart `e`, voient le doigt (à la distance `d`) dans deux
directions différentes. Prolongées jusqu'au mur (à la distance `D`), ces deux
directions donnent deux points séparés de :

    déplacement = e × (D − d) / d

Avec mon écart entre les pupilles mesuré à l'exercice 3 (e = 63 mm) et D = 5 m :

| d | Prévu | Mesuré | Écart |
|--:|------:|-------:|------:|
| 0,30 m | 0,063 × 4,7 / 0,3 = **0,99 m** | 1,02 m | +3 % |
| 1 m    | 0,063 × 4 / 1 = **25,2 cm** | 26 cm | +3 % |
| 3 m    | 0,063 × 2 / 3 = **4,2 cm** | 4,3 cm | +2 % |

Les mesures suivent le modèle à quelques pour cent près. En retournant la formule,
elles donnent même mon écart entre les pupilles : 65,1 mm, 65,0 mm et 64,5 mm, soit
environ **65 mm**, contre 63 mm mesurés à la règle. Les deux méthodes concordent à
2 mm près, ce qui est l'ordre de grandeur de l'incertitude de la règle.

## Ce que les mesures disent

Le décalage entre les deux yeux ne varie pas linéairement avec la distance : il varie
**comme l'inverse de la distance**. En angle (disparité), il vaut à peu près `e / d` :

| d | Disparité angulaire |
|--:|--------------------:|
| 0,30 m | 0,21 rad ≈ **12°** |
| 1 m    | 0,063 rad ≈ **3,6°** |
| 3 m    | 0,021 rad ≈ **1,2°** |

De 30 cm à 3 m, la distance est multipliée par 10, et le décalage divisé par 10.
C'est ce décalage, et lui seul, que le cerveau lit comme du relief : fort de près,
presque nul au loin.

## Ce que cela annonce du travail du chapitre 9

Le travail sur le rendu des deux yeux devra en tirer quatre conséquences.

1. **Deux points de vue, décalés d'exactement l'écart de l'utilisateur.** Chaque œil
   reçoit sa propre matrice de vue, obtenue en décalant la pose de la tête de
   −e/2 et +e/2 le long de son axe x, puis en inversant. C'est ce décalage qui produit
   la disparité mesurée ici.
2. **L'écart doit être celui de l'utilisateur, pas une constante.** Une erreur sur `e`
   change toutes les disparités dans la même proportion. Le cerveau l'interprète comme
   un changement d'échelle du monde, pas comme une faute visible : c'est la catégorie
   de défaut du chapitre 1, qui ne plante pas et se ressent.
3. **La précision compte surtout de près.** À portée de main (0,6 à 0,75 m), la
   disparité est de plusieurs degrés : une erreur d'écart ou de projection s'y voit
   tout de suite. C'est là que se trouvent les mains, les objets qu'on saisit, les
   interfaces : c'est là qu'il faut être juste.
4. **Au loin, les deux images deviennent presque identiques.** À 3 m, il ne reste
   qu'un degré ; à quelques dizaines de mètres, la disparité devient de l'ordre d'un
   pixel du casque. Les deux rendus doivent quand même être faits, mais cela annonce
   les optimisations possibles (partager entre les deux yeux ce qui est très loin, comme
   un ciel), et cela confirme que tout ce qui ne dépend pas du point de vue (logique,
   physique, chargement) ne se double pas.
