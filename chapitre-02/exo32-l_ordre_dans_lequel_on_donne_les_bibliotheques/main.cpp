#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <vector>

int main()
{
    std::map<std::string, std::set<std::string>> besoins;
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
            continue;
        }
        std::set<std::string>& liste = besoins[module];
        std::string besoin;
        while (flux >> besoin) {
            liste.insert(besoin);
        }
        ++lus;
    }

    // M, puis les modules nommes directement
    int m = 0;
    std::cin >> m;

    // Etape 1 : la liste complete, comme a l'exercice precedent
    std::set<std::string> liste;
    std::vector<std::string> aTraiter;
    for (int i = 0; i < m; ++i) {
        std::string nom;
        if (!(std::cin >> nom)) {
            break;
        }
        if (liste.insert(nom).second) {
            aTraiter.push_back(nom);
        }
    }
    while (!aTraiter.empty()) {
        std::string courant = aTraiter.back();
        aTraiter.pop_back();
        std::map<std::string, std::set<std::string>>::const_iterator it = besoins.find(courant);
        if (it == besoins.end()) {
            continue;
        }
        for (const std::string& besoin : it->second) {
            if (liste.insert(besoin).second) {
                aTraiter.push_back(besoin);
            }
        }
    }

    // Etape 2 : pour chaque module, combien de modules de la liste ont besoin de lui
    std::map<std::string, int> compte;
    for (const std::string& nom : liste) {
        compte[nom] = 0;
    }
    for (const std::string& nom : liste) {
        std::map<std::string, std::set<std::string>>::const_iterator it = besoins.find(nom);
        if (it == besoins.end()) {
            continue;
        }
        for (const std::string& besoin : it->second) {
            ++compte[besoin];
        }
    }

    // Etape 3 : on sort les modules a zero, le premier par ordre alphabetique
    std::set<std::string> prets;
    for (const std::pair<const std::string, int>& entree : compte) {
        if (entree.second == 0) {
            prets.insert(entree.first);
        }
    }

    std::vector<std::string> ordre;
    while (!prets.empty()) {
        std::string courant = *prets.begin();
        prets.erase(prets.begin());
        ordre.push_back(courant);

        std::map<std::string, std::set<std::string>>::const_iterator it = besoins.find(courant);
        if (it == besoins.end()) {
            continue;
        }
        for (const std::string& besoin : it->second) {
            --compte[besoin];
            if (compte[besoin] == 0) {
                prets.insert(besoin);
            }
        }
    }

    // Les modules sortis s'affichent dans l'ordre de sortie
    for (const std::string& nom : ordre) {
        std::cout << nom << '\n';
    }

    // Il reste des modules mais aucun a zero : c'est un cycle, on s'arrete la
    if (ordre.size() != liste.size()) {
        std::cout << "CYCLE\n";
    }

    return 0;
}
