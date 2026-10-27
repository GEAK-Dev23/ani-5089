# Chapitre 1 — Exercice 8 : le champ de vision asymétrique

## Le casque : Meta Quest 3, œil gauche

Le runtime d'un casque ne donne pas un angle et un rapport de forme, mais quatre
valeurs par œil : les **tangentes** des quatre bords du champ de vision, mesurées
depuis l'axe de l'œil (convention : gauche et bas négatifs, droite et haut positifs).
L'angle s'obtient par l'arc tangente.

Valeurs relevées sur un Meta Quest 3 (runtime Oculus 1.89, outil `hmdq` 2.1.7,
octobre 2023), œil gauche :

| Bord | Tangente (valeur brute du runtime) | Angle = arctan |
|---|---:|---:|
| **Gauche** (vers l'extérieur, côté tempe) | − 1,376382 | **− 54,0°** |
| **Droite** (vers l'intérieur, côté nez) | + 0,839100 | **+ 40,0°** |
| **Haut** | + 0,965689 | **+ 44,0°** |
| **Bas** | − 1,428148 | **− 55,0°** |

Champ de l'œil gauche : 54 + 40 = **94° horizontalement**, 44 + 55 = **99° verticalement**.

L'œil droit est le miroir de l'œil gauche : − 40° à gauche (côté nez), + 54° à droite
(côté tempe), mêmes valeurs en haut et en bas.

*Remarque sur la source :* la page de la base de données affiche − 54,27° pour le bas
(et 98,25° de champ vertical), alors que l'arc tangente de la valeur brute donne
− 55,0°. J'ai retenu le calcul fait à partir de la valeur brute, que j'ai vérifié
moi-même ; l'écart vient probablement de la manière dont l'outil calcule son angle
d'affichage, que la page n'explique pas.

## Ce que montrent ces quatre angles

- **Horizontalement**, l'œil voit beaucoup plus loin vers l'extérieur (54°) que vers
  le nez (40°) : la lentille n'est pas centrée sur l'œil, et le nez limite la vue
  vers l'intérieur.
- **Verticalement**, il voit plus vers le bas (55°) que vers le haut (44°).
- Le centre de l'écran ne correspond donc pas à « droit devant » : en coordonnées
  de projection, il est décalé de (− 1,376 + 0,839) / 2 = − 0,269 horizontalement,
  soit environ **15° vers l'extérieur**, et de (0,966 − 1,428) / 2 = − 0,231
  verticalement, soit environ **13° vers le bas**.

C'est pour cela que la fonction de perspective habituelle, qui prend un seul angle
et un rapport de forme et construit toujours un champ centré, ne convient pas.

## Et avec un champ symétrique de même surface ?

Un champ symétrique de même surface garde les mêmes étendues (2,215 en largeur et
2,394 en hauteur, en tangentes), mais centrées : environ ± 47,9° horizontalement et
± 50,1° verticalement.

**En une phrase :** l'image serait centrée sur l'axe de l'œil alors que la lentille
la montre décalée de 15° vers l'extérieur et 13° vers le bas, si bien que chaque
objet apparaîtrait au mauvais endroit, différemment pour les deux yeux, et
l'utilisateur verrait des images doublées ou un relief faux, avec fatigue et malaise,
sans qu'aucune erreur ne s'affiche.

Pour aller plus loin que la phrase : on dessinerait 8° de trop du côté du nez (jusqu'à
48° au lieu de 40°, des pixels calculés pour rien) et on perdrait 6° du côté de la
tempe (48° au lieu de 54°), là où la vision périphérique est la plus sensible au
mouvement. C'est l'exemple du chapitre : une projection symétrique donne une image
légèrement fausse, surtout sur les bords, et c'est une faute qui ne plante pas.

## Sources

- Base de données de géométrie des casques (hmdgdb), fiche **Meta Quest 3 (72 Hz)** —
  https://risa2000.github.io/hmdgdb/hmd_cfgs/MetaQuest3_Native_R72.html
- Explication du calcul du champ de vision à partir des valeurs du runtime —
  https://risa2000.github.io/vrdocs/docs/hmd_fov_calculation.html
- Tutoriel Vulkan / OpenXR, *Asymmetric Frustums for Canted Displays* (les quatre
  tangentes par œil et le centre optique décalé) —
  https://docs.vulkan.org/tutorial/latest/OpenXR_Vulkan_Spatial_Computing/11_Canted_Displays/02_non_parallel_projections.html
