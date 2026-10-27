# Chapitre 1 — Exercice 1 : les trois cadences

## Méthode

La durée d'une image est l'inverse de la fréquence :

    durée (ms) = 1000 / fréquence (Hz)

On retire ensuite les **8 ms** fixes prises par les capteurs, la transmission,
la composition et l'affichage. Ce qui reste est le temps dont dispose notre code
pour décider et dessiner (les deux yeux compris).

Les calculs sont faits sur la valeur exacte, puis arrondis au dixième de milliseconde.

## Résultats

| Cadence | Durée d'une image        | Part fixe | **Reste pour notre code** |
|--------:|--------------------------|----------:|--------------------------:|
| 72 Hz   | 1000 / 72  = 13,888… ≈ **13,9 ms** | 8 ms | **5,9 ms** |
| 90 Hz   | 1000 / 90  = 11,111… ≈ **11,1 ms** | 8 ms | **3,1 ms** |
| 120 Hz  | 1000 / 120 =  8,333… ≈  **8,3 ms** | 8 ms | **0,3 ms** |

**Les trois nombres : 5,9 ms, 3,1 ms et 0,3 ms.**

## Ce que ces nombres disent

- Le budget de notre code ne diminue pas proportionnellement à la cadence :
  passer de 72 à 120 Hz divise la durée d'une image par 1,7, mais divise
  le temps restant par presque **20** (5,9 → 0,3 ms), parce que les 8 ms fixes
  ne bougent pas.
- À 120 Hz, 0,3 ms ne suffit pas à rendre une scène deux fois. C'est ce qui
  rend indispensables la prédiction et le travail en parallèle (préparer
  l'image suivante pendant que la précédente s'affiche) plutôt qu'un calcul
  strictement séquentiel dans l'image.
- Ces budgets sont des **échéances**, pas des moyennes : ils doivent être tenus
  à chaque image, car on juge une expérience en casque à sa pire image.
