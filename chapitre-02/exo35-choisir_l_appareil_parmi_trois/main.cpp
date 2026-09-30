#include <iostream>
#include <set>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

static bool lireEntier(int& valeur)
{
    std::string ligne;
    while (std::getline(std::cin, ligne)) {
        std::istringstream flux(ligne);
        if (flux >> valeur) {
            return true;
        }
    }
    return false;
}

static bool lirePremierMot(std::string& mot)
{
    std::string ligne;
    while (std::getline(std::cin, ligne)) {
        std::istringstream flux(ligne);
        if (flux >> mot) {
            return true;
        }
    }
    return false;
}

int main()
{
    // D lignes : serie, etat, modele
    std::vector<std::pair<std::string, std::string>> appareils;
    int d = 0;
    lireEntier(d);
    int lus = 0;
    std::string ligne;
    while (lus < d && std::getline(std::cin, ligne)) {
        std::istringstream flux(ligne);
        std::string serie;
        std::string etat;
        if (!(flux >> serie)) {
            continue;
        }
        flux >> etat;
        appareils.push_back(std::make_pair(serie, etat));
        ++lus;
    }

    // Derniere ligne : la cible demandee, ou - si aucune
    std::string cible;
    if (!lirePremierMot(cible)) {
        cible = "-";
    }

    if (cible != "-") {
        for (const std::pair<std::string, std::string>& appareil : appareils) {
            if (appareil.first == cible) {
                if (appareil.second == "device") {
                    std::cout << appareil.first << '\n';
                } else {
                    std::cout << "ERREUR " << appareil.first << " est " << appareil.second << '\n';
                }
                return 0;
            }
        }
        std::cout << "ERREUR cible introuvable\n";
        return 0;
    }

    // Aucune cible : on ne garde que les appareils en etat device
    std::set<std::string> prets;
    for (const std::pair<std::string, std::string>& appareil : appareils) {
        if (appareil.second == "device") {
            prets.insert(appareil.first);
        }
    }

    if (prets.empty()) {
        std::cout << "ERREUR aucun appareil\n";
    } else if (prets.size() == 1) {
        std::cout << *prets.begin() << '\n';
    } else {
        std::cout << "ERREUR plusieurs appareils\n";
        for (const std::string& serie : prets) {
            std::cout << serie << '\n';
        }
    }

    return 0;
}
