# Chapitre 1 — Exercice 7 : le coût du doublement

## Le programme

Le même programme qu'à l'exercice 6 (fichier `mesure-cout-doublement.html`) : il ne
fait qu'effacer l'écran, il n'a **aucune logique**. Tout le temps mesuré est donc du
rendu.

Deux changements par rapport à l'exercice 6 :

- le chronomètre ne s'arrête qu'une fois le rendu **réellement terminé** : le
  programme relit un pixel, ce qui oblige le navigateur à finir le travail graphique
  en attente ;
- une seconde phase de 1000 images fait le rendu **deux fois par image** (un
  effacement par œil), pour comparer l'estimation à une mesure réelle.

Conditions : Chrome 155 sous Windows 10, cible de 723 × 1580 pixels.

## 1. La mesure : le rendu seul (un œil)

| 1000 images | Durée |
|---|---:|
| Médiane | **7,2 ms** |
| Moyenne | 7,39 ms |
| 99e centile | 12,1 ms |
| **Pire image** | **22,7 ms** |

## 2. L'estimation : le rendu fait deux fois

En supposant que le coût double avec le nombre d'yeux :

| | Un œil (mesuré) | Deux yeux (estimé : × 2) |
|---|---:|---:|
| Médiane | 7,2 ms | **14,4 ms** |
| 99e centile | 12,1 ms | **24,2 ms** |
| Pire image | 22,7 ms | **45,4 ms** |

## 3. Ce qu'il resterait pour le reste

Budgets disponibles pour tout notre code, calculés à l'exercice 1 :
5,9 ms à 72 Hz, 3,1 ms à 90 Hz, 0,3 ms à 120 Hz.

Reste = budget − rendu doublé estimé (médiane 14,4 ms) :

| Cadence | Budget du code | Rendu doublé (estimé) | **Reste** |
|---|---:|---:|---:|
| 72 Hz | 5,9 ms | 14,4 ms | **− 8,5 ms** |
| 90 Hz | 3,1 ms | 14,4 ms | **− 11,3 ms** |
| 120 Hz | 0,3 ms | 14,4 ms | **− 14,1 ms** |

Le reste est **négatif à toutes les cadences**, avant même d'avoir écrit une ligne de
logique. Et ce calcul porte sur la médiane : on juge une expérience en casque à sa
pire image, où l'estimation atteint 45,4 ms, soit plus de quatre échéances à 90 Hz.
En fait, même le rendu **d'un seul œil** (7,2 ms) ne tient déjà dans aucun de ces
budgets.

## 4. La vérification : le doublement mesuré

La seconde phase a réellement rendu deux fois par image :

| | Un œil (mesuré) | Deux yeux (mesuré) | Estimation × 2 |
|---|---:|---:|---:|
| Médiane | 7,2 ms | **7,0 ms** | 14,4 ms |
| 99e centile | 12,1 ms | **11,5 ms** | 24,2 ms |
| Pire image | 22,7 ms | **12,7 ms** | 45,4 ms |

**L'estimation était fausse.** Faire le rendu deux fois n'a presque rien coûté : le
rapport des médianes est de 0,97, pas de 2. Le reste mesuré est quand même négatif
(7,0 ms contre 5,9, 3,1 et 0,3 ms), mais de beaucoup moins.

Cela veut dire que les 7 ms mesurées ne sont **pas le coût d'un effacement**.
L'effacement lui-même est presque gratuit : le temps passe ailleurs, dans un coût
**fixe par image**, payé une seule fois que l'on dessine un œil ou deux. Ici, ce coût
fixe est surtout l'**attente de synchronisation** : relire un pixel bloque le
programme jusqu'à ce que le processeur graphique ait tout terminé, et cette attente
domine tout le reste.

Deux autres observations confirment l'exercice 6 :

- **la pire image d'un seul œil (22,7 ms) est pire que celle de deux yeux (12,7 ms)** :
  la pire image ne dépend pas du travail fait, elle dépend de l'environnement
  (navigateur, ramasse-miettes, système) ;
- les durées sont arrondies au dixième de milliseconde, parce que Chrome réduit
  volontairement la précision de son horloge. Les écarts plus fins ne sont pas
  mesurables avec cet outil.

## 5. Conclusion : ce qu'il faudrait réduire

L'estimation naïve (« deux yeux, deux fois plus cher ») aurait conduit à réduire le
travail par œil. La mesure montre que ce n'est pas le bon levier ici : il faut d'abord
réduire **ce que l'on paie une fois par image**, puis seulement le travail par œil.

1. **Supprimer les attentes bloquantes.** Ne jamais faire attendre la boucle de rendu
   que le processeur graphique ait fini : c'est exactement le « fil qu'on ne bloque
   jamais » du chapitre 1. Pour mesurer le temps du processeur graphique, utiliser
   ses propres horloges (requêtes de minutage GPU) au lieu d'une lecture qui bloque.
2. **Partager le coût fixe entre les deux yeux.** Puisque l'essentiel du coût est
   fixe, il faut dessiner les deux yeux dans une seule passe (rendu stéréo en une
   passe, cibles côte à côte) plutôt qu'en deux passes séparées qui le paieraient
   chacune.
3. **Sortir de l'environnement non maîtrisé.** Un navigateur et son ramasse-miettes
   volent des images au hasard (22,7 ms pour un simple effacement). Une application
   en casque doit tourner dans une boucle native, cadencée par le runtime du casque,
   sans allocation pendant l'image.
4. **Ensuite seulement, réduire le travail par œil** : résolution des cibles de rendu
   et quantité de choses dessinées. Ce sera le vrai poste de dépense dès que la scène
   ne sera plus un simple effacement, et c'est lui qui doublera vraiment.
5. **Ne rien doubler d'autre.** La logique, la physique et le chargement, absents
   ici, devront tenir dans ce qui reste après le rendu : c'est la marge de manœuvre
   du chapitre.

La leçon principale rejoint le chapitre 1 : **il faut mesurer, pas supposer.** Le
doublement est réel pour le travail par œil, mais sur ce programme il était caché
derrière un coût fixe que seule la mesure a révélé.
