#include <iostream>
#include <set>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

static void retirerRetourChariot(std::string& ligne)
{
    if (!ligne.empty() && ligne[ligne.size() - 1] == '\r') {
        ligne.erase(ligne.size() - 1);
    }
}

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

int main()
{
    const std::string marqueur = "undefined reference to '";

    // P lignes : un prefixe, puis le module auquel il appartient
    std::vector<std::pair<std::string, std::string>> prefixes;
    int p = 0;
    lireEntier(p);
    int lus = 0;
    std::string ligne;
    while (lus < p && std::getline(std::cin, ligne)) {
        std::istringstream flux(ligne);
        std::string prefixe;
        std::string module;
        if (!(flux >> prefixe >> module)) {
            continue;
        }
        prefixes.push_back(std::make_pair(prefixe, module));
        ++lus;
    }

    // L, puis les lignes du message : on lit tout jusqu'au bout
    int l = 0;
    lireEntier(l);

    std::set<std::string> modules;
    int inconnus = 0;

    while (std::getline(std::cin, ligne)) {
        retirerRetourChariot(ligne);

        std::string::size_type position = ligne.find(marqueur);
        while (position != std::string::npos) {
            std::string::size_type debut = position + marqueur.size();
            std::string::size_type fin = ligne.find('\'', debut);
            std::string symbole;
            if (fin == std::string::npos) {
                symbole = ligne.substr(debut);
                fin = ligne.size();
            } else {
                symbole = ligne.substr(debut, fin - debut);
            }

            // Le prefixe le plus long qui commence le symbole
            std::string::size_type meilleureLongueur = 0;
            std::string meilleurModule;
            bool trouve = false;
            for (const std::pair<std::string, std::string>& entree : prefixes) {
                const std::string& prefixe = entree.first;
                if (prefixe.size() <= symbole.size()
                    && symbole.compare(0, prefixe.size(), prefixe) == 0
                    && (!trouve || prefixe.size() > meilleureLongueur)) {
                    meilleureLongueur = prefixe.size();
                    meilleurModule = entree.second;
                    trouve = true;
                }
            }

            if (trouve) {
                modules.insert(meilleurModule);
            } else {
                ++inconnus;
            }

            position = ligne.find(marqueur, fin);
        }
    }

    for (const std::string& module : modules) {
        std::cout << module << '\n';
    }
    if (inconnus > 0) {
        std::cout << "INCONNU " << inconnus << '\n';
    }

    return 0;
}