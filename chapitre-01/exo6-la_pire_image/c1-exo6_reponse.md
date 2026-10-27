# Chapitre 1 — Exercice 6 : la pire image

## Le programme

Un programme qui ne fait qu'effacer l'écran à chaque image (fichier
`mesure-pire-image.html`, JavaScript dans le navigateur, boucle
`requestAnimationFrame` synchronisée sur l'écran) :

- 60 images d'échauffement ignorées, puis **1000 images mesurées** ;
- pour chaque image, on enregistre l'intervalle depuis l'image précédente,
  avec l'horloge haute résolution `performance.now()` ;
- on relève **la plus longue image** et **le nombre d'images au-dessus de 11 ms**,
  et non la cadence moyenne.

## Les deux chiffres

| Mesure (sur 1000 images) | Valeur |
|---|---:|
| **Durée de la plus longue image** | **33,42 ms** |
| **Images dépassant 11 ms** | **1000 / 1000** (100 %) |

## Lecture des résultats

**Pourquoi 100 % des images dépassent 11 ms.** La boucle est calée sur la fréquence
de l'écran, et non sur le travail du programme. Sur un moniteur ordinaire à 60 Hz,
une image dure 1000 / 60 = 16,7 ms : elles dépassent donc toutes 11 ms, même si
effacer l'écran ne prend presque rien. Ce chiffre mesure d'abord **l'écran** : un
moniteur à 60 Hz ne peut pas tenir une échéance de 11,1 ms (90 Hz), quel que soit
le programme.

**Pourquoi la pire image vaut 33,42 ms.** C'est, à quelques centièmes près,
**deux fois** 16,7 ms. Au moins une fois sur les 1000, l'image n'était pas prête
au moment du rafraîchissement : l'écran a réaffiché l'ancienne et la nouvelle est
sortie au rendez-vous suivant. C'est exactement le cas décrit par le chapitre :
« une image sur cent qui prend le double se voit ». Ici, le programme ne fait
pourtant rien d'autre qu'effacer l'écran : ce raté vient de l'environnement
(navigateur, ramasse-miettes JavaScript, système d'exploitation, compositeur du
bureau), pas du travail demandé.

*(La fréquence de 60 Hz est déduite de la pire image, égale à deux périodes de
16,7 ms ; la médiane affichée par le programme la confirme directement.)*

## Ce programme tiendrait-il dans un casque ?

**Non.** Pour deux raisons, de natures différentes.

1. **Il est cadencé trop lentement.** À 90 Hz, l'échéance est de 11,1 ms ; ici,
   aucune image sur 1000 ne la tient. Ce point vient surtout de l'écran du test,
   et ne serait pas un défaut du programme sur un vrai casque.
2. **Il rate des rendez-vous sans raison venant de lui.** C'est le point grave.
   Une image à 33,42 ms, c'est trois périodes complètes à 90 Hz (3 × 11,1 ms) :
   dans un casque, deux images manquées d'affilée, que l'utilisateur ressent.
   Or le programme n'a presque aucun travail à faire. Si un simple effacement
   d'écran rate une échéance dans cet environnement, une vraie scène dessinée deux
   fois, dans un budget qui n'est que de 3,1 ms pour notre code à 90 Hz
   (exercice 1), la raterait bien plus souvent.

## Ce que l'exercice montre

- **La moyenne aurait menti.** Avec 999 images à 16,7 ms et une seule à 33,4 ms,
  la cadence moyenne reste à environ 60 images par seconde : on aurait conclu que
  tout va bien. Seule la pire image montre le raté.
- **Le temps d'une image n'est pas le temps de notre code.** L'intervalle mesuré
  dépend de l'écran et du système. Pour juger notre programme, il faut aussi
  mesurer le temps passé par notre code dans chaque image, et le comparer au
  budget qui lui reste (5,9, 3,1 ou 0,3 ms selon la cadence).
- **L'environnement fait partie du budget.** Un navigateur, un ramasse-miettes et
  un système non temps réel peuvent voler une image à tout moment. C'est pourquoi
  une application en casque ne peut pas tourner « comme un programme ordinaire » :
  il faut une boucle dédiée, cadencée par le runtime du casque, qu'on ne bloque
  jamais, et sans allocation imprévisible pendant l'image.
