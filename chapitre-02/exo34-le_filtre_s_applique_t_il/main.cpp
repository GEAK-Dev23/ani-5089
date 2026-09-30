#include <iostream>
#include <map>
#include <sstream>
#include <string>

static void retirerRetourChariot(std::string& ligne)
{
    if (!ligne.empty() && ligne[ligne.size() - 1] == '\r') {
        ligne.erase(ligne.size() - 1);
    }
}

static std::string rogner(const std::string& texte)
{
    const std::string blancs = " \t\r\n";
    std::string::size_type debut = texte.find_first_not_of(blancs);
    if (debut == std::string::npos) {
        return "";
    }
    std::string::size_type fin = texte.find_last_not_of(blancs);
    return texte.substr(debut, fin - debut + 1);
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

static bool termeVrai(const std::map<std::string, std::string>& machine, const std::string& terme)
{
    std::string::size_type egal = terme.find('=');
    if (egal == std::string::npos) {
        return false;
    }
    std::string cle = rogner(terme.substr(0, egal));
    std::string valeur = rogner(terme.substr(egal + 1));

    std::map<std::string, std::string>::const_iterator it = machine.find(cle);
    if (it == machine.end()) {
        return false;
    }
    return it->second == valeur;
}

static bool filtreApplique(const std::map<std::string, std::string>& machine, std::string condition)
{
    // Les && deviennent des espaces : il ne reste que des termes
    std::string::size_type position = condition.find("&&");
    while (position != std::string::npos) {
        condition.replace(position, 2, " ");
        position = condition.find("&&", position);
    }

    std::istringstream flux(condition);
    std::string morceau;
    bool negation = false;
    while (flux >> morceau) {
        // Chaque ! colle au terme qui le suit, meme s'il est separe par une espace
        std::string::size_type i = 0;
        while (i < morceau.size() && morceau[i] == '!') {
            negation = !negation;
            ++i;
        }
        if (i == morceau.size()) {
            continue;
        }

        bool vrai = termeVrai(machine, morceau.substr(i));
        if (negation) {
            vrai = !vrai;
        }
        negation = false;

        if (!vrai) {
            return false;
        }
    }
    return true;
}

int main()
{
    // V lignes cle=valeur : l'etat de la machine
    std::map<std::string, std::string> machine;
    int v = 0;
    lireEntier(v);
    int lus = 0;
    std::string ligne;
    while (lus < v && std::getline(std::cin, ligne)) {
        retirerRetourChariot(ligne);
        if (rogner(ligne).empty()) {
            continue;
        }
        std::string::size_type egal = ligne.find('=');
        if (egal != std::string::npos) {
            machine[rogner(ligne.substr(0, egal))] = rogner(ligne.substr(egal + 1));
        }
        ++lus;
    }

    // F lignes : une condition par ligne, une reponse par ligne
    int f = 0;
    lireEntier(f);
    for (int i = 0; i < f; ++i) {
        if (!std::getline(std::cin, ligne)) {
            break;
        }
        retirerRetourChariot(ligne);
        std::cout << (filtreApplique(machine, ligne) ? "OUI" : "NON") << '\n';
    }

    return 0;
}
