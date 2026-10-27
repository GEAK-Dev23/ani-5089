# Chapitre 1 — Exercice 2 : le tableau des budgets

## Méthode

Pour chacune des cinq étapes du budget « mouvement vers photon », j'ai cherché une
valeur **mesurée** (article, publication scientifique ou documentation de constructeur).
J'ai distingué trois natures de chiffres, parce qu'elles n'ont pas la même valeur :

- **Mesuré** : obtenu par un instrument ou un profileur sur un système réel ;
- **Spécifié** : donné par le constructeur (fiche technique), donc une promesse, pas une mesure ;
- **Introuvable** : je n'ai pas trouvé de source qui isole cette étape. Je le dis plutôt que d'inventer.

## Le tableau

| Étape | Valeur du cours | Valeur trouvée | Nature | Source |
|---|---|---|---|---|
| **1. Les capteurs mesurent le mouvement** | 1 à 2 ms | IMU échantillonnée à **1000 Hz**, soit un échantillon toutes les **1 ms** ; Oculus annonce environ **2 ms** entre le mouvement de la tête et la réception de la donnée par le moteur | Spécifié (constructeur) | [1], [2] |
| **2. Le système transmet la mesure** | 1 à 3 ms | Un périphérique USB HID classique à 125 Hz ajoute jusqu'à **8 ms** de gigue ; certains matériels USB atteignent 1000 mises à jour par seconde (≤ 1 ms) | Analyse d'ingénieur (pas une mesure isolée) | [3] |
| **3. L'application décide et dessine** | 5 à 11 ms | **Introuvable comme valeur mesurée générale** : cela dépend par définition de l'application. Meta donne seulement la contrainte : CPU + GPU doivent tenir dans **13,89 ms à 72 Hz** | Budget, pas une mesure | [4] |
| **4. Le compositeur assemble** | 1 à 2 ms | Noyau de *time warp* : **2,32 à 2,55 ms** en moyenne ; avec la préemption GPU (ATW asynchrone), de **2 ms à près de 16 ms** selon la charge | Mesuré, mais **en simulateur de GPU**, pas sur un casque réel | [5] |
| **5. L'écran affiche la ligne** | 2 à 5 ms | Persistance de l'Oculus Rift DK2 : **2 ms ou 3 ms** ; illumination du Valve Index : **0,33 à 0,53 ms** selon la fréquence (contre 1,85 ms sur le HTC Vive) | Spécifié (constructeur) | [6], [7], [8] |
| **Total mouvement vers photon** | ≈ 20 ms | Prototype Oculus Crystal Cove : environ **30 ms** (moitié des 60 ms précédentes). Carmack signale des systèmes courants qui dépassent **100 ms** | Annonce constructeur / analyse | [9], [3] |

## Ce que je n'ai pas trouvé, et pourquoi

1. **L'étape 3 (l'application)** n'a pas de valeur mesurée universelle : c'est
   précisément la variable que *nous* contrôlons. Les seules sources sérieuses donnent
   un budget (la durée d'une image), et les outils pour le mesurer soi-même
   (le graphe *Advanced Frame Timing* de SteamVR [10], le champ `App=` des journaux
   VrApi de Meta [11]). La valeur se mesure sur son propre programme, pas dans un article.

2. **L'étape 4 (le compositeur) sur un casque réel** : Meta et Valve exposent ce temps
   dans leurs outils (champ `TW=` des journaux VrApi [11], temps GPU du compositeur
   dans SteamVR [10]), mais je n'ai trouvé **aucun chiffre publié** par un constructeur.
   La seule mesure trouvée vient d'un simulateur académique [5].

3. **L'étape 5 au sens « balayage de la ligne »** : les constructeurs publient la
   *persistance* (combien de temps le pixel reste allumé), pas le temps de balayage
   de l'écran ni le temps de réponse des pixels. Ce n'est pas la même grandeur que
   celle du tableau du cours ; je la rends faute de mieux, en le signalant.

4. **La séparation entre les étapes 1 et 2** : le chiffre d'Oculus (≈ 2 ms) couvre
   ensemble la mesure et la transmission jusqu'au moteur. Aucune source trouvée ne
   les sépare sur un casque grand public.

## Remarques critiques sur les sources

- La plupart des chiffres datent de la période 2013–2019 (DK2, Vive, Index). Les
  casques actuels ont probablement de meilleures valeurs, mais je n'ai pas trouvé
  de décomposition étape par étape publiée pour eux.
- Les **mesures** indépendantes publiées portent presque toujours sur la latence
  **totale** (bout en bout), par exemple les méthodes à capteur photo de Seo et al. [12]
  ou au pendule de Zhao et al. sur le DK2 [13], parce qu'on ne peut pas instrumenter
  facilement l'intérieur d'un casque. Le découpage en cinq étapes est donc un
  **modèle**, que les mesures ne confirment qu'en total.
- Conséquence pour la suite du parcours : il faut prévoir de **mesurer nous-mêmes**
  la part de notre code, à chaque image, au lieu de se fier à une valeur publiée.

## Sources

1. Oculus VR, *Building a Sensor for Low Latency VR* (blog Meta) — https://www.meta.com/blog/building-a-sensor-for-low-latency-vr/
2. Fiche technique Oculus Rift DK2 (iFixit) — https://it.ifixit.com/Device/Oculus_Rift_Development_Kit_2
3. J. Carmack, *Latency Mitigation Strategies* (2013, archive) — https://danluu.com/latency-mitigation/
4. Meta, *Understanding Gameplay Latency for Oculus Quest, Oculus Go and Gear VR* — https://developer.oculus.com/blog/understanding-gameplay-latency-for-oculus-quest-oculus-go-and-gear-vr/
5. *Minimizing the Motion-to-Photon-delay (MPD) in Virtual Reality Systems* (arXiv 2301.10408) — https://arxiv.org/pdf/2301.10408
6. Spécifications Oculus Rift DK2 (Legit Reviews) — https://legitreviews.com/?p=137820
7. Valve Index, Wikipédia — https://en.wikipedia.org/wiki/Valve_Index
8. Road to VR, *Hands-on: Valve Index* — https://roadtovr.com/valve-index-hands-on-preview-valve-vr-headset/2/?amp=1
9. IEEE Spectrum, *What Facebook Gets With Oculus Rift Purchase* — https://spectrum.ieee.org/amp/what-facebook-gets-with-oculus-rift-purchase-2650270763
10. Valve Developer Wiki, *SteamVR/Frame Timing* — https://developer.Valvesoftware.com/wiki/SteamVR/Frame_Timing
11. Meta, *Accurately Measure an App's Per-Frame GPU Cost* — https://developers.meta.com/vr/documentation/unity/po-per-frame-gpu/
12. Seo et al., *Photosensor-Based Latency Measurement System for Head-Mounted Displays*, Sensors, 2017 — https://www.ncbi.nlm.nih.gov/pmc/articles/PMC5470788/
13. Zhao, Allison, Vinnikov, Jennings, *Estimating the motion-to-photon latency in head mounted displays*, 2017 — https://paper.nweon.com/9305
