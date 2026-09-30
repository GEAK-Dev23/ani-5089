#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <vector>

int main()
{
    std::map<std::string, std::vector<std::string>> besoins;
    std::string ligne;

    // Nombre de modules connus
    int n = 0;
    while (std::getline(std::cin, ligne)) {
        std::istringstream flux(ligne);
        if (flux >> n) {
            break;
        }
    }

    // N lignes : un module, puis ses besoins
    int lus = 0;
    while (lus < n && std::getline(std::cin, ligne)) {
        std::istringstream flux(ligne);
        std::string module;
        if (!(flux >> module)) {
            continue; // ligne vide ignoree
        }
        std::vector<std::string>& liste = besoins[module];
        std::string besoin;
        while (flux >> besoin) {
            liste.push_back(besoin);
        }
        ++lus;
    }

    // M, puis les M modules nommes directement
    int m = 0;
    std::cin >> m;

    std::set<std::string> resultat;
    std::vector<std::string> aTraiter;
    for (int i = 0; i < m; ++i) {
        std::string nom;
        if (!(std::cin >> nom)) {
            break;
        }
        if (resultat.insert(nom).second) {
            aTraiter.push_back(nom);
        }
    }

    // On ajoute les besoins des nouveaux venus jusqu'a ce que plus rien n'apparaisse
    while (!aTraiter.empty()) {
        std::string courant = aTraiter.back();
        aTraiter.pop_back();

        std::map<std::string, std::vector<std::string>>::const_iterator it = besoins.find(courant);
        if (it == besoins.end()) {
            continue; // module sans ligne : aucun besoin a lui
        }
        for (const std::string& besoin : it->second) {
            if (resultat.insert(besoin).second) {
                aTraiter.push_back(besoin);
            }
        }
    }

    // std::set est deja trie par ordre alphabetique
    for (const std::string& nom : resultat) {
        std::cout << nom << '\n';
    }

    return 0;
}
